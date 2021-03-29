/*kadane's algorithm*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++)
		cin >> a[i];
	int best = 0, sum = 0;
	for(int i = 0; i < n; i++)
	{
		sum = max(a[i], sum+a[i]);
		best = max(sum, best);
	}
	cout << "maximum subarray sum: " << best << endl;
	return 0;
}