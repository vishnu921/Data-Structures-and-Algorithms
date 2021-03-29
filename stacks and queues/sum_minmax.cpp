/*
Given an array of both positive and negative integers, the task is to compute sum of minimum and maximum elements of all sub-array of size k.
*/
#include <bits/stdc++.h>
using namespace std;

void printSumMinMaxk(int a[], int n, int k){
	int i;
	int mini = 0,maxi = 0;
	queue<int> mn,mx;
	for(i = 1; i < k; i++)
	{
		if(a[mini] > a[i])
			mini = i;

		if(a[maxi] < a[i])
			maxi = i;
	}
	mn.push(mini);
	mx.push(maxi);
	while(i < n){
		cout << a[mn.front()] + a[mx.front()] << " ";

		while(!mn.empty() && mn.front() < (i-k+1))
			mn.pop();

		while(!mx.empty() && mx.front() < (i-k+1))
			mx.pop();

		if(a[mini] >= a[i]){
			mini = i;
			mn.push(i);
		}
		if(a[maxi] <= a[i])
		{
			maxi = i;
			mx.push(i);
		}
		i++;
	}
	cout << a[mn.front()] + a[mx.front()] << endl;
}

int main(){
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++)
		cin >> a[i];
	int k;
	cin >> k;
	printSumMinMaxk(a, n, k);
	return 0;
}