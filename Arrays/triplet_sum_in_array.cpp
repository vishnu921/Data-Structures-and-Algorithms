/*
Given an array arr of size n and an integer X. Find if there's a triplet in the array which 
sums up to the given integer X.


Example 1:

Input:
n = 6, X = 13
arr[] = [1 4 45 6 10 8]
Output:
1
*/
#include <bits/stdc++.h>
using namespace std;

//O(n^2) solution
bool tripletSum(int a[], int n, int x)
{
    sort(a, a+n);
    for(int i = 0; i < n-1; i++){
        int l = i+1, r = n-1;
        while(l < r){
            int sum = a[i]+a[l]+a[r];
            if(sum == x) return true;
            if(sum < x) l++;
            else r--;
        }
    }
    return false;
}

int main(){
	int n,x;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	cout << "Enter sum: ";
	cin >> x;
	if(tripletSum(arr, n, x)){
		cout << "Triplet present\n";
	} else{
		cout << "Triplet not present\n";
	}
	return 0;
}