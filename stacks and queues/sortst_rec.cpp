//sort a stack using recursion
#include <bits/stdc++.h>
using namespace std;

void sortedInsert(stack<int> &s, int x)
{
	if(s.empty() || x >= s.top())
	{
		s.push(x);
	}
	else{
		int p = s.top();
		s.pop();
		sortedInsert(s, x);
		s.push(p);
	}
}

void sort(stack<int> &s)
{
	if(s.size() <= 1) return;
	int x = s.top();
	s.pop();
	sort(s);
	sortedInsert(s,x);
}

void print(stack<int> s)
{
	while(!s.empty())
	{
		cout << "  " << s.top() << "\n";
		s.pop();
	}
	cout << endl;
}

int main()
{
	int n,x;
	stack<int> s;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> x;
		s.push(x);
	}
	cout << "Original stack: \n";
	print(s);
	sort(s);
	cout << "Sorted stack: \n";
	print(s);
	return 0;
}