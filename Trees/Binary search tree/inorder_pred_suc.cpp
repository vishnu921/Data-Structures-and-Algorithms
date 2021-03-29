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

void findPreSuc(node *root, node* &pre, node* &suc, int key){
	if(root == NULL) return;

	if(root->data == key){
		if(root->left != NULL){
			node *temp = root->left;
			while(temp->right != NULL)
				temp = temp->right;
			pre = temp;
		}
		if(root->right != NULL){
			node *temp = root->left;
			while(temp->left != NULL)
				temp = temp->left;
			suc = temp;
		}
		return;
	}

	if(key < root->data){
		suc = root;
		findPreSuc(root->left, pre, suc, key);
	}
	else{
		pre = root;
		findPreSuc(root->right, pre, suc, key);
	}
}

void findPredecessor(node *root, node* &pre, int key){
	if(root == NULL) return;

	if(root->data == key){
		if(root->left != NULL){
			node *temp = root->left;
			while(temp->right != NULL){
				temp = temp->right;
			}
			pre = temp;
		}
		return;
	}

	if(key < root->data){
		findPredecessor(root->left, pre, key);
	}
	else{
		pre = root;
		findPredecessor(root->right, pre, key);
	}
}

void findSuccessor(node *root, node* &suc, int key){
	if(root == NULL) return;

	if(root->data == key){
		if(root->right != NULL){
			node *temp = root->right;
			while(temp->left != NULL){
				temp = temp->left;
			}
			suc = temp;
		}
		return;
	}

	if(key < root->data){
		suc = root;
		findSuccessor(root->left, suc, key);
	}
	else{
		findSuccessor(root->right, suc, key);
	}
}

int main(){
	int n,x;
	node *root = NULL;
	do{
		cout << "1. Insert 2. Search 3. Show  4. Predecessor  5. Successor  6. Pred and Suc 7. Exit\n";
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
				node *pre = NULL;
				findPredecessor(root, pre, x);
				if(pre)
					cout << pre->data << endl;
				else cout << -1 << endl;
				break;
			}
			case 5:{
				cout << "Enter key: ";
				cin >> x;
				node *suc = NULL;
				findSuccessor(root, suc, x);
				if(suc)
					cout << suc->data << endl;
				else cout << suc->data << endl;
				break;
			}
			case 6:{
				cout << "Enter key: ";
				cin >> x;
				node *pre = NULL;
				node *suc = NULL;
				findPreSuc(root, pre, suc, x);
				if(pre)
					cout << "Predecessor: " << pre->data << endl;
				else cout << -1 << endl;
				if(suc)
					cout << "Successor: " << suc->data << endl;
				else cout << -1 << endl;
				break;
			}
		}
	}while(n != 7);
	return 0;
}