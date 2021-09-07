/*
Given an array of size n and a range [a, b]. The task is to partition the array around the range such 
that array is divided into three parts.
1) All elements smaller than a come first.
2) All elements in range a to b come next.
3) All elements greater than b appear in the end.
The individual elements of three sets can appear in any order. You are required to return the modified array.
*/

#include <bits/stdc++.h>
using namespace std;

//O(N) solution. This is just a variation of DNF sort
void threeWayPartition(int arr[], int n,int a, int b)
{
    int l = 0, mid = 0, h = n-1;
    while(mid <= h){
        if(arr[mid] < a){
            swap(arr[l], arr[mid]);
            l++; mid++;
        } 
        else if(arr[mid] > b){
            swap(arr[mid], arr[h]);
            h--;
        } 
        else{
            mid++;
        }
    }
}

int main(){
	int n,a,b;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	cout << "Enter range: ";
	cin >> a >> b;

	threeWayPartition(arr, n, a, b);
	for(int i = 0; i < n; i++){
		cout << arr[i] << " ";
	} cout << endl;
	return 0;
}