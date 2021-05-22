/*
Huffman coding is a lossless data compression algorithm. The idea is to assign variable-length codes to input characters, 
lengths of the assigned codes are based on the frequencies of corresponding characters. The most frequent character gets 
the smallest code and the least frequent character gets the largest code.
*/
#include <bits/stdc++.h>
using namespace std;

class node{
public:
	char data;
	int freq;
	node *left, *right;

	node(char c, int f){
		data = c;
		freq = f;
		left = NULL;
		right = NULL;
	}
};

struct compare{
	bool operator()(node *a, node *b){
		return (a->freq > b->freq);
	}
};

void printcodes(node *root, string s){
	if(root == NULL) return;

	if(root->data != '$')
		cout << root->data << " : " << s << endl;

	printcodes(root->left, s+"0");
	printcodes(root->right, s+"1");
}

void huffmanCoding(string s, int f[], int n){
	priority_queue<node*, vector<node*>, compare> pq;
	for(int i = 0; i < n; i++){
		pq.push(new node(s[i], f[i]));
	}
	node *temp;

	while(pq.size() != 1){
		temp = new node('$', 0);
		temp->left = pq.top();
		pq.pop();

		temp->right = pq.top();
		pq.pop();

		temp->freq = temp->left->freq + temp->right->freq;
		pq.push(temp);
	}

	printcodes(temp,"");
}

int main(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	int f[n];
	for(int i = 0; i < n; i++) cin >> f[i];

	huffmanCoding(s, f, n);
	return 0;
}