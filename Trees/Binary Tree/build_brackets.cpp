#include <bits/stdc++.h>
using namespace std;

class node{
public:
	int data;
	node *left;
	node *right;

	node(int x){
		data = x;
		left = NULL;
		right = NULL;
	}
};

int findIndex(string s, int si, int ei){
	if(si > ei) return -1;

	stack<char> st;
	for(int i = si; i <= ei; i++){
		if(s[i] == '(')
			st.push(s[i]);
		else if(s[i] == ')'){
			if(st.top() == '('){
				st.pop();
				if(st.empty()) return i;
			}
		}
	}
	return -1;
}

node *buildTree(string s,int si, int ei){
	if(si > ei) return NULL;

	node *root = new node(s[si]-'0');
	int index = -1;

	if(si+1 <= ei && s[si+1] == '(')
		index = findIndex(s, si+1, ei);

	if(index != -1){
		root->left = buildTree(s, si+2, index-1);
		root->right = buildTree(s, index+2, ei-1);
	}

	return root;
}

void preorder(node *root){
	if(root == NULL) return;
	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);
}

int main(){
	string s;
	cin >> s;
	node *root = buildTree(s, 0, s.length()-1);
	preorder(root);
	return 0;
}