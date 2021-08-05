/*
Given an array of strings, return all groups of strings that are anagrams. The groups must be created in order 
of their appearance in the original array.
*/
#include <bits/stdc++.h>
using namespace std;

//O(n*L*log(L)) n = number of strings L = length of strings
vector<vector<string>> groupAnagrams(vector<string> &strs, int n){
	//result vector of vector of strings
	vector<vector<string>> res;

	//hash map to store each string corresponding to its sorted string
	unordered_map<string, vector<string>> mp;

	for(int i = 0; i < n; i++){
		string s = strs[i];

		//sort the key string
		sort(s.begin(), s.end());

		mp[s].push_back(strs[i]);
	}

	//by doing this we get each group of anagrams in one vector
	for(auto i: mp){
		res.push_back(i.second);
	}

	return res;
}

int main(){
	int n;
	cin >> n;
	vector<string> strs(n);
	for(int i = 0; i < n; i++){
		cin >> strs[i];
	}

	vector<vector<string>> res = groupAnagrams(strs, n);
	for(auto v: res){
		for(string s: v){
			cout << s << " ";
		} cout << "\n";
	}
	return 0;
}