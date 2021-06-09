#include <bits/stdc++.h>
using namespace std;

bool ispossible(string word, vector<string> &dict){
    for(auto s: dict){
        if(word == s) return true;
    }
    
    return false;
}

void solve(string s, string res, vector<string> &dict, int n, vector<string> &ans){
    if(s.empty()){
        ans.push_back(res);
        return;
    }
    
    for(int i = 1; i <= s.length(); i++){
        string word = s.substr(0, i);
        if(ispossible(word, dict)){
            solve(s.substr(i), res+word+" ", dict, n, ans);
        }
    }
}

vector<string> wordBreak(int n, vector<string> &dict, string s){
	vector<string> ans;
	solve(s, "", dict, n, ans);
	return ans;
}

int main(){
	int n;
	cin >> n;
	vector<string> dict;
	string s;
	for(int i = 0; i < n; i++){
		cin >> s;
		dict.push_back(s);
	}
	cin >> s;

	vector<string> ans = wordBreak(n, dict, s);
	if(ans.size() == 0){
		cout << "EMPTY\n";
		return 0;
	}

	for(int i = 0; i < ans.size(); i++){
		cout << ans[i] << "\n";
	}
	return 0;
}