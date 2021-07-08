/*
Given two strings s and t of lengths m and n respectively, find the length of the smallest string which has both, 
s and t as its sub-sequences.
*/

#include <bits/stdc++.h>
using namespace std;

int shortest_common_supersequence(string s, string t, int m, int n){
	int dp[m+1][n+1];

	for(int i = 0; i <= m; i++){
		for(int j = 0; j <= n; j++){
			if(i == 0 || j == 0){
				dp[i][j] = 0;
			}
			else if(s[i-1] == t[j-1]){
				dp[i][j] = 1 + dp[i-1][j-1];
			}
			else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
    
    int lcs = dp[m][n];
    
    //since lcs is present in both strings therefore to get the length of shortest common supersequence
    //we count length of lcs only once in the supersequence of s and t
    return n+m-lcs;
}

int main(){
	string s, t;
	cin >> s >> t;
	int m = s.length();
	int n = t.length();

	cout << shortest_common_supersequence(s, t, m, n) << "\n";
	return 0;
}