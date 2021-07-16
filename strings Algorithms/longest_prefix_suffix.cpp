/*
Given a string of characters, find the length of the longest proper prefix which is also a proper suffix.
*/

#include <bits/stdc++.h>
using namespace std;

int longestPrefixSuffix(string s){
	int n = s.length();
	int lps[n];          //lps[i] stores lps of string s[0...i]
	lps[0] = 0;

	int i = 1, j = 0;

	while(i < n){
		if(s[i] == s[j]){
			lps[i] = j+1;
			j++;
			i++;
		}
		else{
			if(j != 0){
				j = lps[j-1];
			}
			else{
				lps[i] = 0;
				i++;
			}
		}
	}

	return lps[n-1];
}

int main(){
	string s;
	cin >> s;

	cout << longestPrefixSuffix(s) << "\n";
	return 0;
}