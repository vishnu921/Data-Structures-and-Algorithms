//Given a BST (Binary Search Tree) that may be unbalanced, convert it into a balanced BST that has minimum possible height.
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

node* insert(node *root, int x){
	if(root == NULL){
		node *temp = new node(x);
		return temp;
	}

	if(x < root->data){
		root->left = insert(root->left, x);
	}
	else if(x > root->data){
		root->right = insert(root->right, x);
	}

	return root;
}

int height(node *root){
	if(root == NULL) return -1;
	int lh = height(root->left);
	int rh = height(root->right);

	return max(lh,rh)+1;
}

void fill_array(node *root, vector<node *> &res){
	if(root == NULL) return;
	fill_array(root->left, res);
	res.push_back(root);
	fill_array(root->right, res);
}

node *buildTree(vector<node*>res, int l, int r){
	if(l > r) return NULL;

	int mid = (l+r)/2;
	node *root = res[mid];

	root->left = buildTree(res, l, mid-1);
	root->right = buildTree(res, mid+1, r);
	return root;
}

node* balanceTheBST(node *root){
	if(root == NULL) return NULL;
	vector<node*> res;
	fill_array(root, res);
	int n = res.size();
	return buildTree(res, 0, n-1);
}

void preorder(node *root){
	if(root == NULL) return;
	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);
}

int main(){
	int n;
	cout << "Enter number of nodes: ";
	cin >> n;
	node *root = NULL;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		root = insert(root, x);
	}
	cout << "Before balancing height: ";
	cout << height(root) << endl;
	cout << "preorder: ";
	preorder(root);
	cout << endl;
	node *res = balanceTheBST(root);
	cout << "After balancing height: ";
	cout << height(res) << endl;
	cout << "preorder: ";
	preorder(res);
	cout << endl;
	return 0;
}