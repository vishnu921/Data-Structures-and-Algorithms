/*
Given two sequences, print the longest subsequence present in both of them.

Examples:
LCS for input Sequences “ABCDGH” and “AEDFHR” is “ADH” of length 3.
LCS for input Sequences “AGGTAB” and “GXTXAYB” is “GTAB” of length 4.
*/
#include <bits/stdc++.h>
using namespace std;

string print_lcs(string s, string t){
	int n = s.length();
	int m = t.length();

	//first build the dp matrix to calculate length of lcs
	int dp[n+1][m+1];
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= m; j++){
			if(i == 0 || j == 0) dp[i][j] = 0;
			else if(s[i-1] == t[j-1]){
				dp[i][j] = 1 + dp[i-1][j-1];
			}
			else{
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}

	string res = "";
	int i = n, j = m;
	//traverse the path for finding lcs
	while(i > 0 && j > 0){
		if(s[i-1] == t[j-1]){
			res += s[i-1];
			i--;
			j--;
		}
		else if(dp[i-1][j] > dp[i][j-1]){
			i--;
		}
		else j--;
	}

	//the string we get from above is reverse of lcs since we are traversing dp from last
	//therefore first reverse it and then return it
	reverse(res.begin(), res.end());
	return res;
}

int main(){
	string s,t;
	cin >> s >> t;
	cout << print_lcs(s, t) << "\n";
	return 0;
}