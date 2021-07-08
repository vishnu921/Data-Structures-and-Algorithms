/*
Given a gold mine called M of (n x m) dimensions. Each field in this mine contains a positive integer 
which is the amount of gold in tons. Initially the miner can start from any row in the first column.
From a given cell, the miner can move

    to the cell diagonally up towards the right 
    to the right
    to the cell diagonally down towards the right

Find out maximum amount of gold which he can collect.
*/

#include <bits/stdc++.h>
using namespace std;
#define vvi vector<vector<int>>
#define vi vector<int>

//top down approach
int solve(vvi &grid, int n, int m, int r, int c, vvi& dp){
	if(r < 0 || c < 0 || r >= n || c >= m) return 0;

	if(dp[r][c] != INT_MIN) return dp[r][c];

	int right = solve(grid, n, m, r, c+1, dp);
	int right_up = solve(grid, n, m, r-1, c+1, dp);
	int right_down = solve(grid, n, m, r+1, c+1, dp);

	dp[r][c] = grid[r][c] + max(right, max(right_up, right_down));

	return dp[r][c];
}
int maxGold_topDown(vvi& grid, int n, int m){
	vvi dp(n, vi(m, INT_MIN));
	int ans = INT_MIN;

	//we start from every cell in the first column
	for(int i = 0; i < n; i++){
		ans = max(ans, solve(grid, n, m, i, 0, dp));
	}

	return ans;
}

//bottom up (tabulation)
int maxGold_bottomUp(vvi& grid, int n, int m){
	vvi dp(n, vi(m, 0));

	for(int c = m-1; c >= 0; c--){
		for(int r = 0; r < n; r++){

			int right = (c == m-1)? 0 : dp[r][c+1];

			int right_up = (r == 0 || c == m-1)? 0 : dp[r-1][c+1];

			int right_down = (r == n-1 || c == m-1)? 0 : dp[r+1][c+1];

			dp[r][c] = grid[r][c] + max(right, max(right_up, right_down));
		}
	}

	int mx = dp[0][0];
	for(int i = 1; i < n; i++){
		mx = max(mx, dp[i][0]);
	}

	return mx;
}

int main(){
	int n, m;
	cin >> n >> m;
	vvi grid(n, vi(m, 0));

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> grid[i][j];
		}
	}
	cout << maxGold_topDown(grid, n, m) << "\n";
	cout << maxGold_bottomUp(grid, n, m) << "\n";
	return 0;
}