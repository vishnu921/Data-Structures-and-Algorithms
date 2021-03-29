/*
Given an expression string x. Examine whether the pairs and the orders of “{“,”}”,”(“,”)”,”[“,”]” are correct in exp.
For example, the function should return 'true' for exp = “[()]{}{[()()]()}” and 'false' for exp = “[(])”
*/
#include <bits/stdc++.h>
using namespace std;

bool ismatching(char popped, char current)
{
	if(popped == '(' && current == ')') return true;
	if(popped == '{' && current == '}') return true;
	if(popped == '[' && current == ']') return true;
	return false;
}

bool isBalanced(string s)
{
	stack<char> st;
	for(char c: s)
	{
		if(c == '(' || c == '{' || c == '[')
		{
			st.push(c);						//if there is a opening bracket we push it to the stack
		}
		else if(c == ')' || c == '}' || c == ']')
		{	//if stack is empty that means there is no opening bracket for the current closed bracket 'c'
			if(st.empty()) return false;     
			if(ismatching(st.top(), c))        //if stack is not empty the top element should match the current bracket
			{									//example '(' should match with ')' and '{' with '}'.
				st.pop();
			}
			else return false; 
		}
	}
	if(st.empty()) return true;             //At last check whether stack is empty or not, if empty return true;
	return false;
}

int main()
{
	string s;
	cin >> s;
	if(isBalanced(s))
	{
		cout << "Balanced\n";
	}
	else{
		cout << "NOT Balanced\n";
	}
	return 0;
}