/*
There are n houses build in a line, each of which contains some value in it. A thief is going to steal the 
maximal value of these houses, but he can’t steal in two adjacent houses because the owner of the stolen 
houses will tell his two neighbors left and right side. What is the maximum stolen value?
*/
#include <bits/stdc++.h>
using namespace std;

//top down (memoisation)
int dp[10001];
int maxLoot_topDown(int a[], int n){
	if(n <= 0) return 0;

	//using memoised solution
	if(dp[n] != 0) return dp[n];

	//memoisation
	//we have 2 choice
	//1. chosing current element and move to other element next to adjacent element
	//2. Do not chose current element and move to adjacent element
	//get max out of these 2
	dp[n] = max(a[n-1]+maxLoot_topDown(a, n-2), maxLoot_topDown(a, n-1));

	return dp[n];
}

//bottom up (tabulation)
int maxLoot_bottomUp(int a[], int n){
	int dp[n+1];
	//base cases
	dp[0] = 0;
	dp[1] = a[0];

	//fill dp[] in bottom up manner
	for(int i = 2; i <= n; i++){
		dp[i] = max(a[i-1] + dp[i-2], dp[i-1]);
	}

	return dp[n];
}

//dp in O(1) space
int maxLoot_effSpace(int a[], int n){
	if(n == 0) return 0;

	int v1 = a[0];
	if(n == 1) return v1;

	int v2 = max(a[0], a[1]);
	if(n == 2) return v2;

	int max_val;
	for(int i = 2; i < n; i++){
		max_val = max(a[i]+v1, v2);
		v1 = v2;
		v2 = max_val;
	}

	return max_val;
}

int main(){
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	cout << maxLoot_topDown(a, n) << "\n";
	cout << maxLoot_bottomUp(a, n) << "\n";
	cout << maxLoot_effSpace(a, n) << "\n";
	return 0;
}