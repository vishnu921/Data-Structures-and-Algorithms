/*
Given a grid consisting of '0's(Water) and '1's(Land). Find the number of islands.
Note: An island is surrounded by water and is formed by connecting adjacent lands 
horizontally or vertically or diagonally i.e., in all 8 directions.
*/


#include <bits/stdc++.h>
using namespace std;
#define vvi vector<vector<int>>
#define vi vector<int>
int x[] = {-1, 0, 1, 1, 1, 0, 0, -1, -1};
int y[] = {1, 1, 1, 0, -1, -1, -1, 0};

void dfs(vvi &grid, int n, int m, int i, int j){
	if(i >= n || j >= m || i < 0 || j < 0 || grid[i][j] == 0){
		return;
	}

	grid[i][j] = 0;

	for(int k = 0; k < 8; k++){
		int r = i + x[k];
		int c = j + y[k];
		dfs(grid, n, m, r, c);
	}
}

int numberOfIslands(vvi &grid, int n, int m){
	int ans = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			//if grid[i][j] == 1 we make a dfs call for 
			//this cell. This call will mark every node connected
			//to it visited i.e. it will mark the entire island
			//containing this node visited
			if(grid[i][j] == 1){
				dfs(grid, n, m, i, j);
				ans++;
			}
		}
	}

	return ans;
}

int main(){
	int n, m;
	cin >> n >> m;
	vvi grid(n, vi(m));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> grid[i][j];
		}
	}

	cout << numberOfIslands(grid, n, m) << "\n";
	return 0;
}