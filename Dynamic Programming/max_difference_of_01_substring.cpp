/*
Given a binary string of 0s and 1s. The task is to find the maximum difference of the number of 
0s and the number of 1s (number of 0s – number of 1s) in the substrings of a string.

Note: In the case of all 1s, the answer will be -1. 
*/
#include <bits/stdc++.h>
using namespace std;

int maxDifferenceSubstring(string s){
	int n = s.length();
	//cur stores cur best difference of 0s and 1s in substring
	//ans stores all time best difference of 0s and 1s in substring
	int ans = -1, cur = 0;

	// we consider 0s as +1 and 1s as -1 and apply kadane's algorithm
	//because the sum of +1 and -1 will give the difference of 0s and 1s
	for(int i = 0; i < n; i++){
		if(s[i] == '0'){
			cur++;
		}
		else cur--;

		ans = max(ans, cur);   //writing this statement first handels -1 case
		if(cur < 0) cur = 0;
	}

	return ans;
}

int main(){
	string s;
	cin >> s;
	cout << maxDifferenceSubstring(s) << "\n";
	return 0;
}