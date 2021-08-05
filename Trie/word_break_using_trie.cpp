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

//utility function to solve word break using trie
bool wordBreakUtil(string s, TrieNode* root){
	//base case if string is empty then return true;
	if(s.empty()) return true;

	for(int len = 1; len <= s.size(); len++){
		//search if prefix of length 'len' is present in trie made from wordDict
		//if yes then recur for wordBreakUtil for other part of string
		//else check for other prefixes
		if(search(root, s.substr(0, len)) && wordBreakUtil(s.substr(len), root)){
			return true;
		}
	}

	return false;
}

bool wordBreak(string s, vector<string> &wordDict){
	//first we build trie using the given dictionary
	TrieNode* root = new TrieNode();
	for(string word: wordDict){
		insert(root, word);
	}

	//then we search in trie
	return wordBreakUtil(s, root);
}

int main(){
	int n;
	string s;
	cin >> n;
	vector<string> wordDict(n);
	for(int i = 0; i < n; i++){
		cin >> wordDict[i];
	}
	cout << "Enter string: ";
	cin >> s;
	if(wordBreak(s, wordDict)){
		cout << "YES\n";
	} else{
		cout << "NO\n";
	}
	return 0;
}