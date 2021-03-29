/*
Find the largest rectangular area possible in a given histogram where the largest rectangle can be made of a number of contiguous bars. For simplicity, assume that all bars have the same width and the width is 1 unit.
*/
#include <bits/stdc++.h>
using namespace std;
/*
In this problem we create two arrays right[n] and left[n];
right[i] stores nearest smallest element to the right of h[i]
left[i] stores nearest smallest element to the left of the h[i]
then we calculate area of every rectangle with length h[i] and width right[i]-left[i]-1
and then get the maximum area out of those area
*/
int getMaxArea(int h[], int n)
{
	int right[n],left[n];
	stack<int> s;
	for(int i = n-1; i >= 0; i--)
	{
		while(!s.empty() && h[s.top()] >= h[i])
		{
			s.pop();
		}
		if(s.empty()) right[i] = n;
		else right[i] = s.top();
		s.push(i);
	}
	stack<int> st;
	for(int i = 0; i < n; i++)
	{
		while(!st.empty() && h[st.top()] >= h[i])
		{
			st.pop();
		}
		if(st.empty()) left[i] = -1;
		else left[i] = st.top();
		st.push(i);
	}
	int max_area = 0, area;
	for(int i = 0; i < n; i++)
	{
		area = h[i]*(right[i]-left[i]-1);
		max_area = max(area, max_area);
	}
	return max_area;
}

int getMaxArea_usingOneStack(int h[], int n)
{
	
	//this stack stores indexes of h[] array in increasing 
	//order
	stack<int> s;
	int max_area = 0;
	int tp;
	int area_with_top;
	int i = 0;
	while(i < n)
	{
		if(s.empty() || h[s.top()] <= h[i])
			s.push(i++);
		else{
			tp = s.top(); s.pop();
			int width = (s.empty() ? i:i-s.top()-1);
			area_with_top = h[tp]*width;

			max_area = max(max_area, area_with_top);
		}
	}

	while(!s.empty()){
		tp = s.top();
		s.pop();
		int width = (s.empty() ? i:i-s.top()-1);
		area_with_top = h[tp]*width;

		max_area = max(max_area, area_with_top);
	}
	return max_area;
}

int main()
{
	int n;
	cin >> n;
	int h[n];
	for(int i = 0; i < n; i++)
	{
		cin >> h[i];
	}
	cout << getMaxArea(h,n) << endl;
	return 0;
}