#include <bits/stdc++.h>
using namespace std;

string reverse_string(string s){
	int n = s.length();
	int l = 0, r = n-1;

	while(l < r){
		swap(s[l], s[r]);
		l++;
		r--;
	}

	return s;
}

int main(){
	string s;
	cin >> s;

	cout << reverse_string(s) << "\n";
	return 0;
}