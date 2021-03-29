#include <bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int>& nums, int n)
{
	int i;
	for(i = n-2; i >= 0; i--)
	{
		if(nums[i+1] > nums[i]) break;
	}
	if(i >= 0)
	{
		int j;
		for(j = n-1; j >= 0; j--)
		{
			if(nums[j] > nums[i]) break;
		}
		swap(nums[i], nums[j]);
	}
	reverse(nums.begin()+i+1, nums.end());
}

int main()
{
	int n;
	cin >> n;
	vector<int> nums(n);
	for(int i = 0; i < n; i++)
		cin >> nums[i];
	nextPermutation(nums, n);
	for(int i = 0; i < n; i++)
		cout << nums[i] << " ";
	cout << endl;
	return 0;
}