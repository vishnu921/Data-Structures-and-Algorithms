/*
Given a string of S as input. Your task is to write a program to remove or delete the minimum number of characters 
from the string so that the resultant string is a palindrome.
Note: The order of characters in the string should be maintained.

same for minimum insertions required to make string palindromic
*/

#include <bits/stdc++.h>
using namespace std;

/*
minimum number of deletions required to convert a string into palindromic string
is equal to the length of string - length of LPS
*/
int minimumDeletions(string s, int n){
	int dp[n][n] = {};

	//we first get length of LPS
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

	return n - dp[0][n-1];
}

int main(){
	string s;
	cin >> s;
	int n = s.length();
	cout << minimumDeletions(s, n) << "\n";
	return 0;
}