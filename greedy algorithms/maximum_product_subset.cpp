/*
Given an array a, we have to find maximum product possible with the subset of elements present in the array. 
The maximum product can be single element also.
*/
#include <bits/stdc++.h>
using namespace std;

int maxproductsubset(int a[], int n){
	//zero counts number of zeroes
	int zero = 0;
	//neg counts number of negetive integers
	int neg = 0;
	//max_neg stores negetive number with smallest absolute value
	int max_neg = INT_MIN;
	int product = 1;
	for(int i = 0; i < n; i++){
		
		if(a[i] == 0){
			zero++;
			continue;
		}

		if(a[i] < 0){
			neg++;
			max_neg = max(a[i], max_neg);
		}

		product *= a[i];
	}

	if(zero == n) return 0;
	
	if(neg&1){
		if(neg == 1 && zero == n-1) return 0;
		product = product/max_neg;
	}

	return product;
}

int main(){
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	cout << maxproductsubset(a, n) << endl;
	return 0;
}