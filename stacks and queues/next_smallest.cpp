#include <bits/stdc++.h>
using namespace std;

vector<int> NextSmallestElement(int a[], int n)
{
	stack<int> s;
	vector<int> res;
	res.push_back(-1);
	s.push(a[n-1]);
	for(int i = n-2; i >= 0; i--)
	{
		while(!s.empty() && s.top() > a[i])
		{
			s.pop();
		}
		if(s.empty()) res.push_back(-1);
		else res.push_back(s.top());
		s.push(a[i]);
	}
	reverse(res.begin(), res.end());
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

	vector<int> res = NextSmallestElement(a, n);
	for(int i = 0; i < n; i++)
	{
		cout << res[i] << " ";
	}
	cout << endl;
	return 0;
}