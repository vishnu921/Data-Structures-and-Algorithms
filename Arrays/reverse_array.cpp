#include <iostream>
using namespace std;

void reverseArray(int arr[], int n)
{
	int start = 0, end = n-1;
	while(start < end)
	{
		int temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;
		start++;
		end--;
	}
}

int main()
{
	int n;
	cin >> n;
	int a[n];
	cout << "Enter array of n numbers : ";
	for(int i = 0; i < n; i++) cin >> a[i];
	reverseArray(a,n);
	for(int i = 0; i < n; i++) cout << a[i] << " ";
	cout << endl;
	return 0;
}