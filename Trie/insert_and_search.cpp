#include <bits/stdc++.h>
using namespace std;

class TrieNode{
public:
	TrieNode *children[26];
	bool isEndOfWord;

	TrieNode(){
		isEndOfWord = false;
		for(int i = 0; i < 26; i++){
			children[i] = NULL;
		}
	}
};

void insert(TrieNode *root, string word){
	TrieNode *cur = root;

	for(int i = 0; i < word.length(); i++){
		int k = word[i]-'a';
		if(cur->children[k] == NULL){
			cur->children[k] = new TrieNode();
		}

		cur = cur->children[k];
	}

	cur->isEndOfWord = true;
}

bool search(TrieNode *root, string word){
	TrieNode *cur = root;

	for(int i = 0; i < word.length(); i++){
		int k = word[i] - 'a';
		if(cur->children[k] == NULL)
			return false;

		cur = cur->children[k];
	}

	return (cur->isEndOfWord);
}

int main(){
	TrieNode *root = new TrieNode();
	int n;
	cin >> n;
	string s;
	for (int i = 0; i < n; i++){
		cin >> s;
		insert(root, s);
	}

	while(1){
		cout << "Enter word to search: ";
		cin >> s;
		if(s == "-1") break;
		if(search(root, s)){
			cout << "YES\n";
		} else{
			cout << "NO\n";
		}
	}
	return 0;
}