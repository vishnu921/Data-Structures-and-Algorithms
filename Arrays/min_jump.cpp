/*Given an array of integers where each element represents the max number of steps that can be made forward from that element. Write a function to return the minimum number of jumps to reach the end of the array (starting from the first element). If an element is 0, then cannot move through that element.
*/

#include <bits/stdc++.h>
using namespace std;

//This is O(n^2) approach
int dp_approach(int a[], int n)
{
	int dp[n];            //dp[i] stores minimum number of steps required to reach ith position
	dp[0] = 0;                 //initialising dp[0] = 0 because steps rquired to reach 0th pos is 0
	for(int i = 1; i < n; i++) dp[i] = INT_MAX; //initiallize all elements of dp to INT_MAX
	for(int i = 1; i < n; i++)
	{
		for(int j = 0; j < i; j++)
		{
			if(dp[j] != INT_MAX && a[j]+j >= i)            //a[j] + j >= i means is it possible to reach ith pos from jth pos
			{
				if(dp[j] + 1 < dp[i])                 //assign dp[i] to minimum of dp[j] + 1 and dp[i]
					dp[i] = dp[j] + 1;
			}
		}
	}
	if(dp[n-1] != INT_MAX)
		return dp[n-1];
	else
		return -1;
}

//This is a O(n) approach
int fast(int a[], int n)
{
	if(n <= 1) return 0;
	if(a[0] == 0) return -1;
	int maxR = a[0];
	int step = a[0];
	int jump = 1;

	for(int i = 1; i < n; i++)
	{
		if(i == n-1) return jump;

		maxR = max(maxR, a[i] + i);
		step--;

		if(step == 0)
		{
			jump++;
			if(i >= maxR) return -1;
			step = maxR - i;
		}
	}
	return -1;
}

int main()
{
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++) cin >> a[i];
	cout << "solution using dp approach: " << dp_approach(a,n) << endl;
	cout << "solution using fast approach: " << fast(a, n) << endl;
	return 0;
}