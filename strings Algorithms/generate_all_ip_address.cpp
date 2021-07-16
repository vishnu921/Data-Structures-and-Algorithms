/*
Given a string S containing only digits, Your task is to complete the function genIp() which returns a 
vector containing all possible combination of valid IPv4 ip address and takes only a string S as its only argument.
Note : Order doesn't matter.

For string 11211 the ip address possible are 
1.1.2.11
1.1.21.1
1.12.1.1
11.2.1.1
*/

#include <bits/stdc++.h>
using namespace std;

bool isValid(string &s, int i, int len){
	//check for length
	if(i + len > s.length()) return false;
	string x = s.substr(i, len);
	int n = stoi(x);
	//check for range and first element as 0 
	//example: '011' not valid
	if((x.length() > 1 && x[0] == '0') || n > 255)
		return false;

	return true;
}

void solve(string &s, int idx, int cuts, string cur, vector<string> &res){
	if(idx == s.length() && cuts == 4){
		cur.pop_back();
		res.push_back(cur);
		return;
	}

	if(cuts >= 4 || s.length() > 12) return;

	for(int len = 1; len <= 3; len++){
		if(isValid(s, idx, len)){
			solve(s, idx+len, cuts+1, cur+s.substr(idx, len)+'.', res);
		}
	}
}

vector<string> generateIP(string s){
	vector<string> res;
	solve(s, 0, 0, "", res);
	return res;
}

int main(){
	string s;
	cin >> s;
	vector<string> res = generateIP(s);
	for(auto i: res){
		cout << i << "\n";
	}
	return 0;
}