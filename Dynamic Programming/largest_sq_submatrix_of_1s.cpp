/*
Given a binary matrix mat of size n * m, find out the maximum size square sub-matrix with all 1s.
*/

#include <bits/stdc++.h>
using namespace std;
#define vvi vector<vector<int>>
#define vi vector<int>

int largest_sqMatrix(vvi &mat, int n, int m){
	//dp[i][j] stores largest square submatrix of all 1s where
	//mat[i][j] is the bottom right corner of that submatrix
	vvi dp(n, vi(m,0));

	//result is the max value in dp matrix
	int res = 0;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			//copy 1st row and 1st column of mat[][] in dp[][] as it is
			if(i == 0 || j == 0){
				dp[i][j] = mat[i][j];
			}
			//else if mat[i][j] == 1
			//we take minimum of dp[i-1][j-1], dp[i-1][j] and dp[i][j-1] and add it it
			else if(mat[i][j] == 1){
				dp[i][j] = min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j])) + 1;
			}

			if(res < dp[i][j]){
				res = dp[i][j];
			}
		}
	}

	return res;
}

int main(){
	int n, m;
	cin >> n >> m;
	vvi mat(n, vi(m));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> mat[i][j];
		}
	}
	cout << largest_sqMatrix(mat, n, m) << "\n";
	return 0;
}