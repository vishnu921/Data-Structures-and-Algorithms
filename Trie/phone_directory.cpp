/*
Given a list of contacts which exist in a phone directory. The task is to implement search query 
for the phone directory. The search query on a string ‘str’ displays all the contacts which prefix 
as s. One special property of the search function is that, when a user searches for a contact from 
the contact list then suggestions (Contacts with prefix as the string entered so for) are shown after 
user enters each character.

Note : Contacts in the list consist of only lower case alphabets.
*/
#include <bits/stdc++.h>
using namespace std;

class TrieNode{
public:
	bool isLeaf;
	TrieNode *child[26];

	TrieNode(){
		isLeaf = false;
		for(int i = 0; i < 26; i++){
			child[i] = NULL;
		}
	}
};

void insert(TrieNode *root, string word){
	TrieNode *cur = root;

	for(int i = 0; i < word.size(); i++){
		int k = word[i]-'a';
		if(cur->child[k] == NULL){
			cur->child[k] = new TrieNode();
		}

		cur = cur->child[k];
	}

	cur->isLeaf = true;
}

void helper(TrieNode *root, string word, vector<string> &v){
	if(root->isLeaf){
		v.push_back(word);
	}

	for(int i = 0; i < 26; i++){
		if(root->child[i]){
			helper(root->child[i], word+char(i+'a'), v);
		}
	}
}

vector<vector<string>> displayContacts(int n, string contacts[], string s){
	//build trie using contact[] array of strings
	TrieNode *root = new TrieNode();
	for(int i = 0; i < n; i++){
		insert(root, contacts[i]);
	}

	//get contacts with same prefix for each prefix of string s
	vector<vector<string>> res;
	string prefix;
	TrieNode *prevNode = root;
	int i;
	for(i = 1; i <= s.size(); i++){
		vector<string> v;
		prefix = s.substr(0, i);
		char lastChar = prefix[i-1];

		TrieNode *cur = prevNode->child[lastChar-'a'];
		if(cur == NULL){
			break;
		}

		helper(cur, prefix, v);
		prevNode = cur;
		res.push_back(v);
	}

	for(; i<=s.size(); i++){
		res.push_back({"0"});
	}
	return res;
}

int main(){
	int n;
	cin >> n;
	string s;
	string contacts[n];
	for(int i = 0; i < n; i++){
		cin >> contacts[i];
	}
	cout << "Enter string: ";
	cin >> s;
	vector<vector<string>> res = displayContacts(n, contacts, s);
	for(auto v: res){
		for(string s: v){
			cout << s << " ";
		} cout << endl;
	}
	return 0;
}