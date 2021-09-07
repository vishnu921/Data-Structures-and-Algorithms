/*
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.
*/

#include <bits/stdc++.h>
using namespace std;

//O(n) and O(1) solution without changing array
//we use cycle detection approach since each element in 
//the array is in range [1,n]
int findDuplicate(int a[], int n){
	int slow = a[0];
	int fast = a[0];
	do{
		slow = a[slow];
		fast = a[a[fast]];
	}while(slow != fast);

	slow = a[0];

	while(slow != fast){
		slow = a[slow];
		fast = a[fast];
	}

	return fast;
}

int main(){
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	cout << findDuplicate(a, n) << "\n";
	return 0;
}