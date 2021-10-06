/*
Dilpreet wants to paint his dog's home that has n boards with different lengths. The length of ith board is given 
by arr[i] where arr[] is an array of n integers. He hired k painters for this work and each painter takes 1 unit 
time to paint 1 unit of the board. 

The problem is to find the minimum time to get this job done if all painters start together with the constraint that 
any painter will only paint continuous boards, say boards numbered {2,3,4} or only board {1} or nothing but not boards 
{2,4,5}.
*/
#include <bits/stdc++.h>
using namespace std;

bool isPossible(int arr[], int n, int k, long long max_sum){
    int painters = 1;
    long long cur = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] > max_sum) return false;
        
        if(cur + arr[i] > max_sum){
            painters++;
            cur = arr[i];
            
            if(painters > k) return false;
            
        } else{
            cur += arr[i];
        }
    }
    return true;
}

//O(Nlog(sum of lengths))
long long minTime(int arr[], int n, int k)
{
    long long sum = 0;
    for(int i = 0; i < n; i++){
        sum += arr[i];
    }
    
    long long low = 0, high = sum, res = sum;
    while(low <= high){
        long long mid = low + (high-low)/2;
        if(isPossible(arr, n, k, mid)){
            res = mid;
            high = mid-1;
        } else{
            low = mid+1;
        }
    }
    
    return res;
}

int main(){
	int n,k;
	cin >> n >> k;
	int arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}

	cout << minTime(arr, n, k) << "\n";
	return 0;
}