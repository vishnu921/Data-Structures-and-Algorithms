/*
Given a binary string str of length N, the task is to find the maximum count of consecutive substrings str 
can be divided into such that all the substrings are balanced i.e. they have equal number of 0s and 1s. 
If it is not possible to split str satisfying the conditions then print -1.
Example: 
 

    Input: str = “0100110101” 
    Output: 4 
    The required substrings are “01”, “0011”, “01” and “01”.
    Input: str = “0111100010” 
    Output: 3 

    Input: str = “0000000000” 

    Output: -1
     
     */

#include <bits/stdc++.h>
using namespace std;

int maxSubstr(string s){
	int n = s.length();

	int c0 = 0, c1 = 0, count = 0;

	/*
	we keep track of number of 0s and 1s as we traverse
	the string. and where ever c0 == c1
	we increement the count because we need maximum substrings
	with c0 = c1
	*/
	for(int i = 0; i < n; i++){
		if(s[i] == '0'){
			c0++;
		}
		else c1++;
		if(c0 == c1){
			count++;
		}
	}

	if(count == 0) return -1;


	return count;
}

int main(){
	string s;
	cin >> s;

	cout << maxSubstr(s) << "\n";
	return 0;
}