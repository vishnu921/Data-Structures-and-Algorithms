/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 */

#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string> &strs, int n){
	string s = strs[0];
	int ans = s.length();

	//this loop finds the length of longest common prefix of all strings in strs[]
	for(int i = 1; i < n; i++){
		string t = strs[i];
		int idx = 0;
		while(idx < s.length() && idx < t.length()){
			if(s[idx] != t[idx]) break;
			idx++;
		}
		ans = min(ans, idx);
	}

	return s.substr(0, ans);
}

int main(){
	int n;
	cin >> n;
	vector<string> strs(n);
	for(int i = 0; i < n; i++){
		cin >> strs[i];
	}

	cout << longestCommonPrefix(strs, n) << "\n";
	return 0;
}