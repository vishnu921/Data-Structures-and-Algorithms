/*Given two sorted arrays arr1[] of size N and arr2[] of size M. Each array is sorted in non-decreasing order. Merge the two arrays into one sorted array in non-decreasing order without using any extra space.
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	int a[n], b[m];
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < m; i++) cin >> b[i];
	int i = n-1, j = 0;
	while(i >= 0 && j < m)
	{
		if(a[i] > a[j]){
			swap(a[i], a[j]);
			i--;
			j++;
		}
		else
			break;
	}
	sort(a, a+n);
	sort(b, b+m);
	for(int i = 0; i < n; i++) cout << a[i] << " ";
	for(int i = 0; i < m; i++) cout << b[i] << " ";
	cout << endl;
	return 0;
}