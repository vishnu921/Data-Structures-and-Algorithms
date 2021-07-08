/*
There are n stairs, a person standing at the bottom wants to reach the top. The person can climb either 
1 stair or 2 stairs at a time. Count the number of ways, the person can reach the top (order does matter).
*/
#include <bits/stdc++.h>
using namespace std;

//top Down(memoisation)
int countways_topDown(int n, int dp[]){
	if(n <= 1) return 1;

	//using memoised solution
	if(dp[n] != 0) return dp[n];

	//memoising
	dp[n] = countways_topDown(n-1, dp)+countways_topDown(n-2, dp);

	return dp[n];
}

//bottom up(tabulation)
int countways_BottomUp(int n){
	//dp[i] stores number of ways to climb ith stair
	int dp[n+1];
	//initialise dp[] with base case
	dp[0] = 1;
	dp[1] = 1;

	//fill dp[] in bottom up manner
	for(int i = 2; i <= n; i++){
		dp[i] = dp[i-1]+dp[i-2];
	}

	return dp[n];
}

//bottom up with O(1) space
int countways_constspace(int n){
	if(n <= 1) return 1;

	//in tabulation approach we observe that to calculate solution for ith step
	//we need only solution of (i-1)th and (i-2)th step hence we don't need to build a whole array
	//instead we can store last 2 solution in 2 int variables and solve the problem
	int m1 = 1;
	int m2 = 1;
	int res;

	for(int i = 2; i <= n; i++){
		res = m1+m2;
		m2 = m1;
		m1 = res;
	}

	return res;
}

int main(){
	int n;
	cin >> n;
	int dp[n+1] = {0};
	cout << countways_topDown(n, dp) << "\n";
	cout << countways_BottomUp(n) << "\n";
	cout << countways_constspace(n) << "\n";
	return 0;
}