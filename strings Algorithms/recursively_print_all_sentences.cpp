/*
Given a list of word lists How to print all sentences possible taking one word from a list at a time via
recursion? 
*/

#include <bits/stdc++.h>
using namespace std;
#define R 3
#define C 3

void solve(string a[R][C], int i, string output[R]){
	if(i == R){
		for(int i = 0; i < R; i++){
			cout << output[i] << " ";
		}
		cout << "\n";
		return;
	}

	for(int j = 0; j < C; j++){
		if(a[i][j] != ""){
			output[i] = a[i][j];
			solve(a, i+1, output);
		}
	}
}

void print(string a[R][C]){
	string output[R];
	solve(a, 0, output);
}

int main(){
	string arr[R][C]  = {{"you", "we"},
                        {"have", "are"},
                        {"sleep", "eat", "drink"}};
 
   print(arr);
	return 0;
}