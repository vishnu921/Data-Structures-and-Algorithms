/*
Given an integer N denoting the Length of a line segment. You need to cut the line segment in such a way 
that the cut length of a line segment each time is either x , y or z. Here x, y, and z are integers.
After performing all the cut operations, your total number of cut segments must be maximum.
*/

#include <bits/stdc++.h>
using namespace std;

//top down (recursion + memoisation)
int dp[10001];
int helper(int n, int x, int y, int z){
	//base case
	//1. if n = 0 maximum cuts = 1;
	//2. if n < 0  no possible ans so return smallest possible value i.e INT_MIN
    if(n == 0) return 0;
    if(n < 0) return INT_MIN;
    
    //using memoised solutions
    if(dp[n] != -1) return dp[n];
    
    //check for every cut(x, y, z) and return their maximum
    int inx = helper(n-x, x, y, z);
    int iny = helper(n-y, x, y, z);
    int inz = helper(n-z, x, y, z);
    
    dp[n] = 1+max(inx, max(iny, inz));
    
    return dp[n];
}
int maximizeCut_topDown(int n, int x, int y, int z){
	memset(dp, -1, sizeof(dp));
	int ans = helper(n, x, y, z);

	if(ans < 0) return 0;
	return ans;
}

//bottom up
int maximizeCut_BottomUP(int n, int x, int y, int z){
	int dp[n+1];       //dp[i] stores maximum cuts for length i
	dp[0] = 0;

	for(int i = 1; i <= n; i++){
		dp[i] = -1;
		if(i >= x){
			dp[i] = max(dp[i], dp[i-x]);
		}

		if(i >= y){
			dp[i] = max(dp[i], dp[i-y]);
		}

		if(i >= z){
			dp[i] = max(dp[i], dp[i-z]);
		}
		//address current cut
		if(dp[i] != -1) dp[i]++;
	}

	if(dp[n] < 0) return 0;
	return dp[n];
}



int main(){
	int n, x, y, z;
	cin >> n >> x >> y >> z;
	cout << maximizeCut_topDown(n, x, y, z) << "\n";
	cout << maximizeCut_BottomUP(n, x, y, z) << "\n";
	return 0;
}