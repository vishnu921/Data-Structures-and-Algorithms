/*Repeatedly swap adjacent elements if they are in 
wrong order*/

#include <bits/stdc++.h>
using namespace std;

void BubbleSort(int a[], int n)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n-i-1; j++)
		{
			if(a[j] > a[j+1]){
				swap(a[j], a[j+1]);
			}
		}
	}
}

//best case becomes O(n) and worst case remains o(n^2)
void improved_Bubble_sort(int a[], int n)
{
	bool swapped = false;
	for(int i = 0; i < n; i++)
	{
		swapped = false;
		for(int j = 0; j < n-i-1; j++)
		{
			if(a[j] > a[j+1])
			{
				swap(a[j], a[j+1]);
				swapped = true;    //that means atleast one swapping is done in this loop
			}
		}
		if(swapped == false) break; //if we find no adjacent element which are in wrong order that means array is already
									//sorted
	}
}

int main()
{
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++)
		cin >> a[i];
	BubbleSort(a,n);
	for(int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
	return 0;
}