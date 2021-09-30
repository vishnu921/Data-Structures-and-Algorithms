/*
Given two sorted arrays arr1[] of size N and arr2[] of size M. Each array is sorted in non-decreasing order. 
Merge the two arrays into one sorted array in non-decreasing order without using any extra space.
*/

#include <bits/stdc++.h>
using namespace std;

int nextGap(int gp){
    if(gp <= 1) return 0;
    return (gp+1)/2;
}

// time: O((n+m)log(n+m)), space: O(1)
void merge(int arr1[], int arr2[], int n, int m) {
    int i,j,gp = n+m;

    for(gp = nextGap(gp); gp > 0; gp = nextGap(gp)){
        for(i = 0; i + gp < n; i++){
            if(arr1[i] > arr1[i+gp]) swap(arr1[i], arr1[i+gp]);
        }
        
        for(j = gp>n?gp-n:0; i < n && j < m; i++, j++){
            if(arr1[i] > arr2[j]) swap(arr1[i], arr2[j]);
        }
        
        if(j < m){
            for(j = 0; j + gp < m; j++){
                if(arr2[j] > arr2[j+gp]) swap(arr2[j], arr2[j+gp]);
            }
        }
    }
}

int main(){
	int n,m;
	cin >> n >> m;
	int arr1[n], arr2[m];
	for(int i = 0; i < n; i++) cin >> arr1[i];
	for(int i = 0; i < m; i++) cin >> arr2[i];

	merge(arr1, arr2, n, m);

	for(int i = 0; i < n; i++){
		cout << arr1[i] << " ";
	}
	for(int i = 0; i < m; i++){
		cout << arr2[i] << " ";
	} cout << endl;
	return 0;
}