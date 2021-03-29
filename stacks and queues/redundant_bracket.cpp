/*
Given a string of balanced expression, find if it contains a redundant parenthesis or not. A set of parenthesis are redundant if same sub-expression is surrounded by unnecessary or multiple brackets. Print ‘Yes’ if redundant else ‘No’.
*/

#include <bits/stdc++.h>
using namespace std;

bool isoperator(char c)
{
	if(c == '+' || c == '-' || c == '*' || c == '/')
		return true;
	return false;
}

bool checkRedundancy(string s)
{
	stack<char> st;
	for(char c: s)
	{
		if(c == ')')
		{
			char top = st.top();
			st.pop();

			bool flag = true;
			while(top != '(')
			{
				if(isoperator(top))
					flag = false;

				top = st.top();
				st.pop();
			}

			if(flag == true) return true;
		}
		else{
			st.push(c);
		}
	}
	return false;
}

int main()
{
	string s;
	cin >> s;
	if(checkRedundancy(s)){
		cout << "YES\n";
	}
	else{
		cout << "NO\n";
	}
	return 0;
}