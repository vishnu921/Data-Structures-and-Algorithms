/*
Given n stairs and we have 2 colour yellow and green the task is that we have to paint given stairs by given 
colour with condition is that we cannot paints two yellow steps directly after each other.
*/

#include <bits/stdc++.h>
using namespace std;

//tabulation approach
int countways(int n){
	int dp[n+1];
	//initialize with base case
	dp[1] = 2;
	dp[2] = 3;

	for(int i = 3; i <= n; i++){
		dp[i] = dp[i-1]+dp[i-2];
	}

	return dp[n];
}

int main(){
	int n;
	cin >> n;
	cout << countways(n) << "\n";
	return 0;
}