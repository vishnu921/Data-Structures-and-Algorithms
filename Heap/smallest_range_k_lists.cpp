/*
Given K sorted lists of integers of size N each, find the smallest range that includes at least one element from 
each of the K lists. If more than one such range's are found, find the first such range found.
*/

#include <bits/stdc++.h>
using namespace std;

struct compare{
	bool operator()(vector<int> a, vector<int> b){
		return (a[0] > b[0]);
	}
};

pair<int,int> smallestRange(vector<vector<int>> a, int n, int k){
	int range = INT_MAX;
	int min = INT_MAX;
	int max = INT_MIN;
	int start, end;

	//min heap that stores a vector of 3 elements
	//v[0] stores value, v[1] stores list index, v[2] stores index of the next element in its list
	priority_queue<vector<int>, vector<vector<int>>, compare> pq;

	//stores first element of each of the k lists in min heap
	for(int i = 0; i < k; i++){
		pq.push({a[i][0], i, 1});

		//store the maximum element
		if(a[i][0] > max) max = a[i][0];
	}

	//extract minimum element from the minheap and store next element from its list
	while(1){
		vector<int> cur = pq.top();
		//current minimum element
		min = cur[0];

		//update range
		if(range > max-min+1){
			range = max-min+1;
			start = min;
			end = max;
		}

		//find the next element which will replace the root of minheap
		if(cur[2] < n){
			cur[0] = a[cur[1]][cur[2]];
			cur[2]++;

			//update max
			if(cur[0] > max) max = cur[0];
		}
		//if any list ends break the loop because we need at least one element from every list
		else break;

		pq.pop();
		pq.push(cur);
	}
	

	return make_pair(start, end);
}

int main(){
	int n,k;
	cin >> n >> k;
	vector<vector<int>> a(k);

	for(int i = 0; i < k; i++){
		for(int j = 0; j < n; j++){
			int x;
			cin >> x;
			a[i].push_back(x);
		}
	}

	pair<int,int> p = smallestRange(a, n, k);

	cout << p.first << " " << p.second << "\n";
	return 0;
}