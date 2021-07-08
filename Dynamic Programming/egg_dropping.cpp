/*
Suppose you have N eggs and you want to determine from which floor in a K-floor building you can drop an 
egg such that it doesn't break. You have to determine the minimum number of attempts you need in order find 
the critical floor in the worst case while using the best strategy.There are few rules given below. 

    An egg that survives a fall can be used again.
    A broken egg must be discarded.
    The effect of a fall is the same for all eggs.
    If the egg doesn't break at a certain floor, it will not break at any floor below.
    If the eggs breaks at a certain floor, it will break at any floor above.

*/

#include <bits/stdc++.h>
using namespace std;

//top down (recursion + memoisation)
int dp[101][201];
int eggDrop_topDown(int e, int f){
	//base cases
	//if there is no floor then attempts = 0
	//if there is only 1 foor then attempts = 1
	if(f == 1 || f == 0) return f;

	//if there is only one egg then min. attempts is number of floors
	if(e == 1) return f;

	if(dp[e][f] != -1) return dp[e][f];

	int min = INT_MAX;
	for(int k = 1; k <= f; k++){
		/*
		there are 2 cases in each floor
		1. if the egg breaks after throwing from kth floor then that means it will break from the above floors
		   also hence no need to check above floors and we recur for 1 less egg and lower floors (k-1)
		2. if the doesn't breaks the it will not break from any floor below hence no need to check for
		   below floors and we recur for same eggs and above floors (f-k)

		then we take maximum of both cases and if it is less than min. answer we update min answer.
		*/
		int cur = max(eggDrop_topDown(e-1,k-1), eggDrop_topDown(e, f-k));
		if(cur < min){
			min = cur; 
		}
	}

	dp[e][f] = min + 1;

	return dp[e][f];
}

//bottom up
int eggDrop_bottomUp(int e, int f){
	//dp[i][j] stores min. number of trials needed for i eggs and j floors
	int dp[e+1][f+1];

	//base cases
	//if there is no floor then attempts = 0
	//if there is only 1 foor then attempts = 1
	for(int i = 1; i <= e; i++){
		dp[i][1] = 1;
		dp[i][0] = 0;
	}

	//if number of eggs is only one
	for(int i = 1; i <= f; i++){
		dp[1][i] = i;
	}

	for(int i = 2; i <= e; i++){
		for(int j = 2; j <= f; j++){
			dp[i][j] = INT_MAX;

			for(int k = 1; k <= j; k++){
				int res = 1 + max(dp[i-1][k-1], dp[i][j-k]);
				if(res < dp[i][j]){
					dp[i][j] = res;
				}
			}
		}
	}

	return dp[e][f];
}

int main(){
	int e,f;
	cin >> e >> f;
	memset(dp, -1, sizeof(dp));
	//O(e*f^2) solutions using dp
	cout << eggDrop_topDown(e, f) << "\n";
	cout << eggDrop_bottomUp(e, f) << "\n";
	return 0;
}