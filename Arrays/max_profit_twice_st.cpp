#include <bits/stdc++.h>
using namespace std;

int maxprofit(int price[], int n, int k)
{
	//profit[t][] stores maximum profit using
	//atmost t transactions upto day i(inclusive)
	int profit[k+1][n+1];

	//profit at day 0 is 0
	for(int i = 0; i <= k; i++)
		profit[i][0] = 0;

	//profit is 0 if we don't do any transaction i.e k = 0
	for(int j = 0; j <= n; j++)
		profit[0][j] = 0;

	for(int i = 1; i <= k; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			int best = INT_MIN;
			for(int m = 0; m < j; m++)
			{
				best = max(best,price[j]-price[m]+profit[i-1][m]);
			}
			profit[i][j] = max(best, profit[i][j-1]);
		}
	}
	return profit[k][n-1];
}

int main()
{
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++)
		cin >> a[i];
	cout << maxprofit(a,n,2) << endl;
	return 0;
}