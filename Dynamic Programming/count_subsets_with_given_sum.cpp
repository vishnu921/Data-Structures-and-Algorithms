/*
Given an array arr[] of integers and an integer sum, the task is to count all subsets of the 
given array with a sum equal to a given sum.
*/
#include <bits/stdc++.h>
using namespace std;
//this problem is very similar to subset sum problem
//we just need to return int instead of boolean
// and use '+' operator instead of '||'(or) operator

//top down approach (recursion + memoisation)
int dp[101][100001];
int countSubsets_topdown(int a[], int n, int sum){
	//base cases
	if(sum == 0) return 1;
	if(n == 0) return 0;

	//using memoised solutions of subproblems
	if(dp[n][sum] != 0) return dp[n][sum];

	//if current element <= remaining sum
	//we have 2 choices either to choose it or not choose it
	if(a[n-1] <= sum){
		dp[n][sum] = (countSubsets_topdown(a, n-1, sum-a[n-1]) + countSubsets_topdown(a, n-1, sum));
	}
	//else we cannot chose the current element
	else dp[n][sum] = countSubsets_topdown(a, n-1, sum);

	return dp[n][sum];
}

//bottom up(tabulation) approach (time & space : O(n*sum))
int countSubsets_bottomUp(int a[], int n, int sum){
	//dp[i][j] stores number of subsets with sum j in array arr[0....i]
	int dp[n+1][sum+1] = {};

	//fill dp[][] in bottom up manner using appropriate relations to solve the problem
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= sum; j++){
			//base cases
			if(j == 0) dp[i][j] = 1;
			else if(i == 0) dp[i][j] = 0;
			else{
				if(a[i-1] <= j){
					dp[i][j] = (dp[i-1][j-a[i-1]] + dp[i-1][j]);
				}
				else dp[i][j] = dp[i-1][j];
			}
		}
	}

	return dp[n][sum];
}

//dp in O(sum) space
int countSubsets_spaceEfficient(int a[], int n, int sum){
	//dp[i] stores number of subsets with sum = i
	int dp[sum+1] = {};
	//base case: subset with sum = 0 always exists which is an empty set
	dp[0] = 1;

	for(int i = 0; i < n; i++){
		for(int j = sum; j >= a[i]; j--){
				dp[j] += dp[j-a[i]];
		}
	}

	return dp[sum];
}

int main(){
	int n, sum;
	cin >> n >> sum;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	memset(dp, 0, sizeof(dp));
	cout << countSubsets_topdown(a, n, sum) << "\n";
	cout << countSubsets_bottomUp(a, n, sum) << "\n";
	cout << countSubsets_spaceEfficient(a, n, sum) << "\n";
	return 0;
}