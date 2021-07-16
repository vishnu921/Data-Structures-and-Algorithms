/*
Implement the next permutation, which rearranges the list of numbers into Lexicographically 
next greater permutation of list of numbers. If such arrangement is not possible, it must 
be rearranged to the lowest possible order i.e. sorted in an ascending order. You are given 
an list of numbers arr[ ] of size N.
*/

#include <bits/stdc++.h>
using namespace std;

void nextPermutation(int a[], int n){

	//step 1: first we find first element a[i] from R to L
	//such that a[i] < a[i+1] for all 0 <= i < n-1
	int i = n-2;
	while(i >= 0){
		if(a[i] < a[i+1]) break;
		i--;
	}

	//now if no such index is found then the input array is in 
	//descending order and we we return its reverse
	if(i < 0){
		reverse(a, a+n);
		return;
	}

	//else step 2: we find first element a[j] from R to L
	//such that a[j] > a[i] for all i < j < n
	int j = n-1;
	while(j > i){
		if(a[j] > a[i]) break;
		j++;
	}

	swap(a[i], a[j]);
	reverse(a+i+1, a+n);
}

int main(){
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n ;i++){
		cin >> a[i];
	}

	nextPermutation(a, n);

	for(int i = 0; i < n; i++){
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}