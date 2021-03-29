/*Given an array of N integers, and an integer k, find the number of pairs
of elements in the array whose sum is equal to k
*/

#include <bits/stdc++.h>
using namespace std;

//we use unordered map to hash each element of array
int CountPairsWithSum(int a[], int n, int k)
{
	unordered_map <int, int> m;
	int c = 0;
	for(int i = 0; i < n; i++){
		int x = k - a[i];
		if(m[x == 0])
		{
			m[a[i]]++;
		}
		else
		{
			c+= m[x];
			m[a[i]]++;
		}
	}
	return c;
}

int main()
{
	int n, k;
	cin >> n >> k;
	int a[n];
	for(int i = 0; i < n; i++) cin >> a[i];
	cout << CountPairsWithSum(a, n , k) << endl;
	return 0;
}