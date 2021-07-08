/*
You are given weights and values of N items, put these items in a knapsack of capacity W to get the 
maximum total value in the knapsack. Note that we have only one quantity of each item.
In other words, given two integer arrays val[0..N-1] and wt[0..N-1] which represent values and weights 
associated with N items respectively. Also given an integer W which represents knapsack capacity, find 
out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or 
equal to W. You cannot break an item, either pick the complete item or don’t pick it (0-1 property).
*/
#include <bits/stdc++.h>
using namespace std;

//top Down approach(Memoization)
//table to memoize the solution to subproblems
int dp[1001][1001] = {0};
int knapsack_topDown(int wt[], int val[], int n, int w){
	//base case if n == 0 or w == 0 then maximum profit = 0
	if(n == 0 || w == 0)
		return 0;

	//if the sub-problem is already solved then return it
	if(dp[n][w] != 0) return dp[n][w];

	//if weight of current item <= w(capacity of knapsack) then we have 2 choices
	//either to include it or not include it
	//we recur for both choices and return the maximum profit
	if(wt[n-1] <= w){
		dp[n][w] = max(val[n-1]+knapsack_topDown(wt, val, n-1, w-wt[n-1]), knapsack_topDown(wt, val, n-1, w));
	}
	//else we do not include it at all
	else dp[n][w] = knapsack_topDown(wt, val, n-1, w);

	return dp[n][w];
}

//Bottom up approach(tabulation)
int knapsack_bottomUp(int wt[], int val[], int n, int w){
	//dp[i][j] stores maximum profit when first i element are processed and W = j
	int dp[n+1][w+1];

	//initializing dp[][] with base case
	for(int i = 0; i <= n; i++)
		dp[i][0] = 0;
	for(int j = 0; j <= w; j++)
		dp[0][j] = 0;

	//fill the dp[][] in bottom up manner
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= w; j++){
			if(wt[i-1] <= j){
				dp[i][j] = max(val[i-1]+dp[i-1][j-wt[i-1]], dp[i-1][j]);
			}
			else dp[i][j] = dp[i-1][j];
		}
	}

	return dp[n][w];
}

int main(){
	int n, w;
	cin >> n >> w;
	int wt[n], val[n];

	cout << "wt[] = ";
	for(int i = 0; i < n; i++){
		cin >> wt[i];
	}
	cout << "val[] = ";
	for(int i = 0; i < n; i++){
		cin >> val[i];
	}

	cout << knapsack_topDown(wt, val, n, w) << "\n";
	cout << knapsack_bottomUp(wt, val, n, w) << "\n";
	return 0;
}