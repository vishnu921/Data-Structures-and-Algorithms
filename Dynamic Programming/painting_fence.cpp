/*
Given a fence with n posts and k colors, find out the number of ways of painting the fence such that at 
most 2 adjacent posts have the same color. Since answer can be large return it modulo 10^9 + 7.
*/

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

//O(1) space and more intuitive
/*
for n = 2
last_same = k     //choices for common color of 2 posts
last_diff = k*(k-1)   //simple permutation
total = k*k

now for n = 3
last_same = k*(k-1)*(k-1)      //which is last_diff(2)*(k-1)
last_diff = k*k*(k-1)              //which is total(2)*(k-1)

hence we find that
last_same[i] = last_diff[i-1]
last_diff[i] = total[i]*(k-1)
total[i] = last_same[i] + last_diff[i]
*/

long long paintingFence_constSpace(int n, int k){
	//last_same means no. of ways last 2 posts are same
	//last_diff means no. of ways last 2 posts are different
	long long last_same, last_diff, total;
	last_same = 0;
	last_diff = k;
	total = k;

	for(int i = 2; i <= n; i++){
		last_same = last_diff;
		last_diff = total*(k-1)%mod;
		total = (last_same+last_diff)%mod;
	}

	return total;
}


//bottom up
long long paintingFence_bottomUp(int n, int k){
	long long dp[n+1];        //dp[i] stores number of ways to paint i posts
	dp[1] = k;
	dp[2] = k*k;

	for(int i = 3; i <= n; i++){
		dp[i] = (k-1)*(dp[i-1] + dp[i-2])%mod;
	}

	return dp[n];
}

int main(){
	int n, k;
	cin >> n >> k;
	cout << paintingFence_bottomUp(n, k) << "\n";
	cout << paintingFence_constSpace(n, k) << "\n";
	return 0;
}