/*
There are given N ropes of different lengths, we need to connect these ropes into one rope. The cost to 
connect two ropes is equal to sum of their lengths. The task is to connect the ropes with minimum cost.
*/
#include <bits/stdc++.h>
using namespace std;

struct compare{
	bool operator()(int a, int b){
		return (a > b);
	}
};

int minimum_cost(int a[], int n){
	//minheap of lengths of ropes
	priority_queue<int, vector<int>, compare> pq;

	for(int i = 0; i < n; i++){
		pq.push(a[i]);
	}

	int cost = 0;
	//iterate until pq.size() is not equal to 1
	while(pq.size() != 1){
		//extract two minimum length ropes from the minheap
		int r1 = pq.top();
		pq.pop();
		int r2 = pq.top();
		pq.pop();

		//add cost of their connection
		cost += (r1+r2);

		//push the sum of length as a new rope into minheap
		pq.push(r1+r2);
	}

	return cost;
}

int main(){
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	cout << minimum_cost(a, n) << endl;
	return 0;
}