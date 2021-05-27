/*
Given an array of non-negative integers. Our task is to find minimum number of elements such that their sum should be 
greater than the sum of rest of the elements of the array.
*/
#include <bits/stdc++.h>
using namespace std;

int smallestSubset(int a[], int n){
	int halfsum = 0;
	for(int i = 0; i < n; i++){
		halfsum += a[i];
	}
	halfsum = halfsum/2;

	//sort array in descending order
	sort(a, a+n, greater<int>());

	//take elements until their sum becomes greater than halfsum of the array
	int cur_sum = 0;
	int result = 0;
	for(int i = 0; i < n; i++){
		cur_sum += a[i];
		result++;

		if(cur_sum > halfsum) return result;
	}
	return result;
}

int main(){
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	cout << smallestSubset(a, n) << endl;
	return 0;
}