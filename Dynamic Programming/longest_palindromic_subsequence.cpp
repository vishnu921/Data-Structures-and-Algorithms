/*
Given a string s, find the longest palindromic subsequence's length in s.

A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without 
changing the order of the remaining elements.
*/

#include <bits/stdc++.h>
using namespace std;

//top down (recursion + memoisation)
int dp[1001][1001];
int lps_topDown(string s, int l, int r){
	//base case: if there is only one character in the string
	if(l == r) return 1;
	//if string is empty
	if(l > r) return 0;

	if(dp[l][r] != -1) return dp[l][r];

	/*
	let s = c1r1c2
	if(c1 == c2)
		lps(s) = 2 + lps(r1)
	else 
		lps(s) = max(lps(r1c2), lps(c1r1)) 
	*/
	if(s[l] == s[r]){
		dp[l][r] = 2 + lps_topDown(s, l+1, r-1);
	}
	else dp[l][r] = max(lps_topDown(s, l+1, r), lps_topDown(s, l, r-1));

	return dp[l][r];
}

//bottom UP
int lps_bottomUp(string s, int n){
	//dp[i][j] stores longest palindromic subsequence in string s[i....j]
	int dp[n][n] = {};        //initialization to 0 is important


	//fill dp matrix in bottom up manner
	for(int i = n-1; i >= 0; i--){
		dp[i][i] = 1;
		for(int j = i+1; j < n; j++){
			if(s[i] == s[j]){
				dp[i][j] = 2 + dp[i+1][j-1];
			}
			else{
				dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
			}
		}
	}

	return dp[0][n-1];
}

int main(){
	string s;
	cin >> s;
	int n = s.length();
	memset(dp, -1, sizeof(dp));
	cout << lps_topDown(s, 0, n-1) << "\n";
	cout << lps_bottomUp(s, n) << "\n";
	return 0;
}