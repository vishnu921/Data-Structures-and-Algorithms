/*
You are given an integer array coins representing coins of different denominations and an integer amount 
representing a total amount of money.

Return the number of combinations that make up that amount. If that amount of money cannot be made up by
any combination of the coins, return 0.

You may assume that you have an infinite number of each kind of coin.
*/

#include <bits/stdc++.h>
using namespace std;

//top down
int dp[101][1001];
int coinChange_topDown(int a[], int n, int amount){
	//base case: if amount = 0 there is one way that is an empty set of coins
	if(amount == 0) return 1;
	//if amount < 0 then we have chosen wrong coins in the set hence return 0
	if(amount < 0) return 0;

	if(n <= 0 && amount > 0) return 0;

	if(dp[n][amount] != 0) return dp[n][amount];

	//this is similar to unbound knapsack
	//if value of current coin is less than the amount
	//we recur for count of combination after 1. including and 2. excluding
	if(a[n-1] <= amount){
		dp[n][amount] = coinChange_topDown(a, n, amount-a[n-1]) + coinChange_topDown(a, n-1, amount);
	}
	//else we recur for count of combination by excluding
	else dp[n][amount] = coinChange_topDown(a, n-1, amount);

	return dp[n][amount];
}

//bottom up
int coinChange_bottomUp(int a[], int n, int amount){
	//dp[i][j] stores number of combinations for amount = j by using first i coins
	int dp[n+1][amount+1];

	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= amount; j++){
			if(j == 0) dp[i][j] = 1;
			else if(i == 0) dp[i][j] = 0;
			else{
				if(a[i-1] <= j){
					dp[i][j] = dp[i][j-a[i-1]] + dp[i-1][j];
				}
				else dp[i][j] = dp[i-1][j];
			}
		}
	}

	return dp[n][amount];
}

int coinChange_spaceEfficient(int a[], int n, int amount){
	int dp[amount+1] = {};
	//base case
	dp[0] = 1;

	for(int i = 0; i < n; i++){
		for(int j = a[i]; j <= amount; j++){
			dp[j] += dp[j-a[i]];
		}
	}

	return dp[amount];
}

int main(){
	int n, amount;
	cin >> n >> amount;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	cout << coinChange_topDown(a, n, amount) << "\n";
	cout << coinChange_bottomUp(a, n, amount) << "\n";
	cout << coinChange_spaceEfficient(a, n, amount) << "\n";
	return 0;
}