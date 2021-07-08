/*
Given two strings. The task is to find the length of the longest common substring.
*/

#include <bits/stdc++.h>
using namespace std;

//recursion solution
int lcsubstring_recursion(string s1, string s2, int n, int m, int count){
	if(n == 0 || m == 0) return count;

	if(s1[n-1] == s2[m-1]){
		count = lcsubstring_recursion(s1, s2, n-1, m-1, count+1);
	}

	count = max(count, max(lcsubstring_recursion(s1,s2,n-1,m,0), lcsubstring_recursion(s1,s2,n,m-1,0)));

	return count;
}

//bottom up
int lcsubstring_bottomup(string s1, string s2, int n, int m){
	//dp[i][j] stores longest common "suffix" of s1[0...(i-1)] and s2[0....(j-1)]
	int dp[n+1][m+1];
	int res = 0;

	/*
	let s1 = r1c1 and s2 = r2c2
	if(c1 == c2)
		lcSuffix(s1, s2) = 1 + lcSuffix(r1, r2)
	else lcSUffix(s1,s2) = 0

	we fill the dp using above relations
	then we return the longest common suffix because the longest common substring of s1 and s2
	is longest common suffix of some prefix of s1 and s2
	*/
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= m; j++){
			if(i == 0 || j == 0 || s1[i-1] != s2[j-1]){
				dp[i][j] = 0;
			}
			else{
				dp[i][j] = 1 + dp[i-1][j-1];
				res = max(res, dp[i][j]);
			}
		}
	}

	return res;
}

int main(){
	string s1, s2;
	cin >> s1 >> s2;
	int n = s1.length();
	int m = s2.length();
	cout << lcsubstring_recursion(s1,s2,n,m,0) << "\n";
	cout << lcsubstring_bottomup(s1,s2,n,m) << "\n";
	return 0;
}