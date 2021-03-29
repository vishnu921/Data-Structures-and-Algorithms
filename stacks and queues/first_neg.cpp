/*
Given an array and a positive integer k, find the first negative integer for each and every window(contiguous subarray) of size k
*/
#include <bits/stdc++.h>
using namespace std;


/*
in this problem we use queue data structure 
this queue will store the index of the negetive integers only of the current window of size k
and remove the element from it when they are out of window
*/
void printfirstnegetive(int a[], int n, int k){
	int i;
	queue<int> q;
	//store the indexes of all the negetive integers in the first window of size k
	for(i = 0; i < k; i++)
	{
		if(a[i] < 0)
			q.push(i);
	}

	while(i < n){
		//print the first negetive integer of the previous k sized window
		if(!q.empty())
			cout << a[q.front()] << " ";
		else
			cout << 0 << " ";

		//remove the elements which are out of the window
		while(!q.empty() && q.front() < (i-k+1))
			q.pop();

		//add the negetive integers encountered at the rear of the queue
		if(a[i] < 0)
			q.push(i);
		i++;
	}

	//print for the last window
	if(!q.empty())
		cout << a[q.front()] << "\n";
	else
		cout << 0 << "\n";
}

int main(){
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int k;
	cin >> k;
	printfirstnegetive(a, n, k);
	return 0;
}