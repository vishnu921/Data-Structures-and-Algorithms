//Given an array arr[] of size N and an integer K. Find the maximum for each and every contiguous subarray of size k.
#include <bits/stdc++.h>
using namespace std;

vector<int> max_of_subarrays(int a[], int n, int k){
	vector<int> res;
	deque<int> q;
	int i;
	for(i = 0; i < k; i++){
		while(!q.empty() && a[i] >= a[q.back()])
			q.pop_back();
		q.push_back(i);
	}

	while(i < n){
		res.push_back(a[q.front()]);

		while(!q.empty() && q.front() < (i-k+1))
			q.pop_front();

		while(!q.empty() && a[i] >= a[q.back()])
			q.pop_back();

		q.push_back(i);
		i++;
	}
	res.push_back(a[q.front()]);
	return res;
}

int main(){
	int n,k;
	cin >> n >> k;
	int a[n];
	for(int i = 0; i < n; i++)
		cin >> a[i];

	vector<int> res = max_of_subarrays(a,n,k);
	for(int i = 0; i < res.size(); i++)
	{
		cout << res[i] << " ";
	}
	cout << endl;
	return 0;
}