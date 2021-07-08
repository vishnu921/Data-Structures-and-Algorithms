/*
Given an array arr of N positive integers, the task is to find the maximum sum increasing subsequence of the given array.
*/
#include <bits/stdc++.h>
using namespace std;

/*
this problem is just a variation of longest increasing subsequence
here instead of length we need to check for sum
*/
int msis(int a[],int n){
	int dp[n];         //dp[i] stores MSIS ending at a[i]

	//base case MSIS of one element array is the element itself
	dp[0] = a[0];

	for(int i = 1; i < n; i++){
		dp[i] = a[i];
		for(int j = 0; j < i; j++){
			if(a[i] > a[j] && dp[j] + a[i] > dp[i]){
				dp[i] = a[i] + dp[j];
			}
		}
	}

	return *max_element(dp, dp+n);
}

int main(){
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	cout << msis(a, n) << "\n";
	return 0;
}