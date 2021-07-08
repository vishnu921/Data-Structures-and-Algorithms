/*
You are given an integer array coins representing coins of different denominations and an integer amount
 representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot 
be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.
*/

#include <bits/stdc++.h>
using namespace std;

//top down (recursion + memoisation)
int dp[10001] = {};
int coinChange_topDown(int coins[], int n, int amount){
	//base case if amount = 0 then minimum no. of coins required = 0
	if(amount == 0) return 0;
	//base case: invalid amount
	if(amount < 0) return -1;

	if(dp[amount] != 0) return dp[amount];

	int res = INT_MAX;

	for(int i = 0; i < n; i++){
		int sub_res = coinChange_topDown(coins, n, amount-coins[i]);
		if(sub_res >= 0 && sub_res < res){
			res = 1 + sub_res;
		}
	}

	dp[amount] = (res == INT_MAX) ? -1 : res;

	return dp[amount];
}

//bottom up
int coinChange_Bottomup(int coins[], int n, int amount){
	//dp[i][j] stores min. number of coins needed to make amount j using first i coins only
	int dp[n+1][amount+1];

	//base cases
	//1. when there is no element in the coins[]
	for(int i = 1; i <= amount; i++){
		dp[0][i] = INT_MAX-1;
	}
	//2. when amount is 0
	for(int i = 0; i <= n; i++){
		dp[i][0] = 0;
	}

	//fill the dp in bottom-up manner by computing
	//minimum coins required for every pair of i,j
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= amount; j++){
			if(coins[i-1] <= j){
				dp[i][j] = min(1+dp[i][j-coins[i-1]], dp[i-1][j]);
			}
			else dp[i][j] = dp[i-1][j];
		}
	}

	if(dp[n][amount] == INT_MAX-1) return -1;
	return dp[n][amount];
}

//1D dynamic programming
int coinChange_1Ddp(int coins[], int n, int amount){
	//dp[i] stores minimum number of coins required for amount i
	vector<int> dp(amount+1, INT_MAX);

	//base case
	dp[0] = 0;

	for(int i = 1; i <= amount; i++){
		for(int j = 0; j < n; j++){
			if(coins[j] <= i){
				int sub_res = dp[i-coins[j]];
				if(sub_res != INT_MAX && dp[i] > sub_res+1){
					dp[i] = sub_res+1;
				}
			}
		}
	}

	if(dp[amount] == INT_MAX) return -1;
	return dp[amount];
}

int main(){
	int n, amount;
	cin >> n >> amount;
	int coins[n];

	for(int i = 0; i < n; i++){
		cin >> coins[i];
	}

	cout << coinChange_topDown(coins, n, amount) << "\n";
	cout << coinChange_Bottomup(coins, n, amount) << "\n";
	cout << coinChange_1Ddp(coins, n, amount) << "\n";
	return 0;
}