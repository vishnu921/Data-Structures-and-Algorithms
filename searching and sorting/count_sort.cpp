#include <bits/stdc++.h>
using namespace std;

void count_sort(int a[], int n)
{
	int k = a[0];
	for(int i = 1; i < n; i++)
	{
		k = max(k, a[i]);
	}

	int count[k+1] = {0};
	for(int i = 0; i < n; i++)
	{
		count[a[i]]++;
	}

	for(int i = 1; i <= k; i++)
	{
		count[i] += count[i-1];
	}

	int output[n];
	for(int i = n-1; i >= 0; i--)
	{
		output[--count[a[i]]] = a[i];
	}

	for(int i = 0; i < n; i++)
	{
		a[i] = output[i];
	}
}

int main()
{
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++)
		cin >> a[i];
	count_sort(a,n);
	for(int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
	return 0;
}