/*
Given a NxN matrix of positive integers. There are only three possible moves from a cell Matrix[r][c].

    Matrix [r+1] [c]
    Matrix [r+1] [c-1]
    Matrix [r+1] [c+1]

Starting from any column in row 0 return the largest sum of any of the paths up to row N-1.
*/

#include <bits/stdc++.h>
using namespace std;
#define vvi vector<vector<int>>
#define vi vector<int>

int max_path_sum_matrix(vvi &mat, int n){
	//dp[i][j] stores max path sum to reach mat[i][j] from an elment in first row
	int dp[n][n] = {};

	int res = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
        	//Base case: first row is starting point
            if(i == 0){
                dp[i][j] = mat[i][j];
            }
            else{
            	//we take maximum from each direction up, up_left and up_right
                int up = dp[i-1][j];
                int up_left = (j == 0) ? 0 : dp[i-1][j-1];
                int up_right = (j == n-1) ? 0 : dp[i-1][j+1];
                
                dp[i][j] = mat[i][j] + max(up, max(up_left, up_right));
            }
            
            if(dp[i][j] > res){
                res = dp[i][j];
            }
        }
    }
        
        return res;
}
int main(){
	int n;
	cin >> n;
	vvi mat(n, vi(n));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> mat[i][j];
		}
	}

	cout << max_path_sum_matrix(mat, n) << "\n";
	return 0;
}