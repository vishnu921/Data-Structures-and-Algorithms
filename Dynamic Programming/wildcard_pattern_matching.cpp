/*
Given two strings 'str' and a wildcard pattern 'pattern' of length N and M respectively,  You have to 
print '1' if the wildcard pattern is matched with str else print '0' .

The wildcard pattern can include the characters ‘?’ and ‘*’
‘?’ – matches any single character
‘*’ – Matches any sequence of characters (including the empty sequence)

Note: The matching should cover the entire str (not partial str).

*/
#include <bits/stdc++.h>
using namespace std;

int wildCard(string pat, string s){
	int n = pat.length();
	int m = s.length();

	//dp[i][j] = true if pat[i...n-1] matches s[j....m-1] 
	bool dp[n+1][m+1];

	for(int i = n; i >= 0; i--){
		for(int j = m; j >= 0; j--){
			//base cases:
			//if both strings are empty
			if(i == n && j == m){
				dp[i][j] = true;
			}
			//if pattern string is empty
			else if(i == n){
				dp[i][j] = false;
			}
			//if s string is empty
			else if(j == m){
				//if pat[i] = '*' it can take empty value
				//then we check for pat[i+1...n-1]
				if(pat[i] == '*'){
					dp[i][j] = dp[i+1][j];
				}
				else dp[i][j] = false;
			}
			else{
				//if pat[i] = '?' it can match any character
				if(pat[i] == '?' || pat[i] == s[j]){
					dp[i][j] = dp[i+1][j+1];
				}
				//if pat[i] = '*' we have 2 choices
				//1. match pat[i] with empty sequence and check for pat[i+1...n-1] and s[j....m-1]
				//2. match pat[i] with s[j] and check for pat[i...n-1] and s[j....m-1] since pat[i](i.e. '*') can taka
				//	 multiple values
				else if(pat[i] == '*'){
					dp[i][j] = dp[i+1][j] || dp[i][j+1];
				}
				else dp[i][j] = false;
			}
		}
	}

	return dp[0][0];
}

int main(){
	string pat, s;
	cin >> pat >> s;

	cout << wildCard(pat, s) << "\n";
	return 0;
}