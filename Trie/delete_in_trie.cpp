//implement delete operation in trie

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

/*
During delete operation we delete the key in bottom up manner using recursion. The following are possible 
conditions when deleting key from trie, 

    1. Key may not be there in trie. Delete operation should not modify trie.
    2. Key present as unique key (no part of key contains another key (prefix), nor the key itself is 
       prefix of another key in trie). Delete all the nodes.
    3. Key is prefix key of another long key in trie. Unmark the leaf node.
    4. Key present in trie, having atleast one other key as prefix key. Delete nodes from end of key 
       until first leaf node of longest prefix key.
*/
//function to check if a node has children or not
bool isEmpty(TrieNode *root){
	for(int i = 0; i < 26; i++){
		if(root->children[i]) return false;
	}

	return true;
}

//function to remove a word from Trie
TrieNode *remove(TrieNode* root, string word, int i = 0){
	if(!root) return NULL;

	if(i == word.size()){

		//if the given word end at current TrieNode mark it false
		if(root->isEndOfWord)
			root->isEndOfWord = false;

		//now no word ends at current node and if it is not prefix of
		//another key delete it
		if(isEmpty(root)){
			delete root;
			root = NULL;
		}

		return root;
	}

	//recur of further characters in key
	int k = word[i] - 'a';
	root->children[k] = remove(root->children[k], word, i+1);

	//after recursion if current node has no children and no word ends at
	//current node we delete it
	if(isEmpty(root) && root->isEndOfWord == false){
		delete root;
		root = NULL;
	}

	return root;
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
		cout << "Enter word to delete: ";
		cin >> s;
		if(s == "-1") break;
		root = remove(root, s);
		cout << "Deleted\n";
	}
	return 0;
}