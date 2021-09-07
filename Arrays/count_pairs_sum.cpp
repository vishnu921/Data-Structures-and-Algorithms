/*Given an array of N integers, and an integer k, find the number of pairs
of elements in the array whose sum is equal to k
*/

#include <bits/stdc++.h>
using namespace std;

//we use unordered map to hash each element of array
int CountPairsWithSum(int arr[], int n, int k)
{
	unordered_map <int, int> mp;
	int count = 0;
	for(int i = 0; i < n; i++){
		if(mp.find(k-arr[i]) != mp.end()){
			count += mp[k-arr[i]];
		}
		mp[arr[i]]++;
	}

	return count;
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