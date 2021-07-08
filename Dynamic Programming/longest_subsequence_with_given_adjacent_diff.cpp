/*
Given an integer array arr and an integer difference, return the length of the longest subsequence in arr which 
is an arithmetic sequence such that the difference between adjacent elements in the subsequence equals difference.

A subsequence is a sequence that can be derived from arr by deleting some or no elements without changing the 
order of the remaining elements.
*/
#include <bits/stdc++.h>
using namespace std;

//dp solution O(n^2)
int longestSubsequence_dp(int a[], int n, int diff){
	//dp[i] stores longest subsequence with adjacent difference 'diff' ending at a[i]
	int dp[n];
	dp[0] = 1;
	for(int i = 1; i < n; i++){
		dp[i] = 1;
		for(int j = 0; j < i; j++){
			if(abs(a[i]-a[j]) == diff && dp[i] < dp[j]+1){
				dp[i] = dp[j]+1;
			}
		}
	}

	return *max_element(dp, dp+n);
}

//O(n) solution
int longestSubsequence_On(int a[], int n, int diff){
	int ans = 0;     //stores finally answer
	unordered_map<int,int> mp;      //stores key as a[i] and value as LS with adjacent difference 'diff' ending at a[i]

	for(int i = 0; i < n; i++){
		int len = 0;

		/*
		for every element we check whether a[i]-diff or a[i]+diff exist in the array
		if exist we stores LS ending at a[i]  = 1 + max(LS ending at a[i]-diff, LS ending at a[i]+diff)
		else LS ending a[i] = 1
		*/
		if(mp.find(a[i]-diff) != mp.end())
			len = mp[a[i]-diff];

		if(mp.find(a[i]+diff) != mp.end() && len < mp[a[i]+diff])
			len = mp[a[i]+diff];

		mp[a[i]] = len+1;

		ans = max(mp[a[i]], ans);
	}

	return ans;
}

int main(){
	int n, diff;
	cin >> n >> diff;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	cout << longestSubsequence_dp(a, n, diff) << "\n";
	cout << longestSubsequence_On(a, n, diff) << "\n";
	return 0;
}