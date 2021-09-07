/*
Given an array of n positive integers and a number k. Find the minimum number of swaps required to bring 
all the numbers less than or equal to k together.

Example 1:
Input : arr[ ] = {2, 1, 5, 6, 3} and K = 3
Output : 1

Example 2:
input: arr[] = {4,11,6,5,11,20,19,14,14,2,9,20,11,11,15,1,7,12,19,9} and k = 14
output: 4 
*/

#include <bits/stdc++.h>
using namespace std;

//O(n) and O(1) space
int minSwap(int *arr, int n, int k) {
    int count = 0, unwanted = 0;
    //count the number of elements in the array which are <= k
    //this count will the size of our sliding window
    //now we can group elements <= k anywhere between in the array
    for(int i = 0; i < n; i++){
        if(arr[i] <= k){
            count++;
        }
    }
    
    //count unwanted(element greater than k) in first window
    //this unwanted variable stores number of elements > k
    //that represents that in current window how many elements > k are there in the window
    //which need to be replaced by elements <= k outside the window
    //i.e. it is the number of swaps for current window
    for(int i = 0; i < count; i++){
        if(arr[i] > k){
            unwanted++;
        }
    }
    
    //initialize ans with unwanted
    int ans = unwanted;
    //now we calculate unwanted for each window and minimum unwanted is our answer
    for(int i = 0, j = count; j < n; i++, j++){
        if(arr[i] > k) unwanted--;
        if(arr[j] > k) unwanted++;
        
        ans = min(ans, unwanted);
    }
    
    return ans;
}

int main(){
	int n,k;
	cin >> n >> k;
	int arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}

	cout << "Minimum swaps: " << minSwap(arr, n, k);
	return 0;
}