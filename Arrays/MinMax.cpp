#include <iostream>
using namespace std;

void find_MinMax(int a[], int n)
{
	int mini = a[0];
	int maxi = a[0];
	for(int i = 1; i < n; i++)
	{
		if(mini > a[i])
			mini = a[i];
		if(maxi < a[i])
			maxi = a[i];
	}
	cout << "Minimum element in the array : " << mini << endl;
	cout << "Maximum element in the array : " << maxi;
}

int main()
{
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	find_MinMax(a,n);
	return 0;
}