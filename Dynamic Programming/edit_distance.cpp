/*
Given two strings s and t. Find the minimum number of operations that need to be performed on str1 to convert it 
to str2. The possible operations are:

    1. Insert
    2. Remove
    3. Replace

*/
#include <bits/stdc++.h>
using namespace std;

//top down (recursion + memoisation)
int dp[1001][1001];
int editDistance_topDown(string s, string t, int n, int m){
	//base case: if any of the string is empty then ED = length of other string
	if(n == 0){
		return m;
	}
	if(m == 0){
		return n;
	}

	//using memoised solution
	if(dp[n][m] != -1) return dp[n][m];

	//current char of both string are same
	//then we don't need to do any operation and recur for remaining strings
	if(s[n-1] == t[m-1]){
		dp[n][m] = editDistance_topDown(s, t, n-1, m-1);
	}
	//else we have 3 choices (insert, remove and replace)
	//we recur for every choices and store the minimum value amongst them in dp matrix
	else{
		int ins = 1 + editDistance_topDown(s, t, n, m-1);
		int rem = 1 + editDistance_topDown(s, t, n-1, m);
		int rep = 1 + editDistance_topDown(s, t, n-1, m-1);

		dp[n][m] = min(ins, min(rem, rep));
	}

	return dp[n][m];
}

//bottom up (tabulation)
int editDistance_bottomUp(string s, string t, int n, int m){
	//dp[i][j] stores minimum editDistance of string s1[0...(i-1)] and t[0....(j-1)]
	int dp[n+1][m+1];

	//fill the dp matrix in bottom up manner
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= m; j++){
			if(i == 0){
				dp[i][j] = j;
			}
			else if(j == 0){
				dp[i][j] = i;
			}
			else if(s[i-1] == t[j-1]){
				dp[i][j] = dp[i-1][j-1];
			}
			else{
				dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
			}
		}
	}

	return dp[n][m];
}


int main(){
	string s, t;
	cin >> s >> t;
	int n = s.length();
	int m = t.length();
	memset(dp, -1, sizeof(dp));
	cout << editDistance_topDown(s, t, n, m) << "\n";
	cout << editDistance_bottomUp(s, t, n, m) << "\n";
	return 0;
}