/*
Given two strings, one is a text string and other is a pattern string. The task is to print the indexes of
 all the occurences of pattern string in the text string. For printing, Starting Index of a string should 
 be taken as 1.
*/

#include <bits/stdc++.h>
using namespace std;

#define d 256
const int q = 101;

vector<int> search(string pat, string txt){
	vector<int> res;
	int n = txt.length();
	int m = pat.length();
	int p = 0;
	int t = 0;
	int h = 1;

	//h = (d^(m-1))%q
	for(int i = 0; i < m-1; i++){
		h = (h*d)%q;
	}

	//calculate the hash code of pattern and first window of text
	for(int i = 0; i < m; i++){
		p = (d*p + pat[i])%q;
		t = (d*t + txt[i])%q;
	}

	for(int i = 0; i <= n-m; i++){
		//compare the hash code of current window of text with 
		//pattern. If they match then only check the characters one by one
		if(p == t){
			int j;
			for(j = 0; j < m; j++){
				if(pat[j] != txt[i+j])
					break;
			}
			//if p == t and pat[0..(m-1)] == txt[i, i+1, ....(i+m-1)]
			if(j == m) res.push_back(i+1);
		}

		if(i < n-m){
			t = (d*(t - txt[i]*h) + txt[i+m])%q;

			if(t < 0){
				t = (t+q);
			}
		}
	}

	if(res.empty()) return {-1};
	return res;
}

int main(){
	string txt, pat;
	cin >> txt >> pat;

	vector<int> res = search(pat, txt);
	for(auto i: res){
		cout << i << " ";
	} cout << endl;
	return 0;
}