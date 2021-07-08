/*
pick an element from the unsorted subarray and place it 
at the correct position in the sorted subarray
*/

#include <bits/stdc++.h>
using namespace std;

void insertion_sort(int a[], int n)
{
	int i, j ,key;
	for(i = 1; i < n; i++)
	{
		key = a[i];
		j = i-1;
		while(a[j] > key && j >= 0)
		{
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = key;
	}
}

int main()
{
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++)
		cin >> a[i];
	insertion_sort(a,n);
	for(int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl; 
	return 0;
}