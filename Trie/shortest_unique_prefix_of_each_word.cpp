/*
Given an array of words, find all shortest unique prefixes to represent each word in the given array. 
Assume that no word is prefix of another.
*/


#include <bits/stdc++.h>
using namespace std;

class TrieNode{
public:
	TrieNode *children[26];
	bool isEndOfWord;
	int freq;

	TrieNode(){
		isEndOfWord = false;
		freq = 0;
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
		cur->freq++;                  //frequency of each node is the number of time it is visited in insertions
	}

	cur->isEndOfWord = true;
}

//function to return length of shortest common prefix for each word
int search(TrieNode *root, string word){
    TrieNode *cur = root;
    
    for(int i = 0; i < word.length(); i++){
        int k = word[i]-'a';
        cur = cur->children[k];
        //as soon as we find freq of a node to be 1 we return the (i+1) value 
        //where i is the index of character matching that node and (i+1) is the length of prefix 
        if(cur->freq == 1) return i+1;
    }
    
    return -1;
}


vector<string> findPrefixes(string arr[], int n)
{
    /*
    to solve this problem we build a special Trie in which each node has
    a freq variable which indicates the number of prefixes ending at that node in the trie
    */
    TrieNode *root = new TrieNode();
    for(int i = 0; i < n; i++){
        insert(root, arr[i]);
    }
    
    vector<string> res;
    
    for(int i = 0; i < n; i++){
        int len = search(root, arr[i]);
        res.push_back(arr[i].substr(0, len));
    }
    
    return res;
}

int main(){
    int n;
    cin >> n;
    string arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    vector<string> res = findPrefixes(arr, n);
    for(auto prefix: res){
        cout << prefix << " ";
    } cout << endl;
    return 0;
}