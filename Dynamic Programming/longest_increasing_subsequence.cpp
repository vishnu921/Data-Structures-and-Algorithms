/*
Given an array of integers, find the length of the longest (strictly) increasing subsequence from the given array.
*/

#include <bits/stdc++.h>
using namespace std;

int LIS_recursion(int a[], int n, int &ans){
	//base case
	if(n == 1) return 1;

	int res, lis_ending_here = 1;
	//recursively get all LIS ending at a[0] to a[n-2]
	//and if a[i-1] < a[n-1] and if lis_ending_here is less than lis(a[i-1]) then update it
	for(int i = 1; i < n; i++){
		res = LIS_recursion(a, i, ans);
		if(a[i-1] < a[n-1] && res+1 > lis_ending_here){
			lis_ending_here = res+1;
		}
	}

	ans = max(ans, lis_ending_here);

	return lis_ending_here;
}

//Bottom up approach O(n^2)
int LIS_dp(int a[], int n){
	//dp[i] stores length of LIS ending at a[i] 
	int dp[n];
	//initialise with base case
	dp[0] = 1;

	//fill dp[] in bottom up manner
	//dp[i] = 1+max(dp[j]) where 0 < j < i and a[j] < a[i]
	//else dp[i] = 1
	for(int i = 1; i < n; i++){
		dp[i] = 1;
		for(int j = 0; j < i; j++){
			if(a[j] < a[i] && dp[i] < dp[j]+1){
				dp[i] = dp[j]+1;
			}
		}
	}

	//LIS of array a[] must end at an index(0...n-1) hence
	//length of LIS of a[] is max value in dp[]
	return *max_element(dp, dp+n);
}

//function to return leftmost greater element than key
int ceilIdx(int tail[], int l, int r, int key){
	while(l < r){
		int mid = l+(r-l)/2;
		if(tail[mid] >= key){
			r = mid;
		}
		else l = mid+1;
	}

	return r;
}

int LIS_nlogn(int a[], int n){
	int len = 1;
	//tail[i] stores the smallest element at the end of LIS of length (i+1)
	int tail[n];

	//initialise with base case
	tail[0] = a[0];

	for(int i = 1; i < n; i++){
		//if a[i] is the largest value till now that means length of LIS so far is increased
		//store a[i] at tail[len] and increase len
		if(a[i] > tail[len-1]){
			tail[len] = a[i];
			len++;
		}
		//else find the leftmost greater element than a[i] 
		//and replace it with a[i] in tail[] array
		else{
			int index = ceilIdx(tail, 0, len-1, a[i]);
			tail[index] = a[i];
		}
	}

	// cout << "tail: ";
	// for(int i = 0; i < len; i++){
	// 	cout << tail[i] << " ";
	// }
	// cout << "\n";
	return len;
}

int main(){
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++) cin >> a[i];
	int ans = 0;
	LIS_recursion(a, n, ans);
	cout << ans << "\n";
	cout << LIS_dp(a, n) << "\n";
	cout << LIS_nlogn(a, n) << "\n";
	return 0;
}