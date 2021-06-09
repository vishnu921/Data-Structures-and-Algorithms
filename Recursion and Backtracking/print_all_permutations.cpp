/*
Given a string S. The task is to print all permutations of a given string.
*/
#include <bits/stdc++.h>
using namespace std;
#define vs vector<string>

void getPermutations(string &s, int i, vs &res){
	//base case
	if(i == s.length()){
		res.push_back(s);
		return;
	}

	//permutation made using swapping
	for(int j = i; j < s.length(); j++){
		swap(s[i], s[j]);
		//recur for next position after every swapping
		getPermutations(s, i+1, res);
		//backtrack
		swap(s[i], s[j]);

	}
}


vs printallPermutations(string s){
	vs res;
	getPermutations(s, 0, res);
	return res;
}

int main(){
	string s;
	cin >> s;
	vs res = printallPermutations(s);
	for(auto x: res){
		cout << x << " ";
	}
	cout << endl;
	return 0;
 }
