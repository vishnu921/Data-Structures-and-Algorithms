/*
Given a string consisting of opening and closing parenthesis, find the length of the longest valid parenthesis substring.
*/
#include <bits/stdc++.h>
using namespace std;


//solution using stack
int getMaxLen_stack(string s)
{
	stack<int> st;
	int n = s.length();
	int res = 0;
	st.push(-1);
	for(int i = 0; i < n; i++)
	{
		if(s[i] == '(')
			st.push(i);
		else{
			if(!st.empty())
				st.pop();

			if(!st.empty())
			{
				res = max(res, i-st.top());      //i-st.top() gives the legth of currently encountered valid string
			}
			else
				st.push(i);
		}
	}
	return res;
}

//solution using dp
int getMaxLen_dp(string s)
{
	if(s.length() <= 1) return 0;
	int mx = 0, n = s.length();
	int dp[n] = {0};
	for(int i = 1; i < n; i++)
	{
		if(s[i] == ')')
		{
			if(s[i-1] == '(')
			{
				dp[i] = (i >= 2 ? dp[i-2]:0) + 2;
			}
			else if(i-dp[i-1] > 0 && s[i-dp[i-1]-1] == '(')
			{
				dp[i] = dp[i-1] + ((i-dp[i-1] >= 2)?dp[i-dp[i-1]-2]:0)+2;
			}
			mx = max(mx, dp[i]);
		}
	}
	return mx;
}

//using auxillary o(1) space
int getMaxLen_O1(string s)
{
	int n = s.length();
	int left = 0, right = 0, mx = 0;
	for(int i = 0; i < n; i++)
	{
		if(s[i] == '(')
			left++;
		else
			right++;

		if(left == right)
		{
			mx = max(mx, 2*right);
		}
		else if(right > left)
			left = right = 0;
	}
	left = right = 0;
	for(int i = n-1; i >= 0; i--)
	{
		if(s[i] == '(')
			left++;
		else
			right++;

		if(left == right)
		{
			mx = max(mx, 2*left);
		}
		else if(left > right)
		{
			left = right = 0;
		}
	}
	return mx;
}


int main()
{
	string s;
	cin >> s;
	cout << "using stack:       " << getMaxLen_stack(s) << endl;
	cout << "using dp:          " << getMaxLen_dp(s) << endl;
	cout << "using o(1) space : " << getMaxLen_O1(s) << endl;
	return 0;
}