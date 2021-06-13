#include <bits/stdc++.h>
using namespace std;

void solve(string &s, string &res, int idx, int k){
	//base case if there are no swaps left
	if(k == 0){
		return;
	}

	int n = s.length();
	int mx = idx;
	//find maximum digit after current index idx
	for(int i = idx+1; i < n; i++){
		if(s[i] > s[mx]){
			mx = i;
		}
	}

	//if there is a digit on the right side of s[idx] we have to make a swap hence decrease k by 1
	if(s[mx] != s[idx]) k--;

	//find every digit equal to s[mx]
	for(int i = idx; i < n; i++){
		//swap with every digit equal to s[mx]
		if(s[i] == s[mx]){
			swap(s[i], s[idx]);
			//update res if after swapping s > res;
			res = max(s, res);
			//recur for rest of the string
			solve(s, res, idx+1, k);
			//backtracking
			swap(s[i], s[idx]);
		}
	}
}

string largestNumKswaps(string s, int k){
	string res = s;
	//helper function to get largest number with at most k swaps
	solve(s, res, 0, k);
	return res;
}

int main(){
	int k;
	cin >> k;
	string s;
	cin >> s;
	cout << largestNumKswaps(s, k) << "\n";
	return 0;
}