/*
Given a string S consisting of only opening and closing curly brackets '{' and '}', find out the 
minimum number of reversals required to convert the string into a balanced expression.
A reversal means changing '{' to '}' or vice-versa.

Example 1:

Input:
S = "}{{}}{{{"
Output: 3
*/

#include <bits/stdc++.h>
using namespace std;

int countReversal(string s){
	int n = s.length();
	if(n&1) return -1;

	//op = number of opening braces
	//cl = number of closed braces
	int op = 0, cl = 0;
	int ans = 0;

	for(int i = 0; i < n; i++){
		if(s[i] == '{'){
			op++;
		}
		else{
			cl++;
		}

		//if a closing brace is extra we reverse it
		if(cl > op){
			ans++;
			cl--;
			op++;
		}
	}

	//reverse extra opening braces
	ans += (op-cl)/2;

	return ans;
}

int main(){
	string s;
	cin >> s;

	cout << countReversal(s) << "\n";
	return 0;
}