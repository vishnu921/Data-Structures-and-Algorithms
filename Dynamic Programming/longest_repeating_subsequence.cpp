/*
Given a string, find the length of the longest repeating subsequence such that the two subsequences don't have 
same string character at the same position, i.e., any i'th character in the two subsequences shouldn't have the 
same index in the original string.
*/ 

#include <bits/stdc++.h>
using namespace std;

//recursion + memoisation
int dp[1001][1001];
int lrs_topDown(string &s, int m, int n){
	if(m == 0 || n == 0) return 0;

	if(dp[m][n] != -1) return dp[m][n];

	if(s[m-1] == s[n-1] && m != n){
		dp[m][n] = 1 + lrs_topDown(s, m-1, n-1);
	}
	else{
		dp[m][n] = max(lrs_topDown(s, m, n-1), lrs_topDown(s, m-1, n));
	}

	return dp[m][n];
}

//bottom Up
int lrs_bottomUP(string s, int n){
	//dp[i][j] stores lcs of string s[0..(i-1)] and s[0...(j-1)] where every character in lcs
	//have different indexes in both strings
	int dp[n+1][n+1];

	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= n; j++){
			if(i == 0 || j == 0) dp[i][j] = 0;
			else if(s[i-1] == s[j-1] && i != j){
				dp[i][j] = 1 + dp[i-1][j-1];
			}
			else{
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}

	return dp[n][n];
}

int main(){
	string s;
	cin >> s;
	int n = s.length();
	memset(dp, -1, sizeof(dp));
	cout << lrs_topDown(s, n, n) << "\n";
	cout << lrs_bottomUP(s, n) << "\n";
	return 0;
}