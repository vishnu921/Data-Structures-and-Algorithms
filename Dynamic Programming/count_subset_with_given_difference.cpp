/*
count subset with given sum difference
similar question : Target sum (leetcode)
You are given an integer array nums and an integer target.

You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer 
in nums and then concatenate all the integers.

    For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate
    them to build the expression "+2-1".

Return the number of different expressions that you can build, which evaluates to target.
*/

#include <bits/stdc++.h>
using namespace std;

int countSubsetwithSum(int a[], int n, int sum){
	//dp[i] stores number of subsets with sum = i
	int dp[sum+1];
	dp[0] = 1;

	for(int i = 0; i < n; i++){
		for(int j = sum; j >= a[i]; j--){
			dp[j] += dp[j-a[i]];
		}
	}

	return dp[sum];
}

int FindTargetSumWays(int a[], int n, int target){
	int sum = 0;
	for(int i = 0; i < n; i++){
		sum += a[i];
	}

	/*
	let s1 & s2 be 2 subset sums
	we need to find number of ways when abs(s2-s1) = target
	s2 = sum-s1 => target = (sum-2*s1)
	we need to find s1 = (sum-target)/2
	if sum < target then there is no way to get diff = target
	and if (sum-target) is odd there is no way
	*/
	if(sum < target || (sum+target)&1) return 0;

	//else find s1 = (sum-target)/2
	int s1 = (sum-target) >> 1;
	return countSubsetwithSum(a, n, s1);
}

int main(){
	int n, target;
	cin >> n >> target;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	cout << FindTargetSumWays(a, n, target) << "\n";
	return 0;
}