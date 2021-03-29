//evaluate postix expression
#include <bits/stdc++.h>
using namespace std;

int operate(int a, int b, char c)
{
	switch(c){
		case '+': return a+b;
		case '-': return a-b;
		case '*': return a*b;
		case '/': return a/b;
	}
	return -1;
}

bool isOperator(char c)
{
	if(c == '+' || c == '-' || c == '*' || c == '/')
		return true;
	return false;
}

int evaluatePostfix(string s)
{
	int n = s.length();
	stack<int> st;
	for(int i = 0; i < n; i++)
	{
		if(!isOperator(s[i]))
		{
			int x = s[i]-'0';
			st.push(x);
		}
		else{
			int a = st.top(); st.pop();
			int b = st.top(); st.pop();
			int c = operate(b, a, s[i]);
			st.push(c);
		}
	}
	return st.top();
}

int main()
{
	string s;
	cin >> s;
	cout << "Ans : " << evaluatePostfix(s) << endl;
	return 0;
}