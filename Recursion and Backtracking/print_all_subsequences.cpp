/*
let a string is abc then its all substrings are
"", "a", "b", "c", "ab", "ac", "bc", "abc".

total number of subsequences of a string of length n = 2^n
*/
#include <bits/stdc++.h>
using namespace std;

void printSubsequences(string s, string output){
	if(s.empty()){
		cout << output << "\n";
		return;
	}

	//we have 2 choices either select current element
	//we do both coices one by one
	printSubsequences(s.substr(1), output);
	printSubsequences(s.substr(1), output+s[0]); //here we have taken the current element
}

#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin >> s;
	printSubsequences(s, "");
	return 0;
}