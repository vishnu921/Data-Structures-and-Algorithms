/*
Given a sequence of strings, the task is to find out the second most repeated (or frequent) string in the given sequence.

Note: No two strings are the second most repeated, there will be always a single string.
*/

#include <bits/stdc++.h>
using namespace std;

string secondMostFrequent(vector<string> &strings, int n){
	//map to store count of each string
	unordered_map<string, int> mp;
	for(int i = 0; i < n; i++){
		mp[strings[i]]++;
	}

	int best = 0, second_best = 0;
	string s1, s2;

	for(auto i: mp){
		//there are 2 cases
		//1. we got a new most occuring string therefore second most
		//occuring will be the current best
		if(i.second > best){
			second_best = best;
			best = i.second;

			s2 = s1;
			s1 = i.first;
		}
		//2. we got a new second most occuring string therefore
		//we update second_best and second most occuring string
		else if(i.second > second_best && i.second != best){
			s2 = i.first;
			second_best = i.second;
		}
	}

	return s2;
}

int main(){
	int n;
	cin >> n;
	vector<string> strings(n);
	for(int i = 0; i < n; i++){
		cin >> strings[i];
	}

	cout << secondMostFrequent(strings, n) << "\n";
	return 0;
}