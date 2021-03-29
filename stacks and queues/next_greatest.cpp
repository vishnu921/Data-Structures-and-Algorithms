/*
Given an array arr[ ] of size N having distinct elements, the task is to find the next greater element for each element of the array in order of their appearance in the array.
Next greater element of an element in the array is the nearest element on the right which is greater than the current element.
If there does not exist next greater of current element, then next greater element for current element is -1. For example, next greater of the last element is always -1
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> NextGreatestElement(int a[], int n)
{
	vector<int> res;
	stack<int> s;
	s.push(a[n-1]);
	res.push_back(-1);
	for(int i = n-2; i >= 0; i--)
	{
		while(!s.empty() && s.top() <= a[i])
		{
			s.pop();     //popping all element less than a[i] in stack to get the nearest greatest element to the right of it
		}
		if(s.empty()) res.push_back(-1);
		else res.push_back(s.top());
		s.push(a[i]);
	}
	reverse(res.begin(),res.end());
	return res;
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
	vector<int> res;
	res = NextGreatestElement(a, n);
	for(auto i: res)
	{
		cout << i << " ";
	}
	cout << endl;
	return 0;
}