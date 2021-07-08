/*
Given N friends, each one can remain single or can be paired up with some other friend. Each friend can be 
paired only once. Find out the total number of ways in which friends can remain single or can be paired up.
Note: Since answer can be very large, return your answer mod 10^9+7.

ex: n = 4
we have to choices
1. Do not pair the current element with any element
2. Pair the current element with all remaining element and recur


hence
if n == 1 return 1
if n== 2 return 2 
For n > 2 => friendsPairing(n) = friendsPairing(n-1) + (n-1)*friendsPairing(n-2)

(1,2,3,4)______1,(2,3,4)________1,2,(3,4)_______1,2,3,4         -- [1]
	|   			|	           |____________1,2,34          -- [2]
	|				|
	|				|___________________________1,23,4          -- [3]
	|               |___________________________1,24,3          -- [4]
    |
    |__________12,(3,4)________12,3,4                           -- [5]
    |               |___________12,34                           -- [6]
    |
    |__________13,(2,4)_________13,2,4                          -- [7]
    |              |______________13,24                         -- [8]
    |
    |__________14,(2,3)____________14,2,3                       -- [9]
                  |________________14,23                        -- [10]

hence total number of ways to pair 4 friends = 10
[1,2,3,4], [1,2,34], [1,23,4], [1,24,3], [12,3,4], [12,34], [13,2,4], [13,24], [14,2,3], [14,23]

*/
#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
//top down
long long dp[10001] = {};
long long friendsPairing_topDown(int n){
	//base cases
	if(n <= 2)
		return n;

	//using memoised solutions
	if(dp[n] != 0) return dp[n];

	//1. do not pair with any
	int exc = friendsPairing_topDown(n-1)%mod;
	//2. pair with remaining (n-1) elements
	int paired = (((n-1)%mod)*friendsPairing_topDown(n-2)%mod)%mod;

	dp[n] = (exc+paired)%mod;

	return dp[n];
}

//bottom up
long long friendsPairing_bottomUp(int n){
	long long dp[n+1] = {};
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;

	for(int i = 3; i <= n; i++){
		dp[i] = ((dp[i-1]%mod) + ((i-1)%mod*(dp[i-2]%mod))%mod)%mod;
	}

	return dp[n];
}

//O(1) space
long long friendsPairing_constSpace(int n){
	if(n <= 2) return n;
        
    long long v1 = 1;
    long long v2 = 2;
    long long ans;
    
    for(int i = 3; i <= n; i++){
        ans = (v2%mod + ((i-1)%mod*v1%mod))%mod;
        v1 = v2;
        v2 = ans;
    }
    
    return ans;
}

int main(){
	int n;
	cin >> n;
	cout << friendsPairing_topDown(n) << "\n";
	cout << friendsPairing_bottomUp(n) << "\n";
	cout << friendsPairing_constSpace(n) << "\n";
	return 0;
}