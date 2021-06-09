/*
Given a N*N board with the Knight placed on the first block of an empty board. Moving according to the rules 
of chess knight must visit each square exactly once. Print the order of each the cell in which they are visited
*/
#include <bits/stdc++.h>
using namespace std;

void displayBoard(vector<vector<int>> &board, int n){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << " " << setw(2) << board[i][j] << " ";
		}
		cout << "\n";
	}
}

//function to check if current cell is inside matrix and unvisited
bool check(vector<vector<int>> &board, int n, int r, int c){
	if(r >= 0 && c >= 0 && r < n && c < n && board[r][c] == -1){
		return true;
	}
	return false;
}

//board: output matrix with each cell marked with its move number
//n = size of matrix
//r = current row, c = current column
//move = current moves
//x, y array of possible next moves for the knight
bool solveKnightTour(vector<vector<int>> &board, int n, int r, int c, int move, int x[], int y[]){

	//if all cell are filled move = n*n display board
	if(move == n*n){
		board[r][c] = move;
		displayBoard(board, n);
		//board[r][c] = -1;
		return true;;
	}

	//mark the current cell with its move number
	board[r][c] = move;
	int nrow, ncol;
	//recur for all possible moves the knight can make
	for(int i = 0; i < 8; i++){
		nrow = r+x[i];
		ncol = c+y[i];
		if(check(board, n, nrow, ncol)){
			//board[nrow][ncol] = move;
			if(solveKnightTour(board, n, nrow, ncol, move+1, x, y)){
				return true;
			}
			board[nrow][ncol] = -1;
		}
	}
	return false;

}

void knightTour(int n, int r, int c){
	vector<vector<int>> board(n, vector<int>(n, -1));
	int x[8] = {2, 1, -1, -2, -2, -1, 1, 2};
	int y[8] = {1, 2, 2, 1, -1, -2, -2, -1};
	//board[r][c] = 0;
	if(!solveKnightTour(board, n, r, c, 1, x, y)){
		cout << "No Possible solution exists\n";
	}
}

int main(){
	int n;
	cin >> n;
	int r,c;
	cin >> r >> c;

	knightTour(n, r, c);
	return 0;
}