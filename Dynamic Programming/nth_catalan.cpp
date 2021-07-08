/*
Given a number N. The task is to find the Nth catalan number.
The first few Catalan numbers for N = 0, 1, 2, 3, … are 1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862,.....

C0 = 1;
Cn+1 = SUMOF(Ci*Cn-i) for i = [0, n]

also Catn = 2nCn/(n+1) where 2nCn is binomial coefficient
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
//tabulation approach
ll Catalan_dp(ll n){
	//dp[i] stores ith catalan number
	ll dp[n+1];
	//base cases
	dp[0] = 1;
	dp[1] = 1;

	//fill dp[] in bottom up manner using appropriate relations
	for(int i = 2; i <= n; i++){
		dp[i] = 0;
		for(int j = 0; j < i; j++){
			dp[i] += dp[j]*dp[i-j-1];
		}
	}

	return dp[n];
}

ll Catalan_using_binomialCoeff(ll n){
	ll ans = 1;

	//first calculate 2nCn
	for (int i = n; i >= 1; i--) {
		ans *= n+i;
		ans /= n-i+1;
	}

	//Catn = 2nCn/(n+1)
	ans /= n+1;
	return ans;
}

int main(){
	ll n;
	cin >> n;
	cout << Catalan_dp(n) << "\n";
	cout << Catalan_using_binomialCoeff(n) << "\n";
	return 0;
}
