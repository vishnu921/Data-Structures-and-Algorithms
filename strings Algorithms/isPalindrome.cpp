#include <bits/stdc++.h>
using namespace std;

bool isPalindromic(string s){
	int n = s.length();
	int l = 0, r = n-1;

	while(l < r){
		if(s[l] != s[r]) return false;
		l++;
		r--;
	}

	return true;
}

int main(){
	string s;
	cin >> s;

	if(isPalindromic(s)){
		cout << s << " is Palindromic\n";
	}
	else cout << s << " is not a Palindrome\n";
	return 0;
}