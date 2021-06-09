/*
string has consecutive same characters
*/

#include <bits/stdc++.h>
using namespace std; 

void removeDuplicates(char* s){
	if(s[0] == '\0') return;

	if(s[0] == s[1]){
		int i = 0;
		while(s[i] != '\0'){
			s[i] = s[i+1];
			i++;
		}
		removeDuplicates(s);
	}

	removeDuplicates(s+1);
}

int main(){
	char s[100];
	cin >> s;
	removeDuplicates(s);
	cout << s << endl;
	return 0;
}