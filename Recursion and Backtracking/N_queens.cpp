/*
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both 
indicate a queen and an empty space, respectively.
*/
#include <bits/stdc++.h>
using namespace std; 

//function to check if queen can be placed at board[row][col]
bool issafe(vector<string> &board, int r, int c){
	//check for current column
	int n = board.size();
	for(int i = 0; i < r; i++){
		if(board[i][c] == 'Q') return false;
	}

	//check for diagonal on left side
	for(int i = r,j = c; i >= 0 && j >= 0; i--, j--){
		if(board[i][j] == 'Q') return false;
	}

	//check for diagonal on right side
	for(int i = r, j = c; i >= 0 && j < n; i--, j++){
		if(board[i][j] == 'Q') return false;
 	}

 	return true;
}

void NQueens(vector<string> &board, int row, vector<vector<string>> &res){
	int n = board.size();
	//base case: if all queens are placed then push the board into result
	if(row == n){
		res.push_back(board);
		return;
	}

	//consider current row and try placing queen in all columns of this row one by one
	for(int col = 0; col < n; col++){
		//check if queen can be placed at board[row][col];
		if(issafe(board, row, col)){
			//place the queen at board[row][col]
			board[row][col] = 'Q';

			//recur for next row 
			NQueens(board, row+1, res);

			//after processing by placing queen at board[row][col]
			//remove queen from its position
			board[row][col] = '.';
		}
	}
}

vector<vector<string>> solveNqueens(int n){
	vector<vector<string>> res;
	vector<string> board(n, string(n,'.'));

	NQueens(board, 0, res);
	return res;
}

int main(){
	int n;
	cin >> n;
	vector<vector<string>> res;
	res = solveNqueens(n);
	if(res.size() == 0){
		cout << "NO solution\n";
		return 0;
	}
	for(int i = 0; i < res.size(); i++){
		cout << "-------------\n";
		for(int j = 0; j < n; j++){
			cout << res[i][j] << "\n";
		}
	}
	return 0;
}