/*
Given an array of integers arr[] and a number K.You can pair two numbers of the array if the difference between them is strictly less than K. The task is to find the maximum possible sum of such disjoint pairs. The Sum of P pairs is the sum of all 2P numbers of pairs.
*/

#include <bits/stdc++.h>
using namespace std;

//O(nlogn)
int maxSumPairs(int a[], int n, int k){
	//first we sort the input array
	sort(a, a+n);

	//dp[i] stores maximum sum pairs with difference less than k using first (i+1) elements
	int dp[n];

	//base cases
	//if only one element is present
	dp[0] = 0;
	//if only 2 elements are present
	if(a[1]-a[0] < k){
		dp[1] = a[1] + a[0];
	}
	else dp[1] = 0;

	//for every element a[i] (2 <= i < n) we have 2 choices
	//if a[i]-a[i-1] < k we make pair them add them to dp[i]
	//because we are traversing from left to right and a[i-1] is always greater than a[i-2]
	//else dp[i] = d[i-1]
	for(int i = 2; i < n; i++){
		if(a[i]-a[i-1] < k){
			dp[i] = dp[i-2] + a[i] + a[i-1];
		}
		else dp[i] = dp[i-1];
	}

	return dp[n-1];
}

int main(){
	int n,k;
	cin >> n >> k;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	cout << maxSumPairs(a, n, k) << endl;
	return 0;
}