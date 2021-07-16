/*
Given a binary string, that is it contains only 0s and 1s. We need to make this string a sequence of alternate 
characters by flipping some of the bits, our goal is to minimize the number of bits to be flipped.
*/

#include <bits/stdc++.h>
using namespace std;

int minFlips(string s){
	int n = s.length();
	int c1 = 0, c2 = 0;
	//there are only 2 possible strings 010101... and 1010101...
	//we calculate the number of flips required to convert string s to
	//both possibilities and return the minimum
	for(int i = 0; i < n; i++){
		if(i%2 == s[i]-'0'){
			c1++;
		}
		else c2++;
	}

	return min(c1, c2);
}

int main(){
	string s;
	cin >> s;
	cout << minFlips(s) << "\n";
	return 0;
}