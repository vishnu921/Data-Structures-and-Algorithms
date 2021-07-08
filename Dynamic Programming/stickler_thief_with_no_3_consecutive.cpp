/*
Given a sequence of positive numbers, find the maximum sum that can be formed which has no three consecutive elements present.
*/

#include <bits/stdc++.h>
using namespace std;

int maxSumWO3Consec(int a[], int n){
	int dp[n];         //dp[i] stores maximum sum possible in array a[0...i] such that no 3 elements are consecutive

	if(n >= 1) dp[0] = a[0];
	if(n >= 2) dp[1] = a[0] + a[1];
	if(n >= 3) dp[2] = max(a[0]+a[1], max(a[0]+a[2], a[1]+a[2]));

	/*
	we have 3 choices
	1. exclude a[i] then dp[i] = dp[i-1]
	2. exclude a[i-1] then dp[i] = a[i] + dp[i-2]
	3. exclude a[i-2] then dp[i] = a[i] + a[i-1] + dp[i-3]
	*/
	for(int i = 3; i < n; i++){
		int e1 = dp[i-1];           			//exclude a[i]
		int e2 = dp[i-2] + a[i];      			//exclude a[i-1]
		int e3 = dp[i-3] + a[i-1] + a[i];		//exclude a[i-2]

		dp[i] = max(e1, max(e2, e3));
	}

	return dp[n-1];
}

int main(){
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	cout << maxSumWO3Consec(a, n) << "\n";
	return 0;
}