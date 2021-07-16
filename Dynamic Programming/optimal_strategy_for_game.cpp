/*
Consider a row of n coins of values v1 . . . vn, where n is even. We play a game against an opponent by 
alternating turns. In each turn, a player selects either the first or last coin from the row, removes it 
from the row permanently, and receives the value of the coin. Determine the maximum possible amount of 
money we can definitely win if we move first.

Note: Both the players are playing optimally.
*/

#include <bits/stdc++.h>
using namespace std;

//top down approach O(n^2)
int dp[100][100];
int solve(int a[], int i, int j){
	//base cases
	//if only one element is present
	if(i == j) return a[i];
	//if empty return 0
	if(i > j) return 0;

	//using memoised solution of subproblems
	if(dp[i][j] != -1) return dp[i][j];

	/*
	At every turn a player has 2 choices
	1. choose a[i] coin & get min of solve(i+2, j) and solve(i+1, j-1)
	2. choose a[j] coin & get min of solve(i, j-2) and solve(i+1, j-1)
	   current player get min because in the next turn another player has 2 choices 
	   choose (i+1)th coin or choose jth coin he will take maximum of both choices

	*/
	int c1 = a[i] + min(solve(a, i+2, j), solve(a, i+1, j-1));
	int c2 = a[j] + min(solve(a, i, j-2), solve(a, i+1, j-1));

	return dp[i][j] = max(c1, c2);
}

int OptimalStragtegy_topDown(int a[], int n){
	memset(dp, -1, sizeof(dp));
	return solve(a, 0, n-1);
}


//bottom up approach
int OptimalStragtegy_BottomUp(int a[], int n){

	//dp[i][j] stores maximum possible win amount using a[i.....j] coins
    int dp[n][n];
    
    //fill the dp[][] matrix in bottom up manner using gap method
    //to traverse matrix diagonally
    for(int gap = 0; gap < n; gap++){
        for(int i = 0, j = gap; j < n; i++, j++){
            if(gap == 0){
                dp[i][j] = a[i];
            }
            else if(gap == 1){
                dp[i][j] = max(a[i], a[j]);
            }
            else{
                int c1 = a[i] + min(dp[i+2][j], dp[i+1][j-1]);
                int c2 = a[j] + min(dp[i][j-2], dp[i+1][j-1]);
                
                dp[i][j] = max(c1, c2);
            }
        }
    }
    
    return dp[0][n-1];
}

int main(){
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	cout << OptimalStragtegy_topDown(a, n) << "\n";
	cout << OptimalStragtegy_BottomUp(a, n) << "\n";
	return 0;
}