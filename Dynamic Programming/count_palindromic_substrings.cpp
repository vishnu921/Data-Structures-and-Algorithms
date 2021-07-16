/*
Given a string, the task is to count all palindrome substring in a given string. Length of palindrome 
substring is greater then or equal to 2.

Examples:
Input : str = "abaab"
Output: 3
Explanation : 
All palindrome substring are :
 "aba", "aa", "baab" 
 */

#include <bits/stdc++.h>
using namespace std;

//O(n^2)
int countPalinSubstring(string s){
	int n = s.length();

	//dp[i][j] stores true if s[i...j] is palindromic or not
	bool dp[n][n];

	int res = 0;

	for(int gap = 0; gap < n; gap++){
		for(int i = 0, j = gap; j < n; i++, j++){
			//if gap == 0 that means only 1 element hence dp[i][j] = true
			if(gap == 0){
				dp[i][j] = true;
			}

			//else if gap == 1 i.e. 2 elements -> if they are same dp[i][j] = true else false
			else if(gap == 1){
				if(s[i] == s[j]){
					dp[i][j] = true;
				}
				else dp[i][j] = false;
			}
			//else for gap >= 2 
			//	if a string s = c1rc2 is palindromic then it must follow below 2 conditions
			//	1. c1 == c2
			//  2. string 'r' is palindromic  
			else{

				if(s[i] == s[j]){
					dp[i][j] = dp[i+1][j-1];
				}
				else{
					dp[i][j] = false;
				}
			}

			if(dp[i][j] == true) res++;
		}
	}

	return res;
}

int main(){
	string s;
	cin >> s;

	cout << countPalinSubstring(s) << "\n";
	return 0;
}