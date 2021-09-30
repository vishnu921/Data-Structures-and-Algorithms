/*
Given an unsorted array Arr of size N of positive integers. 
One number 'A' from set {1, 2, …N} is missing and one number 'B' occurs twice in array. Find these two numbers.
*/

#include <bits/stdc++.h>
using namespace std;

int *findMissingAndRepeating(int a[], int n){
	int repeated = 0, missing = 0;
	for(int i = 0; i < n; i++){
		int idx = abs(a[i])-1;

		if(a[idx] > 0){

			a[idx] = (-1)*a[idx];

		} else{
			repeated = idx+1;
		}
	}

	for(int i = 0; i < n; i++){
		if(a[i] > 0){
			missing = i+1;
			break;
		}
	}

	return new int[2]{missing, repeated};
}

int main(){
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++) cin >> a[i];

	int *mandr = findMissingAndRepeating(a, n);
	cout << "Missing: " << mandr[0];
	cout << "\nRepeated: " << mandr[1];
	return 0;
}