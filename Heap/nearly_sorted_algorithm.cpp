/*
Given an array of n elements, where each element is at most k away from its target position. 
The task is to print array in sorted form.
*/

#include <bits/stdc++.h>
using namespace std;

//O(nlogk)
//we use a minheap of size k
void solve(int a[], int n, int k){
	priority_queue<int,vector<int>,greater<int>> pq;

	int j = 0;
	for(int i = 0; i < n; i++){
		pq.push(a[i]);
		if(pq.size() > k){
			a[j++] = pq.top();
			pq.pop();
		}
	}

	while(!pq.empty()){
		a[j++] = pq.top();
		pq.pop();
	}
}

int main(){
	int n,k;
	cin >> n >> k;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	solve(a,n,k);

	for(int i = 0; i < n; i++){
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}