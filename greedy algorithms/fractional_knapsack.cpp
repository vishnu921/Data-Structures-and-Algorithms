/*
Given weights and values of N items, we need to put these items in a knapsack of capacity W to get 
the maximum total value in the knapsack.
*/
#include <bits/stdc++.h>
using namespace std;

struct Item{
	int val;
	int weight;
};

bool compare(Item a, Item b){
	return (a.val*b.weight > b.val*a.weight);
}

double fractionalKnapsack(Item arr[], int n, int w){
	//sort arr[] based on value/weight ratio in descending order
	sort(arr, arr+n, compare);

	//result to store final value in the knapsack
	double res = 0;
	//start with highest value/weight ratio and add till w = 0
	for(int i = 0; i < n; i++){
		//if w > current weight add whole item with its value
		if(w > arr[i].weight){
			w = w-arr[i].weight;
			res += arr[i].val;
		}
		//if w < current weight take the amount that can be added
		else{
			res += arr[i].val*(1.0*w/arr[i].weight);
			w = 0;
			break;
		}
	}
	return res;
}

int main(){
	int n, w;
	cin >> n >> w;
	Item arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i].val >> arr[i].weight;
	}

	cout << fractionalKnapsack(arr, n, w) << endl;
	return 0;
}