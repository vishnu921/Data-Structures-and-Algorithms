/* The Fibonacci numbers are the numbers in the following integer sequence.
0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, ……..

In mathematical terms, the sequence Fn of Fibonacci numbers is defined by the recurrence relation 

Fn = Fn-1 + Fn-2

with seed values 

F0 = 0 and F1 = 1.

Given a number n, print n-th Fibonacci Number. */
#include <bits/stdc++.h>
using namespace std;
#define ll long long

//memoization approach(top-dowm)
ll nth_fibonnaci_topDown(int n, ll dp[]){
	if(n <= 1) return n;

	if(dp[n] != 0) return dp[n];

	dp[n] = nth_fibonnaci_topDown(n-1, dp)+nth_fibonnaci_topDown(n-2, dp);

	return dp[n];
}

//tabulation approach(bottom-up)
ll nth_fibonnaci_BottomUp(int n){
	ll dp[n+1] = {};
	dp[0] = 0;
	dp[1] = 1;

	for(int i = 2; i <= n; i++){
		dp[i] = dp[i-1]+dp[i-2];
	}

	return dp[n];
}

int main(){
	int n;
	cin >> n;
	ll dp[n+1] = {0};
	cout << nth_fibonnaci_topDown(n, dp) << "\n";
	cout << nth_fibonnaci_BottomUp(n) << "\n";			
	return 0;
}