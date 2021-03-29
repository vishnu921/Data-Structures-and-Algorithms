#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++)
		cin >> a[i];
	int l = 0;
	int h = n-1;
	while(l <= h)
	{
		if(a[l] < 0 && a[h] < 0)
			l++;
		else if(a[l] >= 0 && a[h] < 0)
		{
			swap(a[l], a[h]);
			l++;
			h--;
		}
		else if(a[l] >= 0 && a[h] >= 0)
			h--;
		else
		{
			l++;
			h--;
		}
	}
	for(int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
	return 0;
}