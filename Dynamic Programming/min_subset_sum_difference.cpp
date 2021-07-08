/*
Given an integer array arr of size N, the task is to divide it into two sets S1 and S2 such that the 
absolute difference between their sums is minimum and find the minimum difference

------Recursion solution for this problem--------
int minDiff(int a[], int n, int s1, int sum){
	if(n == 0){
		return abs(sum-2*s1);
	}

	return min(minDiff(a, n-1, s1+a[n-1], sum-a[n-1]), minDiff(a, n-1, s1, sum));
}
*/
#include <bits/stdc++.h>
using namespace std;

//O(n*sum)
int minDifference_dp(int a[], int n){
	int sum = 0;
	for(int i = 0; i < n; i++){
		sum += a[i];
	}

	//dp[i] = true if there exists a subset with sum = i
	bool dp[sum+1] = {};
	//base case: subset with sum = 0 always exists(empty set)
	dp[0] = true;

	//fill the dp[] array in bottom up manner
	for(int i = 0; i < n; i++){
		for(int j = sum; j >= a[i]; j--){
			if(dp[j-a[i]] == true){
				dp[j] = true;
			}
		}
	}

	//let s1 & s2 be sum of subsets
	//s2 = sum - s1
	//we have to minimum abs(s2-s1)
	//i.e abs(s2 - s1) = abs(sum - 2*s1)
	//now to make abs(sum-2*s1) minimum
	//we need s1 close to sum/2
	int min_diff;
	for(int i = sum/2; i>=0; i--){
		//if subset with sum i exists in array a[]
		//chose the first subset sum from right to left in 0....sum/2
		//and calculate there difference
		if(dp[i] == true){
			min_diff = sum-2*i;
			break;
		}
	}

	return min_diff;
}

int main(){
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	cout << minDifference_dp(a, n) << "\n";
	return 0;
}