/*
Given an incomplete Sudoku configuration in terms of a 9 x 9  2-D square matrix (grid[][]), the task to 
find a solved Sudoku. For simplicity, you may assume that there will be only one unique solution.
*/
#include <bits/stdc++.h>
using namespace std;
#define N 9

bool issafe(int grid[N][N], int r, int c, int num){
	//check for current row and column
	for(int i = 0; i < N; i++){
		if(grid[i][c] == num) return false;
		if(grid[r][i] == num) return false;
	}

	//check for its 3*3 matrix
	int srow = r-r%3;
	int scol = c-c%3;

	for(int i = srow; i < srow+3; i++){
		for(int j = scol; j < scol+3; j++){
			if(grid[i][j] == num) return false;
		}
	}
	return true;
}

bool solveSudoku(int grid[N][N], int row, int col){
	int n = N;
	//base case if whole grid is filled return true
	if(row == n-1 && col == n) return true;
	//if current row is filled move to next row
	if(col == n){
		row++;
		col = 0;
	}
	//if there is already a number at grid[row][col] recur for next cell
	if(grid[row][col] > 0){
		return solveSudoku(grid, row, col+1);
	}

	for(int num = 1; num <= 9; num++){
		//if it is safe to put num at grid[row][col]
		if(issafe(grid, row, col, num)){
			grid[row][col] = num;
			//recur for next cell
			if(solveSudoku(grid, row, col+1)){
				return true;
			}

			//if setting num at grid[row][col] didn't give any solution set this value back at 0
			grid[row][col] = 0;
		}
	}
	return false;
}

void printGrid(int grid[N][N]){
	cout << "------------------\n";
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cout << grid[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "-----------------\n";
}

int main(){
	int grid[N][N];
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> grid[i][j];
		}
	}

	if(solveSudoku(grid, 0, 0)){
		printGrid(grid);
	}
	else cout << "NO POSSIBLE SOLUTIONS\n";
	return 0;
}