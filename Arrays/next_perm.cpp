#include <bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int>& nums, int n)
{
	int i;
	//first we find the first element from right such that
	//nums[i] < nums[i+1]
	for(i = n-2; i >= 0; i--)
	{
		if(nums[i+1] > nums[i]) break;
	}
	if(i >= 0)
	{
		//if we found the element then find smallest number from right
		//greater than nums[i], we find smallest number greater to get lexographical
		//next permutation
		int j;
		for(j = n-1; j >= 0; j--)
		{
			if(nums[j] > nums[i]) break;
		}
		//swap both elements
		swap(nums[i], nums[j]);
	}
	//now reverse all element right to the nums[i]
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