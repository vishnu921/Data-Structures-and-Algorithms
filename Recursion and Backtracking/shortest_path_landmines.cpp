#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vector<int>>
int row[4] = {-1, 0, 0, 1};
int col[4] = {0, -1, 1, 0};

//function to check if it safe to visit the mat[r][c] or its already visited
bool issafe(vvi &mat,vvi &visited, int r, int c){
	if(mat[r][c] == 0 || visited[r][c]) return false;
	return true;
}

//are coordinates valid within the matrix
bool isvalid(int r,int c, int m, int n){
	return (r < m && c < n && r >= 0 && c >= 0);
}

//make all cells adjacent to landmines(left,right,up,down) = 0
void markunsafecells(vvi &mat, int m, int n){
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			if(mat[i][j] == 0){
				for(int k = 0; k < 4; k++){
					if(isvalid(i+row[k], j+col[k], m, n))
						mat[i+row[k]][j+col[k]] = -1;
				}
			}
		}
	}

	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			if(mat[i][j] == -1) mat[i][j] = 0;
		}
	}
}

//function to calculate shortest path
//mat = input matrix with safe cells marked as 1
//visited = matrix with visited cell marked as 1
//m = no. of rows, n = no. of columns
//r = current row, c = current coloumn
//min_path = shortest path length(passed by reference)
//cur = current path length
void solve(vvi &mat, vvi &visited, int m, int n, int r, int c, int &min_path, int cur){
	//if we reach last column update min_path and return
	if(c == n-1){
		min_path = min(min_path, cur);
		return;
	}

	//if current path is greater than min_path so far, there is no need to go on this path
	if(cur > min_path) return;

	//mark current cell as visited
	visited[r][c] = 1;

	for(int i = 0; i < 4; i++){
		//recur for all safe adjecent neighbours
		if(isvalid(r+row[i], c+col[i], m, n) && issafe(mat, visited, r+row[i], c+col[i])){
			solve(mat, visited, m, n, r+row[i], c+col[i], min_path, cur+1);
		}
	}
	//backtracking
	visited[r][c] = 0;
}

int shortestPath(vvi &mat, int m, int n){
	//matrix to mark visited cells
	vvi visited(m, vi(n, 0));
	int min_path = INT_MAX;
	markunsafecells(mat, m, n);

	//start from each cell in the first column one by one
	for(int i = 0; i < m; i++){
		if(mat[i][0] == 1){
			//update all cells in visited to 0
			for(int k = 0; k < m; k++){
				for(int j = 0; j < n; j++)
					visited[k][j] = 0;
			}
			solve(mat, visited, m, n, i, 0, min_path, 0);

			//the least value of shortest path = length of row - 1
			//if it is achieved there is no need to check further paths
			if(min_path == n-1) break;
		}
	}

	//if there is no path found return -1
	if(min_path == INT_MAX) return -1;

	return min_path;
}

int main(){
	int m, n;
	cin >> m >> n;
	vvi matrix(m, vi(n));
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			cin >> matrix[i][j];
		}
	}
	cout << shortestPath(matrix, m, n) << "\n";
	return 0;
}