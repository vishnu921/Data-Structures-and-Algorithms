#include <bits/stdc++.h>
using namespace std;

string smallestWindow(string s, string p){
	int hash[256] = {0};
	int uniqueWords = 0;
	for(int i = 0; i < p.length(); i++){
		if(hash[p[i]] == 0){
			uniqueWords++;
		}
		hash[p[i]]++;
	}

	int i = 0, j = 0;
	int start = 0, res = INT_MAX;

	while(j < s.length()){
		hash[s[j]]--;

		if(hash[s[j]] == 0){
			uniqueWords--;
		}

		while(uniqueWords == 0){
			if(res > j-i+1){
				res = j-i+1;
				start = i;
			}
			hash[s[i]]++;
			if(hash[s[i]] > 0){       //the most important step to understand
				uniqueWords++;
			}

			i++;
		}
		j++;
	}

	if(res == INT_MAX) return "-1";
	return s.substr(start, res);
}

int main(){
	string s,p;
	cin >> s >> p;

	cout << smallestWindow(s, p) << "\n";
	return 0;
}