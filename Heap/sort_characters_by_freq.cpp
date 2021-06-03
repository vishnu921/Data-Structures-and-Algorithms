/*
Given a string s, sort it in decreasing order based on the frequency of characters, and return the sorted string.
this contains 2 solution:
1. Bucket sort of O(n) complexity
2. Priority queue of O(nlogn) complexity
*/

#include <bits/stdc++.h>
using namespace std;
typedef pair<int,char> pic;

struct compare{
	bool operator()(pic a, pic b){
		return (a.first < b.first);
	}
};

string frequencySort_pq(string s){
	int n = s.length();
	unordered_map<char,int> freq;
	priority_queue<pic, vector<pic>, compare> pq;
	string res = "";

	for(auto c: s){
		freq[c]++;
	}

	
	for(auto i: freq){
		pq.push(make_pair(i.second, i.first));
	}

	while(!pq.empty()){
		pic a =pq.top();
		pq.pop();
		for(int i = 0; i < a.first; i++){
			res += a.second;
		}
	}
	return res;
}

string frequencySort_Bucket(string s){
	int n = s.length();
	unordered_map<char,int> freq;
	vector<string> bucket(n+1, "");
	string res;

	//count frequency of every character
	for(char c: s) freq[c]++;

	//let character c have freq = f
	//then put string of c character of length f at fth index of bucket
	for(auto i: freq){
		int f = i.second;
		int c = i.first;
		bucket[f].append(f,c);
	}

	//string at largest index has most frequent character
	for(int i = n; i>0; i--){
		if(!bucket[i].empty()){
			res.append(bucket[i]);
		}
	}
	return res;
}

int main(){
	string s;
	cin >> s;
	cout << frequencySort_pq(s) << endl;
	cout << frequencySort_Bucket(s) << endl;
	return 0;
}