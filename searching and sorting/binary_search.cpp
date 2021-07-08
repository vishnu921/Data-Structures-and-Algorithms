// when array is sorted we use binary search algorithm
//C++ functions based on binary search implementation
// 1. lower_bound() function returns iterator pointing to first element whose value is
// the smallest number greater >= k in range [first,last).
// Syntax = auto i = lower_bound(first,last,k) - first;
// example: auto i = lower_bound(a, a+n, k) - a;
// 2. upper_bound() returns iterator pointing to first element greater than x or last if not found
// syntax = auto i = upper_bound(first,last,k) - first; 
#include <bits/stdc++.h>
using namespace std;

//This function counts number of elements whose value is x;
void countN(int a[], int n, int x)
{
	auto ax = lower_bound(a, a+n, x);
	auto bx = upper_bound(a, a+n, x);
	cout << bx-ax << endl;
}

int BinarySearch(int a[], int left, int right, int k)
{
	int mid;
	while(left <= right)
	{
		mid = left + (right - left)/2;
		if(a[mid] == k) return mid;
		else if(a[mid] > k) right = mid - 1;
		else left = mid + 1;
	}
	return -1;
}

int BinarySearch_recursive(int a[], int low, int high, int k)
{
	int mid = low + (high - low)/2;
	if(low > high) return -1;
	if(a[mid] == k) return mid;
	else if(a[mid] < k) return BinarySearch_recursive(a,mid+1,high,k);
	else return BinarySearch_recursive(a,low,mid-1,k);
	return -1;
}

int main()
{
	int n, k;
	cin >> n >> k;
	int a[n];
	for(int i = 0; i < n; i++) cin >> a[i];
	int ans = BinarySearch_recursive(a,0,n-1,k);
	if(ans != -1)
		cout << "Found at " << ans+1 << "th index\n";
	else
		cout << "Not Found\n";
}