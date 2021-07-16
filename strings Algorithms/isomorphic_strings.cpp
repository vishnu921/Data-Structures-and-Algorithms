/*
Given two strings 'str1' and 'str2', check if these two strings are isomorphic to each other.
Two strings str1 and str2 are called isomorphic if there is a one to one mapping possible for every character of str1 to every character of str2 while preserving the order.
Note: All occurrences of every character in ‘str1’ should map to the same character in ‘str2’
*/

#include <bits/stdc++.h>
using namespace std;

bool isIsomorphic(string a, string b){
	if(a.length() != b.length()) return false;

	int h1[26] = {}, h2[26] = {};

	for(int i = 0; i < a.length(); i++){
		//if both character did not appearh before
		//add them to hashmaps
		if(h1[a[i]-'a'] == 0 && h2[b[i]-'a'] == 0){
			h1[a[i]-'a'] = b[i];
			h2[b[i]-'a'] = a[i];
		}
		//else if their hashmap does not match return false
		else if(h1[a[i]-'a'] != b[i] || h2[b[i]-'a'] != a[i])
			return false;
	}

	return true;
}


int main(){
	string a, b;
	cin >> a >> b;

	if(isIsomorphic(a, b)){
		cout << "TRUE\n";
	}
	else cout << "FALSE\n";
	return 0;
}