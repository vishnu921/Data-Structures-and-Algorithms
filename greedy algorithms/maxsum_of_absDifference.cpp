/*
Given an array, we need to find the maximum sum of absolute difference
of any permutation of the given array.
*/
#include <bits/stdc++.h>
using namespace std;

int maxSumOfAbsoluteDifference(int a[], int n){
	sort(a, a+n);
	int ans = 0;
	for(int i = 0; i < n/2; i++){
		ans -= (2*a[i]);
		ans += (2*a[n-i-1]);
	}
	return ans;
}

int main(){
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	cout << maxSumOfAbsoluteDifference(a, n) << endl;
	return 0;
}