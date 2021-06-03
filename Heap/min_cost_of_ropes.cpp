/*
There are given N ropes of different lengths, we need to connect these ropes into one rope. 
The cost to connect two ropes is equal to sum of their lengths. The task is to connect the ropes with minimum cost.
*/

#include <bits/stdc++.h>
using namespace std;

int minCost(int arr[], int n) {
        // Your code here
        priority_queue<int, vector<int>, greater<int>> pq(arr,arr+n);

        int cost = 0;
        while(pq.size() != 1){
            int a = pq.top(); pq.pop();
            int b = pq.top(); pq.pop();
            
            cost += (a+b);
            pq.push(a+b);
        }
        return cost;
    }

int main(){
	int n;
	cin >> n;
	int a[n];
	for(int i=0; i < n; i++){
		cin >> a[i];
	}

	cout << minCost(a, n) << "\n";
	return 0;
}