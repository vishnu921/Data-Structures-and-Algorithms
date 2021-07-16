#include <bits/stdc++.h>
using namespace std;

void printAllSubsequences(string &s, int idx, string output){
	if(idx == s.length()){
		cout << output << "\n";
		return;
	}

	//we have 2 choices for every character
	//1. do not add current charcter to output
	printAllSubsequences(s, idx+1, output);
	
	//2. add the current character to output
	printAllSubsequences(s, idx+1, output + s[idx]);

}

int main(){
	string s;
	cin >> s;

	printAllSubsequences(s, 0, "");
	return 0;
}