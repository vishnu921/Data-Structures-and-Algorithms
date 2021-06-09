/*
Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n.
Return empty string for numbers 0 and 1.
*/

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

string key(int n){
	if(n == 2) return "abc";
	if(n == 3) return "def";
	if(n == 4) return "ghi";
	if(n == 5) return "jkl";
	if(n == 6) return "mno";
	if(n == 7) return "pqrs";
	if(n == 8) return "tuv";
	if(n == 9) return "wxyz";

	return "";
}

void keypad(int n, string output){
	if(n <= 1){
		cout << output << "\n";
		return;
	}

	//get the letters corresponding to the number
	string k = key(n%10);
	n = n/10;

	//all letters corresponding to current digit one by one
	//and recursively call the function for remaining number
	for(int i = 0; i < k.size(); i++){
		keypad(n, k[i]+output);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	keypad(n, "");
	return 0;
}