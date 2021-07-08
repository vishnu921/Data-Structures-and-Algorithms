/*
Given two strings text1 and text2, return the length of their longest common subsequence. If there is no 
common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none)
deleted without changing the relative order of the remaining characters.

    For example, "ace" is a subsequence of "abcde".

A common subsequence of two strings is a subsequence that is common to both strings.
*/
#include <bits/stdc++.h>
using namespace std;

//top down (recursion + memoisation)
int dp[1001][1001] = {};
int lcs_topDown(int n, int m, string s1, string s2){
	//base case: if any of the string is empty then lcs = 0
	if(n == 0 || m == 0)
		return 0;

	//using memoised solutions
	if(dp[n][m] != 0) return dp[n][m];

	//if current chars of both strings are same
	//then add it to the current lcs and recur for remaining strings
	if(s1[n-1] == s2[m-1]){
		dp[n][m] = 1 + lcs_topDown(n-1, m-1, s1, s2);
	}
	//else lcs will be max(lcs(s1[0..n-1], s2), lcs(s1, s2[0...m-1]))
	else{
		dp[n][m] = max(lcs_topDown(n-1, m, s1, s2), lcs_topDown(n, m-1, s1, s2));
	}

	return dp[n][m];
}

//bottom up
int lcs_bottomUp(int n, int m, string s1, string s2){
	//dp[i][j] stores longest common subsequence between
	//s1 of length i and s2 of length j
	int dp[n+1][m+1] = {};

	//fill dp[][] in bottom up manner
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= m; j++){
			//base cases
			if(i == 0 || j == 0) dp[i][j] = 0;
			else{
				if(s1[i-1] == s2[j-1]){
					dp[i][j] = 1 + dp[i-1][j-1];
				}
				else{
					dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
				}
			}
		}
	}

	return dp[n][m];
}

int main(){
	string s1, s2;
	cin >> s1 >> s2;
	int n = s1.length();
	int m = s2.length();

	cout << lcs_topDown(n, m, s1, s2) << "\n";
	cout << lcs_bottomUp(n, m, s1, s2) << "\n";
	return 0;
}