// Given a Binary Search Tree that contains positive integer values greater than 0. 
// The task is to check whether the BST contains a dead end or not. 
// Here Dead End means, we are not able to insert any integer element after that node.
// Input :        8
//              /   \
//            5      9
//          /   \
//         2     7
//        /
//       1
// Output : Yes
// Explanation : Node "1" is the dead End because
//          after that we cant insert any element.

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

node* insert(node* root, int x){
	if(root == NULL){
		root = new node(x);
	}
	else if(x < root->data){
		root->left = insert(root->left, x);
	}
	else{
		root->right = insert(root->right, x);
	}
	return root;
}

bool isDeadEnd(node *root, int min = 0, int max = INT_MAX){
	//if root == NULL that means dead does not exists
	if(root == NULL) return false;

	if(root->data-min == 1 && root->data-max == 1) return true;

	return isDeadEnd(root->left, min, root->data) || isDeadEnd(root->right, root->data, max);
}

int main()
{
	int n,x;
	cout << "Enter number of nodes: ";
	cin >> n;
	node *root = NULL;
	for(int i = 0; i < n; i++){
		cin >> x;
		root = insert(root, x);
	}
	if(isDeadEnd(root)){
		cout << "True\n";
	}
	else cout << "False\n";
	return 0;
}