/*
Given an array Arr that contains N integers (may be positive, negative or zero). Find the 
product of the maximum product subarray.

Example 1:

Input:
N = 5
Arr[] = {6, -3, -10, 0, 2}
Output: 180
*/
#include <bits/stdc++.h>
using namespace std;

long long maxProduct(int *arr, int n) {
	long long minval = arr[0];
	long long maxval = arr[0];
	long long maxProduct = arr[0];   

	for(int i = 1; i < n; i++){
		//since we will be multiplying the products with a negetive number
		//we swap both values because product of minimum number with a negetive
		//number gives maximum value and vice versa.
		if(arr[i] < 0)
			swap(minval,maxval);

		maxval = max((long long)arr[i], maxval*arr[i]);
		minval = min((long long)arr[i], minval*arr[i]);

		maxProduct = max(maxProduct, maxval);
	}

	return maxProduct;
}

int main(){
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	return 0;
}