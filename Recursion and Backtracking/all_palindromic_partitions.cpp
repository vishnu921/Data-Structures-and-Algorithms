#include <bits/stdc++.h>
using namespace std;

//function returns true when string is palindromic
bool ispalindromic(string s){
	int l = 0, r = s.length()-1;
	while(l < r){
		if(s[l] != s[r]) return false;
		l++;
		r--;
	}
	return true;
}

void printAllpalindromic(string s, string res){
	if(s.empty()){
		cout << res << "\n";
		return;
	}

	//partition every substring s[0..i] and check if it is palindromic
	//if palindromic add it to the result and recur for s[i+1...n]
	for(int i = 1; i <= s.length(); i++){
		string pre = s.substr(0,i);
		if(ispalindromic(pre)){
			printAllpalindromic(s.substr(i), res+pre+" ");
		}
	}
}

int main(){
	string s;
	cin >> s;
	printAllpalindromic(s, "");
	return 0;
}