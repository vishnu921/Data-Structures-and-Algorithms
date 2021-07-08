/*
Given a set of non-negative integers, and a value sum, determine if there is a subset of the 
given set with sum equal to given sum. 
*/
#include <bits/stdc++.h>
using namespace std;

//top down approach (recursion + memoisation)
int dp[101][100001];
int subsetSum_topDown(int a[], int n, int sum){
	//base cases
	if(sum == 0) return true;
	if(n == 0) return false;

	//using memoised solutions of subproblems
	if(dp[n][sum] != -1) return dp[n][sum];

	//if current element <= remaining sum
	//we have 2 choices either to cho0se it or not choose it
	if(a[n-1] <= sum){
		dp[n][sum] = (subsetSum_topDown(a, n-1, sum-a[n-1]) || subsetSum_topDown(a, n-1, sum));
	}
	//else we cannot chose the current element
	else dp[n][sum] = subsetSum_topDown(a, n-1, sum);

	return dp[n][sum];
}

//bottom up(tabulation) approach (time & space : O(n*sum))
bool subsetSum_bottomUp(int a[], int n, int sum){
	//dp[i][j] stores true if there exists a subset with sum j in array arr[0....i]
	bool dp[n+1][sum+1] = {};

	//fill dp[][] in bottom up manner using appropriate relations to solve the problem
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= sum; j++){
			//base cases
			if(j == 0) dp[i][j] = true;
			else if(i == 0) dp[i][j] = false;
			else{
				if(a[i-1] <= j){
					dp[i][j] = (dp[i-1][j-a[i-1]] || dp[i-1][j]);
				}
				else dp[i][j] = dp[i-1][j];
			}
		}
	}

	return dp[n][sum];
}

//dp in O(sum) space
bool subsetSum_spaceEfficient(int a[], int n, int sum){
	//dp[i] stores if there exists a subset with sum = i
	bool dp[sum+1] = {};
	//base case: subset with sum = 0 always exists which is an empty set
	dp[0] = 1;

	for(int i = 0; i < n; i++){
		for(int j = sum; j >= a[i]; j--){
			//if subset of sum = j-a[i] exists then subset of sum=j also exists in the array
			if(dp[j-a[i]] == true){
				dp[j] = true;
			}
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
	memset(dp, -1, sizeof(dp));
	cout << subsetSum_topDown(a, n, sum) << "\n";
	cout << subsetSum_bottomUp(a, n, sum) << "\n";
	cout << subsetSum_spaceEfficient(a, n, sum) << "\n";
	return 0;
}