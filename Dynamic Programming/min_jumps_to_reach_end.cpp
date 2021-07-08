/*
Given an array of N integers arr[] where each element represents the max number of steps that can be made forward 
from that element. Find the minimum number of jumps to reach the end of the array (starting from the first element). 
If an element is 0, then you cannot move through that element. 
*/
#include <bits/stdc++.h>
using namespace std;

//tabulation approach O(n^2)
int minJumps_dp(int a[], int n){
	//dp[i] stores minimum jumps needed to reach a[i] from a[0];
	int dp[n];

	//base case
	dp[0] = 0;

	//find minimum jumps to reach each index and fill the dp[] array
	//in bottom up manner
	for(int i = 1; i < n; i++){
		dp[i] = INT_MAX;
		for(int j = 0; j < i; j++){
			//if a[j] is reachable itself and a[i] is reachable from a[j] update dp[i]
			if(dp[j] != INT_MAX && a[j]+j >= i){
				if(dp[j]+1 < dp[i]){
					dp[i] = dp[j]+1;
				}
				break;
			}
		}
	}

	if(dp[n-1] == INT_MAX) return -1;
	return dp[n-1];
}

//O(n) approach
int minJumps_efficient(int a[], int n){
	if(n <= 0) return 0;
	//return -1 if not possible to jump from a[i]
	if(a[0] == 0) return -1;

	//maxReach stores all time maximal reachable
	//index in the array
	int maxReach = a[0];

	//stores how many steps we ca still take
	int step = a[0];

	//stores no. of jumps needed to reach that
	//maximal reachable position
	int jump = 1;

	for(int i = 1; i < n; i++){
		//if a[n-1] reached return jumps
		if(i == n-1) return jump;

		//update maxReach
		maxReach = max(maxReach, a[i]+i);
		//decrease step to get to the a[i]
		step--;

		if(step == 0){
			//if no further steps left
			//we increase the jumps used
			jump++;
			
			//if current index or lesser is maximal reachable index
			//then we cannot go further hence return -1
			if(i >= maxReach) return -1;

			//else update step to number of steps
			//to reach maxReach from i
			step = maxReach - i;
		}
	}

	return -1;
}

int main(){
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	cout << minJumps_dp(a, n) << "\n";
	cout << minJumps_efficient(a, n) << "\n";
	return 0;
}