/*rearrange array such that  negetive and positive elements are alternate*/
#include <bits/stdc++.h>
using namespace std;

void rearrange(int a[], int n)
{
	int i = -1, j = n-1;
	while(i < j)
	{
		while( i < n && a[i] > 0) i++;
		while( j >= 0 && a[j] < 0) j--;
		if(i < j)
			swap(a[i], a[j]);
	}

	if(i == 0 || i == n) return;

	int k = 0;
	while(k < n && i < n)
	{
		swap(a[k], a[i]);
		i++;
		k += 2;
	}
}

int main()
{
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++)
		cin >> a[i];
	rearrange(a, n);
	for(int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
	return 0;
}