/*
You are given a string s of lower case english alphabets. You can choose any two characters in the string and replace all 
the occurences of the first character with the second character and replace all the occurences of the second character with 
the first character. Your aim is to find the lexicographically smallest string that can be obtained by doing this operation 
at most once.
*/
#include <bits/stdc++.h>
using namespace std;

string chooseAndswap(string s){
	//array to store left most occurence of every character
	int left_most[26];
	for(int i = 0; i < 26; i++){
		left_most[i] = -1;
	}
	for(int i = 0; i < s.length(); i++){
		if(left_most[s[i]-'a'] == -1){
			left_most[s[i]-'a'] = i;
		}
	}

	int i,j;
	//find the first character from left to right which has a smaller
	//character on its left
	for(i = 0; i < s.length(); i++){
		for(j = 0; j < 26; j++){
			if(j < (s[i]-'a') && left_most[j] > left_most[s[i]-'a'])
				break;
		}
		if(j != 26) break;
	}

	//swap all positions of characters
	char x = j+'a';
	char y = s[i];
	for(i = 0; i < s.length(); i++){
		if(s[i] == x){
			s[i] = y;
		}
		else if(s[i] == y){
			s[i] = x;
		}
	}

	return s;
}

int main(){
	string s;
	cin >> s;
	cout << chooseAndswap(s) << endl;
	return 0;
}