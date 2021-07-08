/*
Given a sequence of matrices, find the most efficient way to multiply these matrices together. The efficient 
way is the one that involves the least number of multiplications.

The dimensions of the matrices are given in an array a[] of size N (such that N = number of matrices + 1) where 
the ith matrix has the dimensions (a[i-1] x a[i]).
*/

#include <bits/stdc++.h>
using namespace std;

//top down
int dp[101][101];
int mcm_topDown(int a[], int i, int j){
	//base case: if there is only one matrix
	if(i == j) return 0;

	//if the subproblem is solved previously
	if(dp[i][j] != -1) return dp[i][j];

	dp[i][j] = INT_MAX;

	/*
	place the parantheses/cut at different places between M[i] to M[j]
	calculate the COM and return minimum amoungst them
	Example: possible cuts for  	M1 * M2 * M3 * M4
							_______________|____________________
						   |               |                    |
					(M1)(M2*M3*M4)     (M1*M2)(M3*M4)         (M1*M2*M3)(M4)


	dimensions of M[i] = a[i-1]*a[i]

	*/
	for(int k = i; k < j; k++){
		dp[i][j] = min(dp[i][j], mcm_topDown(a, i, k) + mcm_topDown(a, k+1, j) + a[i-1]*a[k]*a[j]);
	}

	return dp[i][j];
}

//bottom up
int mcm_bottomUp(int a[], int n){
	//dp[i][j] stores minimum COM to mulitply M[i], M[i+1], ..... M[j]
	int dp[n][n];

	for(int i = 1; i < n; i++){
		dp[i][i] = 0;
	}

	//L is the chain length varied from 2 to n-1
	for(int L = 2; L < n; L++){
		for(int i = 1; i < n-L+1; i++){
			int j = i+L-1;
			//setting max possible value first
			dp[i][j] = INT_MAX;
			for(int k = i; k < j; k++){
				int cur = dp[i][k] + dp[k+1][j] + a[i-1]*a[k]*a[j];

				if(cur < dp[i][j]){
					dp[i][j] = cur;
				}
			}
		}
	}

	return dp[1][n-1];
}


int main(){
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	
	//top down function is defined as
	//return the min. Cost of Mulitiplication of M[i],M[i+1],.....M[j]
	//number of matrices in array of length n = n-1
	memset(dp, -1, sizeof(dp));
	cout << mcm_topDown(a, 1, n-1) << "\n";
	cout << mcm_bottomUp(a, n) << "\n";
	return 0;
}