//inorder predecessor and successor of a given key in binary search tree
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

node *findMaximum(node *root){
	if(root == NULL) return NULL;
	while(root->right != NULL){
		root=root->right;
	}
	return root;
}

node *findMin(node *root){
	if(root == NULL) return NULL;
	while(root->left != NULL){
		root = root->left;
	}
	return root;
}

node* findPredecessor(node *root, int key){
	if(root == NULL) return NULL;
	node *pred = NULL;
	while(1){
		if(key < root->data){
			root = root->left;
		}
		else if(key > root->data){
			pred = root;
			root = root->right;
		}
		else{
			if(root->left != NULL){
				pred = findMaximum(root->left);
			}
			break;
		}
		if(root == NULL) return NULL;
	}
	return pred;
}

node* findSuccessor(node *root, int key){
	if(root == NULL) return NULL;
	node *suc = NULL;
	while(1){
		if(key < root->data){
			suc = root;
			root = root->left;
		}
		else if(key > root->data){
			root = root->right;
		}
		else{
			if(root->right != NULL){
				suc = findMin(root->right);
			}
			break;
		}
		if(root == NULL) return NULL;
	}
	return suc;
}

int main(){
	int n,x;
	node *root = NULL;
	do{
		cout << "1. Insert 2. Search 3. Show  4. Predecessor  5. Successor  6. Exit\n";
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
			case 4:{
				cout << "Enter key: ";
				cin >> x;
				node *pre = findPredecessor(root, x);
				if(pre)
					cout << pre->data << endl;
				else cout << -1 << endl;
				break;
			}
			case 5:{
				cout << "Enter key: ";
				cin >> x;
				node *suc = findSuccessor(root, x);
				if(suc)
					cout << suc->data << endl;
				else cout << -1 << endl;
				break;
			}
		}
	}while(n != 6);
	return 0;
}