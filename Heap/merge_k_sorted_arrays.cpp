/*
Given k sorted arrays of possibly different sizes, merge them and print the sorted output.
*/

#include <bits/stdc++.h>
using namespace std;
typedef pair<int,pair<int,int>> ppi;


//time complexity O(nlogk);
vector<int> mergeKsorted(vector<vector<int>> a, int k){
	priority_queue<ppi, vector<ppi>, greater<ppi>> pq;
	vector<int> res;

	//create a min heap and push 1st element of all array into the heap
	for(int i = 0; i < k; i++){
		pq.push(make_pair(a[i][0], make_pair(i,0)));
	}

	//repeat below 2 steps until pq becomees empty
	//extract min element from the heap and store it in the result array
	//push next element from the array from which the element is extracted. if there is no 
	//element in the array left then do nothing
	while(!pq.empty()){
		ppi cur = pq.top();
		pq.pop();

		res.push_back(cur.first);

		int i = cur.second.first;
		int j = cur.second.second;

		if(j+1 < a[i].size()){
			pq.push(make_pair(a[i][j+1], make_pair(i,j+1)));
		}
	}

	return res;
}

int main(){
	int k;
	cin >> k;
	vector<vector<int>> a(k);
	for(int i = 0; i < k; i++){
		int x;
		while(1){
			cin >> x;
			if(x == -1) break;
			a[i].push_back(x);
		}
	}

	for(int i = 0; i < k; i++){
		for(int j = 0; j < a[i].size(); j++){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	vector<int> res = mergeKsorted(a, k);
	for(int i = 0; i < res.size(); i++){
		cout << res[i] << " ";
	}
	cout << "\n";
	return 0;
}