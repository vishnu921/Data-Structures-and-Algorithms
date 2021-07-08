/*
Permutation refers to the process of arranging all the members of a given set to form a sequence. The number 
of permutations on a set of n elements is given by n! , where “!” represents factorial. 

//it has optimal substructure and overlapping subproblems properties
P(n, k) = P(n-1, k) + k* P(n-1, k-1)   
*/
#include <bits/stdc++.h>
using namespace std;

//tabulation
int nPk_dp(int n, int k){
	//dp[n][k] stores nPk
	int dp[n+1][k+1];

	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= min(i, k); j++){
			//base case
			if(j == 0) dp[i][j] = 1;

			else dp[i][j] = dp[i-1][j] + (j*dp[i-1][j-1]);

			//dp[i][j] = 0 for j > i;
			dp[i][j+1] = 0;
		}
	}

	return dp[n][k];
}

//we know that P(n,k) = n*(n-1)*(n-2)*......*(n-k+1)
int nPk_eff(int n, int k){
	if(k > n) return 0;
	int res = 1;

	for(int i = 0; i < k; i++){
		res *= (n-i);
	}

	return res;
}

int main(){
	int n, k;
	cin >> n >> k;
	cout << nPk_dp(n, k) << "\n";
	cout << nPk_eff(n, k) << "\n"; 
	return 0;
}