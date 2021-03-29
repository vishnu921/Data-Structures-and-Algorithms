//reverse a string using stack
#include <bits/stdc++.h>
using namespace std;

string reverse(string s){
	stack<char> st;
	for(char c: s)
	{
		st.push(c);
	}
	s = "";
	while(!st.empty())
	{
		s += st.top();
		st.pop();
	}
	return s;
}

int main()
{
	string s;
	cin >> s;
	s = reverse(s);
	cout << s << endl;
}