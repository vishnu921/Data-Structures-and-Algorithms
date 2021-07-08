/*
Given two integers n and r, find nCr. Since the answer may be very large, calculate the answer modulo 109+7.
*/

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

/*
we know that nCr = (n-1)C(r-1) + (n-1)Cr
*/

//top down(Memoisation) approach
int dp[1001][801] = {};
int nCr_topDown(int n, int r){
	//base cases
	if(r > n) return 0;
	if(r == 0 || r == n) return 1;

	//using previously calculated solutions
	if(dp[n][r] != 0) return dp[n][r];

	//memoisation
	dp[n][r] = (nCr_topDown(n-1, r-1)%mod + nCr_topDown(n-1, r)%mod)%mod;

	return dp[n][r];
}

//Bottom up (tabulation) approach
int nCr_bottomUp(int n, int r){
	int dp[n+1][r+1];

	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= min(i,r); j++){
			//fill the base cases
			if(j == 0 || j == i){
				dp[i][j] = 1;
			}
			//calculate values by using previously calculated values
			else{
				dp[i][j] = (dp[i-1][j-1]%mod + dp[i-1][j]%mod)%mod;
			}
		}
	}

	return dp[n][r];
}

int nCr_efficient(int n, int r)
{
    int res = 1;
 
    // Since C(n, k) = C(n, n-k)
    if (r > n - r)
        r = n - r;
 
    // Calculate value of
    // [n * (n-1) *---* (n-k+1)] / [k * (k-1) *----* 1]
    for (int i = 0; i < r; ++i) {
        res *= (n-i);
        res /= (i + 1);
    }
 
    return res;
}

int main(){
	int n, r;
	cin >> n >> r;
	cout << nCr_topDown(n, r) << "\n";
	cout << nCr_bottomUp(n, r) << "\n";
	cout << nCr_efficient(n, r) << "\n";
	return 0;
}