/*
Given a binary search tree which is also a complete binary tree. The problem is to convert the given 
BST into a Min Heap with the condition that all the values in the left subtree of a node should be less 
than all the values in the right subtree of the node. This condition is applied on all the nodes in the 
so converted Min Heap. 
*/
#include <bits/stdc++.h>
using namespace std;

class node{
public:
	int data;
	node *left, *right;

	node(int x){
		data = x;
		left = NULL;
		right = NULL;
	}
};

node *buildTree(string s){
	if(s.length() == 0 || s[0] == 'N') return NULL;
	vector<string> ip;

	istringstream iss(s);
	for(string s; iss >> s;) ip.push_back(s);

	node *root = new node(stoi(ip[0]));

	queue<node *> queue;
	queue.push(root);

	int i = 1;
	while(!queue.empty() && i < ip.size()){
		node *cur = queue.front();
		queue.pop();
		
		string currval = ip[i];
		
		if(currval != "N"){
			cur->left = new node(stoi(currval));
			queue.push(cur->left);
		}

		i++;
		if(i >= ip.size()) break;
		currval = ip[i];
		
		if(currval != "N"){
			cur->right = new node(stoi(currval));
			queue.push(cur->right);
		}
		i++;
	}
	return root;
}

void inorder(node *root, vector<int> &a){
	if(root == NULL) return;

	inorder(root->left, a);
	a.push_back(root->data);
	inorder(root->right, a);
}

void bstTOminheap(node *root, vector<int> &a, int &i){
	if(root == NULL) return;

	i++;
	root->data = a[i];
	bstTOminheap(root->left, a, i);
	bstTOminheap(root->right, a, i);
}

void convertToMinheap(node *root){
	if(root == NULL) return;

	vector<int> a;
	//store inorder traversal of BST in array
	inorder(root,a);

	//now copy array elements to nodes from start in preorder manner
	int i = -1;
	bstTOminheap(root,a,i); 
}

void preorder(node *root){
	if(root == NULL) return;

	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);
}

int main(){
	string s;
	getline(cin, s);
	node *root = buildTree(s);

	convertToMinheap(root);
	//preorder should give sorted array
	preorder(root);
	return 0;
}