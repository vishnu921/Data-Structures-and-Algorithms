#include <bits/stdc++.h>
using namespace std;

void DNFSort(int arr[], int n){
	int low = 0, mid = 0, high = n-1;

	/*
	Here we ensure that each element in range
	arr[0....(low-1)] = 0
	arr[low....(mid-1)] = 1
	arr[(high+1)....n-1] = 2
	*/
	while(mid <= high){
		if(arr[mid] == 0){
			swap(arr[low], arr[mid]);
			low++; mid++;
		} else if(arr[mid] == 1){
			mid++;
		} else{
			swap(arr[mid], arr[high]);
			high--;
		}
	}
}

int main(){
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	DNFSort(arr, n);
	for (int i = 0; i < n; ++i){
		cout << arr[i] << " ";
	} cout << endl;
	return 0;
}