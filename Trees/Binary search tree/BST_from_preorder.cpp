//Given preorder traversal of a binary search tree, construct the BST.
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

node *buildUtil(vector<int> &pre, int &preIndex, int min, int max){
	if(preIndex >= pre.size()) return NULL;

	int val = pre[preIndex];
	if(val < min || val > max) return NULL;

	node *root = new node(val);
	preIndex++;

	root->left = buildUtil(pre, preIndex, min, val-1);
	root->right = buildUtil(pre, preIndex, val+1, max);

	return root;
}

node *BuildBSTfromPreorder(vector<int> &pre){
	int preIndex = 0;
	return buildUtil(pre, preIndex, INT_MIN, INT_MAX);
}

void inorder(node *root){
	if(root == NULL) return;
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

int main(){
	int n;
	cin >> n;
	vector<int> pre;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		pre.push_back(x);
	}
	node *root = BuildBSTfromPreorder(pre);
	inorder(root);
	return 0;
}