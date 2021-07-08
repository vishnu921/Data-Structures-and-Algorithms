/*
In this program we implement the 3 DFS traversals in the binary tree
1. Inorder
2. Preorder
3. Postorder
*/
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

node *insertLevelorder(node *root, int x){
	node *temp = new node(x);
	if(root == NULL){
		root = temp;
		return root;
	}
	queue<node *> q;
	q.push(root);
	while(!q.empty()){
		node *cur = q.front(); q.pop();
		if(cur->left != NULL) q.push(cur->left);
		else{
			cur->left = temp;
			break;
		}

		if(cur->right != NULL) q.push(cur->right);
		else{
			cur->right = temp;
			break;
		}
	}
	return root;
}

//inordered traversal(LDR) recursion
void inorderTraversal(node *root){
	if(root == NULL) return;
	inorderTraversal(root->left);
	cout << root->data << " ";
	inorderTraversal(root->right);
}

//inorder traversal iterative
void inorderIterative(node *root){
	stack<node *> s;
	node *cur = root;

	while(!s.empty() || cur != NULL){
		if(cur != NULL){
			s.push(cur);
			cur = cur->left;
		}
		else{
			cur = s.top();
			s.pop();
			cout << cur->data << " ";
			cur = cur->right;
		}
	}
	cout << endl;
}

//preorder traversal(DLR) recursive
void PreorderTraversal(node *root){
	if(root == NULL) return;
	cout << root->data << " ";
	PreorderTraversal(root->left);
	PreorderTraversal(root->right);
}

//preorder traversal iterative
void PreorderIterative(node *root){
	if(root == NULL) return;
	stack<node *> s;
	s.push(root);

	while(!s.empty()){
		node *cur = s.top();
		s.pop();
		cout << cur->data << " ";

		if(cur->right) s.push(cur->right);
		if(cur->left) s.push(cur->left);
	}
	cout << endl;
}

//postorder traversal(LRD)
void PostorderTraversal(node *root){
	if(root == NULL) return;
	PostorderTraversal(root->left);
	PostorderTraversal(root->right);
	cout << root->data << " ";
}

//postorder traversal iterative
void PostorderIterative(node *root){
	if(root == NULL) return;

	stack<node *> s;
	stack<int> output;
	s.push(root);

	while(!s.empty()){
		node *cur = s.top();
		s.pop();
		output.push(cur->data);

		if(cur->left) s.push(cur->left);
		if(cur->right) s.push(cur->right);
	}

	while(!output.empty()){
		cout << output.top() << " ";
		output.pop();
	}
	cout << endl;
}

//postorder using one stack
void PostorderIterative_oneStack(node *root){
	if(root == NULL) return;
	stack<node *> s;
	node *cur = root;
	node *prev = NULL;
	while(cur != NULL || !s.empty()){
		if(cur != NULL){
			s.push(cur);
			cur = cur->left;
		}
		else{
			cur = s.top();
			if(cur->right == NULL || cur->right == prev){
				cout << cur->data << " ";
				s.pop();
				prev = cur;
				cur = NULL;
			}
			else{
				cur = cur->right;
			}
		}
	}
	cout << endl;
}

int main(){
	int n;
	cin >> n;
	node *root = NULL;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		root = insertLevelorder(root, x);
	}
	cout << "Inorder traversal: ";
	inorderTraversal(root);
	cout << endl;
	cout << "Preorder traversal: ";
	PreorderTraversal(root);
	cout << endl;
	cout << "Postorder traversal: ";
	PostorderTraversal(root);
	cout << endl;
	return 0;
}