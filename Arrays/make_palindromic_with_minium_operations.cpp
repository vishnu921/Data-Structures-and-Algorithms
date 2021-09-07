/*
Given an array of positive integers. We need to make the given array a ‘Palindrome’. The only allowed 
operation is”merging” (of two adjacent elements). Merging two adjacent elements means replacing them 
with their sum. The task is to find the minimum number of merge operations required to make the given 
array a ‘Palindrome’.
To make any array a palindrome, we can simply apply merge operation n-1 times where n is the size of 
the array (because a single-element array is always palindromic, similar to single-character string). 
In that case, the size of array will be reduced to 1. But in this problem, we are asked to do it in the
minimum number of operations.
*/
#include <bits/stdc++.h>
using namespace std;

//O(1) solution
int minimumOperations(int arr[], int n){
	int i = 0, j = n-1;
	int count = 0;
	while(i <= j){
		if(arr[i] == arr[j]){
			i++, j--;
		} 
		else if(arr[i] < arr[j]){
			arr[i+1] += arr[i];
			i++;
			count++;
		} 
		else{
			arr[j-1] += arr[j];
			j--;
			count++;
		}
	}

	return count;
}

int main(){
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++)
		cin >> arr[i];

	cout << minimumOperations(arr, n);
	return 0;
}