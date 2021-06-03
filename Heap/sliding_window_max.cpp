/*
Given an array and an integer K, find the maximum for each and every contiguous subarray of size k.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> Sliding_Max(int a[], int n, int k){
	//deque to store element which is in current window and greater than all other elements 
	//on its right in the current window
	deque<int> dq;
	vector<int> res;

	for(int i = 0; i < n; i++){
		//pop the element which out of the current window
		if(!dq.empty() && dq.front() == i-k) dq.pop_front();

		//pop all element from back until all the element on left are greater than current element
		while(!dq.empty() && a[dq.back()] < a[i]){
			dq.pop_back();
		}

		//push current element from back
		dq.push_back(i);

		if(i >= k-1) res.push_back(a[dq.front()]);
	}

	return res;
}

int main(){
	int n,k;
	cin >> n >> k;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	vector<int> res = Sliding_Max(a, n, k);
	for(int i = 0; i < res.size(); i++){
		cout << res[i] << " ";
	}
	cout << endl;
	return 0;
}