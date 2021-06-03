#include <bits/stdc++.h>
using namespace std;

//quickselect algorithm gives O(n) avg time and O(n2) worst time complextiy
//it is similar to quicksort but we don't sort the entire array
//we stop when pivot element is the kth smallest element
int partition(int a[], int l, int r){
	int pivot = a[r];
	int i = l-1;
	for(int j = l; j < r; j++){
		if(a[j] <= pivot){
			i++;
			swap(a[i],a[j]);
		}
	}
	swap(a[i+1], a[r]);
	//i is the position of pivot in the sorted array
	return i+1;
}

int kthsmallest_quickSelect(int a[], int l, int r, int k){
	if(k > 0 && k <= r-l+1){
		//pos is the index of pivot element in the sorted array
		int pos = partition(a,l,r);

		//if pivot element is itself the kth smallest element return it
		if(pos-l == k-1) return a[pos];

		//if pos of pivot element is greater than k, that means kth smallest is present in left part
		if(pos-l > k-1) return kthsmallest_quickSelect(a, l, pos-1, k);

		//else kth smallest is present in the right part
		return kthsmallest_quickSelect(a, pos+1, r, k-pos+l-1);
	}
	return INT_MAX;
}

int main(){
	int n,k;
	cin >> n >> k;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	cout << kthsmallest_quickSelect(a, 0, n-1, k) << endl;
	return 0;
}