#include <bits/stdc++.h>
using namespace std;


/*
let an array be a[0.....ax......ay....an];
let sum of subarray a[0...ax] = x;
let sum of subarray a[0....ay] = y;
let sum of subarray a[ax+1.....ay] = 0;
now if the sum of this subarray is 0 that means x + 0 = y
so the algorithm to solve:
calculate sum from left to right
	if this sum is previously encountered that means zero sum subarray exists
	hence return true
	else insert each sum to hash
if no zero sum subarray found return false
*/
bool subArrayExists(int arr[], int n)
{
    int sum = 0;
    unordered_set<int> hash;
    for(int i = 0; i < n; i++){
        sum += arr[i];
        if(sum == 0 || hash.find(sum) != hash.end()) return true;
        hash.insert(sum);
    }
    
    return false;
}

int main(){
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}

	if(subArrayExists(arr,n)){
		cout << "YES\n";
	} else{
		cout << "NO\n";
	}
	return 0;
}