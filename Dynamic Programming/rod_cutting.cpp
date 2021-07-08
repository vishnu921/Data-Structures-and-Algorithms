/*
Given a rod of length N inches and an array of prices that contains prices of all pieces of size 
smaller than N. Determine the maximum value obtainable by cutting up the rod and selling the pieces.
*/

#include <bits/stdc++.h>
using namespace std;

//top down(recursion + memoisation)
int dp[1001] = {};
int cutRod_topDown(int price[], int n){
	//base case: profit from a rod of length <= 0 is 0
	if(n <= 0) return 0;

	//using memoised solutions
	if(dp[n] != 0) return dp[n];

	dp[n] = INT_MIN;
	/*
	we need to find maximum profit we can get from cutting rod of length n
	to achieve the optimal solution we do as following
		for each length i in [1, n] , we cut length i from the rod, add its price and recur for optimal
		of the remaining length i.e. (n-i)
	finally we return the maximum value
	*/
	for(int i = 0; i < n; i++){
		dp[n] = max(dp[n], price[i] + cutRod_topDown(price, n-i-1));
	}

	return dp[n];
}

//bottom up
int cutRod_BottomUp(int price[], int n){
	//dp[i] stores maximum profit we can get from optimally cutting rod of length i
	int dp[n+1];
	//base case
	dp[0] = 0;

	//fill the dp[] array in bottom up manner
	for(int i = 1; i <= n; i++){
		dp[i] = INT_MIN;
		for(int j = 0; j < i; j++){
			dp[i] = max(dp[i], price[j] + dp[i-j-1]);
		}
	}
	for(int i = 0; i <= n; i++)
		cout << dp[i] << " ";
	cout << endl;

	return dp[n];
}

//similarity from unbound knapsack problem
int cutRod_un_knapsack(int price[], int n){
	//dp[i][j] stores maximum profit from rod of length j
	//when maximum cut length is i
	int dp[n+1][n+1];

	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= n; j++){
			if(i == 0 || j == 0) dp[i][j] = 0;
			else{
				if(i <= j){
					dp[i][j] = max(price[i-1] + dp[i][j-i], dp[i-1][j]);
				}
				else dp[i][j] = dp[i-1][j];
			}
		}
	}

	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= n; j++){
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}

	return dp[n][n];
}

int main(){
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	cout << cutRod_topDown(a, n) << "\n";
	cout << cutRod_BottomUp(a, n) << "\n";
	cout << cutRod_un_knapsack(a, n) << "\n";
	return 0;
}