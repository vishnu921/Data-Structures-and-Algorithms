/*
1) Create an empty Trie 
2) One by one take all words of input sequence. Do following for each word 
	a) Copy the word to a string s. 
	b) Sort s 
	c) Insert the sorted s and index of this word to Trie. Each leaf node of Trie is head of a Index list. 
		The Index list stores index of words in original sequence. If sorted s is already present, we insert 
		index of this word to the index list. 
3) Traverse Trie. While traversing, if you reach a leaf node, traverse the index list. And print all words 
using the index obtained from Index list. 
*/

#include <bits/stdc++.h>
using namespace std;

class Node{
public:
	int index;
	Node *next;

	Node(int i){
		index = i;
		next = NULL;
	}
};

class TrieNode{
public:
	bool isLeaf;
	TrieNode *children[26];
	Node *head;

	TrieNode(){
		isLeaf = false;
		head = NULL;
		for(int i = 0; i < 26; i++){
			children[i] = NULL;
		}
	}
};

void insert(TrieNode *root, string word, int i){
	TrieNode *cur = root;

	for(int i = 0; i < word.size(); i++){
		int k = word[i] - 'a';
		if(cur->children[k] == NULL){
			cur->children[k] = new TrieNode();
		}

		cur = cur->children[k];
	}

	if(cur->isLeaf){
		Node *newNode = new Node(i);
		newNode->next = cur->head;
		cur->head = newNode;
	} else{
		cur->isLeaf = true;
		cur->head = new Node(i);
	}
}

void groupAnagramsUtil(TrieNode *root, vector<string> &strs, vector<vector<string>> &res){
	//base case
	if(root == NULL) return;

	//if a string ends at root then we traverse its index list
	//this index list contains indexes of one group of anagrams
	//store this group of anagrams in res vector
	if(root->isLeaf){
		Node *cur = root->head;
		vector<string> v;
		while(cur){
			v.push_back(strs[cur->index]);
			cur = cur->next;
		}

		res.push_back(v);
	}

	//now recur for further nodes
	for(int i = 0; i < 26; i++){
		groupAnagramsUtil(root->children[i], strs, res);
	}
}

vector<vector<string>> GroupAnagrams(vector<string> &strs, int n){
	TrieNode *root = new TrieNode();

	//Build trie
	for(int i = 0; i < n; i++){
		string s = strs[i];
		sort(s.begin(), s.end());

		insert(root, s, i);
	}

	//fill the result array with group of anagrams using groupAnagramsUtil function
	vector<vector<string>> res;
	groupAnagramsUtil(root, strs, res);
	return res;
}

int main(){
	int n;
	cin >> n;
	vector<string> strs(n);
	for(int i = 0; i < n; i++){
		cin >> strs[i];
	}

	vector<vector<string>> res = GroupAnagrams(strs, n);
	for(auto v: res){
		for(string s: v){
			cout << s << " ";
		} cout << endl;
	}
	return 0;
}