/*
Given a non negative array, find the number of subsequences having product smaller than K.
Examples: 
 

Input : [1, 2, 3, 4] 
        k = 10
Output :11 
The subsequences are {1}, {2}, {3}, {4}, 
{1, 2}, {1, 3}, {1, 4}, {2, 3}, {2, 4}, 
{1, 2, 3}, {1, 2, 4}

Input  : [4, 8, 7, 2] 
         k = 50
Output : 9
*/

#include <bits/stdc++.h>
using namespace std;

int CountSubsequence(int a[], int n, int k){
	//dp[i][j] stores count of subsequence with product less than i
	//using first j element of the array
	int dp[k + 1][n + 1];
    memset(dp, 0, sizeof(dp));
 
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= n; j++) {
    
            // number of subsequence using j-1 terms
            dp[i][j] = dp[i][j - 1];
   
            // if arr[j-1] > i it will surely make product greater
            // thus it won't contribute then
            if (a[j - 1] <= i && a[j - 1] > 0)
                // number of subsequence using 1 to j-1 terms
                // and j-th term
                dp[i][j] += dp[i/a[j-1]][j-1] + 1;
        }
    }

    for(int i = 0; i <= k; i++){
    	for(int j = 0; j <= n; j++){
    		cout << dp[i][j] << " ";
    	}
    	cout << endl;
    }
    return dp[k][n];
}

int main(){
	int n, k;
	cin >> n >> k;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	cout << CountSubsequence(a, n, k) << "\n";
	return 0;
}