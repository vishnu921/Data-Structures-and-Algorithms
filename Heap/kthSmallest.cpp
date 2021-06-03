/*
Given an array and a number k where k is smaller than the size of the array, we need to find the k’th
smallest element in the given array. It is given that all array elements are distinct.
*/
#include <bits/stdc++.h>
using namespace std;

//time complexity O(klogk + (n-k)logk) = O(nlogk)
int kthsmallest_maxheap(int a[], int n, int k){
	priority_queue<int> pq;
	//build maxheap of first k elements
	for(int i = 0; i < k; i++){
		pq.push(a[i]);
	}

	//for next n-k elements do the following
	//if a[i] >= pq.top(), ignore it because we have already k smaller elements in the max heap
	// if a[i] < pq.top(), pop() one element from pq and push a[i]
	for(int i = k; i < n; i++){
		if(a[i] < pq.top()){
			pq.pop();
			pq.push(a[i]);
		}
	}
	return pq.top();
}

int main(){
	int n,k;
	cin >> n >> k;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	cout << kthsmallest_maxheap(a, n, k) << endl;
	return 0;
}