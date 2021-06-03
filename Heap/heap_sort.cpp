/*
steps to perform heap sort
-> Build heap by heapifying all the internal nodes of the array
-> Run a loop from i = n-1 to i = 1 and do the following for each step
   -> swap root node(a[0]) with the last node(a[i])
   -> heapify the root node for array of size i
*/

#include <bits/stdc++.h>
using namespace std;

//heapify index i
void heapify(int a[], int n, int i){
	int largest = i;
	int l = 2*i+1;
	int r = 2*i+2;

	//if left child is larger than root
	if(l < n && a[l] > a[i]){
		largest = l;
	}
	//if right child is larger than both left child and root
	if(r < n && a[r] > a[largest]){
		largest = r;
	}

	//if largest is not the root
	if(largest != i){
		swap(a[i], a[largest]);

		//recursively heapify the affected sub-tree
		heapify(a, n, largest);
	}
}

void heapSort(int a[], int n){

	//build heap in O(n) time complexity
	for(int i = n/2-1; i >= 0; i--){
		heapify(a, n, i);
	}

	for(int i = n-1; i > 0; i--){
		//extract max and put it at ith position(i from right to left)
		swap(a[0], a[i]);

		heapify(a, i, 0);
	}
}

int main(){
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	heapSort(a, n);
	for(int i = 0; i < n; i++){
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}