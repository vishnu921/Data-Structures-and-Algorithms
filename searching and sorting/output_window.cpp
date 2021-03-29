/*
find the maximum occuring element in an array
time complexity = O(n);
space complexity = O(1)

this algorithm is called Moore's voting algorithm
*/
#include <bits/stdc++.h>
using namespace std;

int findMaj(int a[], int n)
{
	//setting majority index to 0 and count = 1 of that element
	int count = 1, maj_index = 0;
	for(int i = 1; i < n; i++)
	{
		if(a[maj_index] == a[i])
			count++;
		else
			count--;

		//if count = 0 we set majority index to current index
		if(count == 0)
		{
			maj_index = i;
			count = 1;
		}
	}
	return a[maj_index];
}

int main()
{
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++) cin >> a[i];

	cout << "majority element : " << findMaj(a,n) << endl;
	return 0;
}