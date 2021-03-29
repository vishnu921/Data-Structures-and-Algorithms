/*Given an array of integers. Find the Inversion Count in the array. 

Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. If array is already sorted then the inversion count is 0. If an array is sorted in the reverse order then the inversion count is the maximum. 
Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.
*/
#include <bits/stdc++.h>
using namespace std;

int merge_sort(int a[], int temp[], int left, int right);

int count_inv(int a[], int n)
{
	int temp[n];
	return merge_sort(a,temp,0,n-1);
}

int merge(int a[], int temp[], int left, int mid, int right)
{
	int i, j, k;
	int inv_count = 0;
	i = left;
	j = mid;
	k = left;
	while((i <= mid - 1) && (j <= right))
	{
		if(a[i] <= a[j])
			temp[k++] = a[i++];
		else{
			temp[k++] = a[j++];
			inv_count = inv_count + mid - i;
		}
	}

	while(i <= mid-1)
		temp[k++] = a[i++];
	while(j <= right)
		temp[k++] = a[j++];

	for(i = left; i <= right; i++)
		a[i] = temp[i];

	return inv_count;
}

int merge_sort(int a[], int temp[], int left, int right)
{
	int mid, inv_count = 0;
	if(left < right)
	{
		mid = (right + left)/2;
		inv_count += merge_sort(a,temp,left,mid);
		inv_count += merge_sort(a,temp,mid+1,right);

		inv_count += merge(a,temp,left,mid+1,right);
	}
	return inv_count;
}

int main()
{
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	cout << "count inversion: " << count_inv(a,n) << endl;
	/* code */
	return 0;
}