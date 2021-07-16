/*
Given a string A and a dictionary of n words B, find out if A can be segmented into a space-separated sequence 
of dictionary words. 
*/

#include <bits/stdc++.h>
using namespace std;

bool WordBreak(string& a, vector<string> &words){
	//first we put all words in a unordered-set
	unordered_set<string> mp;

	for(auto &x: words){
		mp.insert(x);
	}

	int n = a.length();
	//dp[i] stores true if it is possible to segment string s[0...(i-1)]
	//into sentence of words present in the dictionary
	vector<bool> dp(n+1, false);
	dp[0] = true;

	for(int i = 1; i <= n; i++){
		for(int j = i-1; j >= 0; j--){
			if(dp[j] && mp.find(a.substr(j, i-j)) != mp.end()){
				dp[i] = true;
				break;
			}
		}
	}

	return dp[n];
}

int main(){
	int n;
	cin >> n;
	vector<string> words;
	for(int i = 0; i < n; i++){
		string w;
		cin >> w;
		words.push_back(w);
	}
	string a;
	cin >> a;

	cout << WordBreak(a, words) << "\n";
	return 0;
}