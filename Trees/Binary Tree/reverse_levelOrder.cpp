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

//difference in normal level order traversal and reversed level ordered traversal are:
// 1. instead of printing we push the element into the stack
// 2. Right subtree is pushed into the queue before left subtree
void reverseOrderedTraversal(node *root){
	if(root == NULL){
		return;
	}
	queue<node *> q;
	stack<node *> s;
	q.push(root);
	while(!q.empty()){
		root = q.front();
		q.pop();
		s.push(root);
		if(root->right != NULL) q.push(root->right);      //this is the important step right subtree is pushed firts
		if(root->left != NULL) q.push(root->left);
	}

	while(!s.empty()){
		root = s.top();
		cout << root->data << " ";
		s.pop();
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
	reverseOrderedTraversal(root);
	return 0;
}