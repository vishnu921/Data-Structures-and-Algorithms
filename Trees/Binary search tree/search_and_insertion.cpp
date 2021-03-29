//perform search and insertion operation in a binary search tree
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

node *search(node *root, int key){
	if(root == NULL) return NULL;

	if(root->data == key) return root;

	if(key < root->data){
		return search(root->left, key);
	}

	return search(root->right, key);
}

void inorder(node *root){
	if(root == NULL) return;
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

int main(){
	int n,x;
	node *root = NULL;
	do{
		cout << "1. Insert 2. Search 3. Show 4. Exit\n";
		cin >> n;
		switch(n){
			case 1:{
				cout << "Enter node: ";
				cin >> x;
				root = insert(root, x);
				inorder(root);
				cout << endl;
				break;
			}
			case 2:{
				cout << "Enter key to search: ";
				cin >> x;
				node *key = search(root, x);
				if(key == NULL){
					cout << "Not FOUND\n";
				}
				else cout << "FOUND\n";
				break;
			}
			case 3:{
				inorder(root);
				cout << endl;
				break;
			}
		}
	}while(n != 4);
	return 0;
}