//reverse a stack using recursion
// time complexity = O(n^2)
#include <bits/stdc++.h>
using namespace std;

stack<char> st;
string s;

void insertatbottom(char x)
{
	if(st.empty()){
		st.push(x);
	}
	else{
		char c = st.top();
		st.pop();
		insertatbottom(x);
		st.push(c);
	}
}

void reverse()
{
	if(!st.empty())
	{
		char x = st.top();
		st.pop();
		reverse();
		insertatbottom(x);
	}
}

void print(stack<char> s)
{
	while(!s.empty())
	{
		cout << "  " << s.top() << endl;
		s.pop();
	}
	cout << endl;
}

int main()
{
	int n;
	cin >> n;
	char c;
	for(int i = 0; i < n; i++)
	{
		cin >> c;
		st.push(c);
	}
	cout << "original: \n";
	print(st);
	reverse();
	cout << "reversed: \n";
	print(st);
	return 0;
}