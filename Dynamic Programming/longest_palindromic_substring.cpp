/*
Given a string S, find the longest palindromic substring in S. Substring of string S: S[ i . . . . j ] 
where 0 ≤ i ≤ j < len(S). Palindrome string: A string which reads the same backwards. More formally, 
S is palindrome if reverse(S) = S. Incase of conflict, return the substring which occurs first 
( with the least starting index).

*/

#include <bits/stdc++.h>
using namespace std;

//O(n^2) dp solutions
string LongestPalinSubstring(string s){
	int n = s.length();

	//dp[i][j] stores true if s[i...j] is palindromic
	bool dp[n][n];

	int start = 0, len = 1;

	//dp matrix is fill same as count palindromic substrings question
	for(int gap = 0; gap < n; gap++){
		for(int i = 0, j = gap; j < n; i++, j++){
			if(gap == 0){
				dp[i][j] = true;
			}
			else if(gap == 1){
				dp[i][j] = (s[i] == s[j]) ? true : false;
			}
			else{
				dp[i][j] = (s[i] == s[j]) ? dp[i+1][j-1] : false;
			}

			//here if s[i...j] is palindromic and (gap+1 == j-i+1) is greater
			//than previous selected LPSS then we update it
			if(gap+1 > len && dp[i][j] == true){
				start = i;
				len = gap + 1;
			}
		}
	}

	return s.substr(start, len);
}

int main(){
	string s;
	cin >> s;
	cout << LongestPalinSubstring(s) << "\n";
	return 0;
}