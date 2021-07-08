/*
Given a set of N items, each with a weight and a value, and a weight limit W. Find the maximum
 value of a collection containing any of the N items any number of times so that the total weight 
 is less than or equal to W.
*/

#include <bits/stdc++.h>
using namespace std;

//top down(recursion+memoisation)
int dp[1001][1001];
int KnapSack_topDown(int n, int w, int wt[], int val[]){
	if(w == 0 || n == 0) return 0;

	if(dp[n][w] != 0) return dp[n][w];

	//if weight of current item is less than or equal to capacity, we have 2 choices
	//1. include the current item and recur for same elements(since we can include any items any number of times)
	//2. exclude the current item and recur for all elements except the current item
	if(wt[n-1] <= w){
		dp[n][w] = max(val[n-1]+KnapSack_topDown(n, w-wt[n-1], wt, val), KnapSack_topDown(n-1, w, wt, val));
	}
	//else we exclude current item and recur for all elements except the current item
	else dp[n][w] = KnapSack_topDown(n-1, w, wt, val);

	return dp[n][w];
}

//bottom up 
int KnapSack_bottomUp(int n, int w, int wt[], int val[]){
	//dp[i][j] stores maximum profit when first i elements are processed and knapsack capacity = j
	int dp[n+1][w+1];

	//fill the dp[][] in bottom up manner
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= w; j++){
			//base cases
			if(i == 0 || j == 0){
				dp[i][j] = 0;
			}
			else{
				if(wt[i-1] <= j){
					dp[i][j] = max(val[i-1] + dp[i][j-wt[i-1]], dp[i-1][j]);
				}
				else{
					dp[i][j] = dp[i-1][j];
				}
			}
		}
	}

	return dp[n][w];
}

int main(){
	int n, w;
	cin >> n >> w;
	int wt[n], val[n];
	cout << "weight: ";
	for(int i = 0; i < n; i++){
		cin >> wt[i];
	}
	cout << "value: ";
	for(int i = 0; i < n; i++){
		cin >> val[i];
	}
	memset(dp, 0, sizeof(dp));
	cout << KnapSack_topDown(n, w, wt, val) << "\n";
	cout << KnapSack_bottomUp(n, w, wt, val) << "\n";
	return 0;
}