//Given an array of integers, replace every element with the least greater element on its right side in the array. 
//If there are no greater element on the right side, replace it with -1.
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

void insert(node* &root, int data, node* &succ){
	if(root == NULL){
		root = new node(data);
	}
	else if(data < root->data){
		succ = root;
		insert(root->left, data, succ);
	}
	else if(data > root->data){
		insert(root->right, data, succ);
	}
}

void replace(int a[], int n){
	node *root = NULL;

	//start from right to left
	for(int i = n-1; i>=0; i--){
		node *succ = NULL;
		//insert the current element into BST
		//and find its inorder successor
		insert(root, a[i], succ);
		if(succ)
			a[i] = succ->data;
		else
			a[i] = -1;
	}
}

int main(){
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	replace(a, n);
	for(int i = 0; i < n; i++){
		cout << a[i] << " ";
	}
	return 0;
}