/*
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the 
elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums, int n) {
    vector<int> res(n, 1);
    int preProd = 1;
    for(int i = 0; i < n; i++){
        res[i] = preProd;                 // res[i] stores product of elements in array nums[0....(i-1)]
        preProd *= nums[i];
    }
    
    preProd = 1;
    for(int i = n-1; i >= 0; i--){
        res[i] *= preProd;
        preProd *= nums[i];            // preprod = product of elements in array nums[(i+1)...(n-1)]
    }
    
    return res;
}

int main(){
	int n;
	cin >> n;
	vector<int> nums(n);
	for(int i = 0; i < n; i++){
		cin >> nums[i];
	}

	vector<int> res = productExceptSelf(nums, n);
	for(int i = 0; i < n; i++){
		cout << res[i] << " ";
	}
	return 0;
}