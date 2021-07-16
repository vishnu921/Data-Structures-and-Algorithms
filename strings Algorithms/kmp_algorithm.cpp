/*
Given two strings, one is a text string and other is a pattern string. The task is to print the indexes of all 
the occurences of pattern string in the text string. For printing, Starting Index of a string should be taken as 1.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> KMPsearch(string pat, string txt){
	int n = pat.length();
	int m = txt.length();
	vector<int> res;

	int lps[n];     //lps[i] = longest proper prefix of s[0...i] which is also proper suffix of s[0...i]
	lps[0] = 0;
	int i = 1, j = 0;

	//building lps[] array for pat string
	while(i < n){
		if(pat[i] == pat[j]){
			lps[i] = j+1;
			j++;
			i++;
		}
		else{
			if(j != 0){
				j = lps[j-1];
			}
			else{
				lps[i] = 0;
				i++;
			}
		}
	}

	//kmp pattern searching
	i = 0, j = 0;
	while(i < m){
		if(txt[i] == pat[j]){
			i++;
			j++;
		}
		else{
			if(j != 0){
				j = lps[j-1];
			}
			else i++;
		}

		if(j == n){
			res.push_back(i-j+1);
			j = lps[j-1];
		}
	}

	return res;
}

int main(){
	string pat, txt;
	cin >> pat >> txt;

	vector<int> res = KMPsearch(pat, txt);

	if(res.empty()){
		cout << "-1\n";
		return 0;
	}

	for(auto i: res){
		cout << i << " ";
	}
	cout << endl;
	return 0;
}