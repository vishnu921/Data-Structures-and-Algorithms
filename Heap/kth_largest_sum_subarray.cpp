/*
Given an array of integers. Write a program to find the K-th largest sum of contiguous subarray within the 
array of numbers which has negative and positive numbers.
*/

#include <bits/stdc++.h>
using namespace std;

//O(n^2logk)
int kthLargestSubarray(int a[], int n, int k){
	//creater a prefix sum subarray
	//sum[i] stores sum of subarray ending at ith index;
	int sum[n];
	sum[0] = a[0];
	for(int i = 1; i < n; i++){
		sum[i] = sum[i-1]+a[i];
	}

	//min heap to store k largest sum subarray
	priority_queue<int, vector<int>, greater<int>> pq;

	for(int i = 0; i < n; i++){
		for(int j = i; j < n; j++){
			//sum of contiguous array from index i to j
			int x;
			if(i == 0) x = sum[j];
			else x = sum[j]-sum[i-1];

			//if pq has less than k elements push the sum
			if(pq.size() < k){
				pq.push(x);
			}
			//if sum of subarray from i to j is less than the top element
			//then ignore because we have already k sum that are larger than it, hence it cannot be in k largest sums
			//if x > pq.top(), pop an element out and push x 
			else if(x > pq.top()){
				pq.pop();
				pq.push(x);
			}
		}
	}

	//top element of the min heap is the kth largest sum subarray
	return pq.top();
}

int main(){
	int n, k;
	cin >> n >> k;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	cout << kthLargestSubarray(a, n, k) << endl;
	return 0;
}