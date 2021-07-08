/*
Given an array arr[] of size N, check if it can be partitioned into two parts such that the sum of elements
in both parts is the same.
*/
#include <bits/stdc++.h>
using namespace std;

bool ispartitionPossible(int a[], int n){
	int sum = 0;
	for(int i = 0; i < n; i++){
		sum += a[i];
	}

	//if sum is odd we cannot divide a[] into 2 equal sum subsets
	if(sum&1) return false;

	//now we have to if there exist a subset with sum = sum/2
	//if it exists then we know that other subset has also sum = sum/2
	//hence return true
	sum /= 2;

	//dp[i] stores if there exists a subset with sum = i
	bool dp[sum+1] = {};
	dp[0] = 1;

	for(int i = 0; i < n; i++){
		for(int j = sum; j >= a[i]; j--){
			if(dp[j-a[i]] == true){
				dp[j] = true;
			}
		}
	}

	return dp[sum];
}

int main(){
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	if(ispartitionPossible(a, n)){
		cout << "YES\n";
	}
	else cout << "NO\n";
	return 0;
}