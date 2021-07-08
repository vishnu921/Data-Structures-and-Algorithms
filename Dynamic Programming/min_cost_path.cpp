/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes 
the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
*/
#include <bits/stdc++.h>
using namespace std;
#define vvi vector<vector<int>>
#define vi vector<int> 

int minCostPathSum(vvi &grid, int m, int n){
	//dp[i][j] stores minimum cost path from grid[0][0] to grid[i][j]
	int dp[m][n];

	//base cases
	dp[0][0] = grid[0][0];

	for(int i = 1; i < m; i++){
		dp[i][0] = dp[i-1][0] + grid[i][0];
	}

	for(int j = 1; j < n; j++){
		dp[0][j] = dp[0][j-1] + grid[0][j];
	}

	for(int i = 1; i < m; i++){
		for(int j = 1; j < n; j++){
			dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
		}
	}

	return dp[m-1][n-1];
}

int main(){
	int m,n;
	cin >> m >> n;
	vvi grid(m, vi(n));
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			cin >> grid[i][j];
		}
	}

	cout << minCostPathSum(grid, m, n) << "\n";
	return 0;
}