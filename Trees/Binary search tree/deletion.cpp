//perform deletion operation in binary search tree
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

node *deletion(node *root, int x){
	if(root == NULL) return root;

	if(x < root->data){
		root->left = deletion(root->left, x);
	}
	else if(x > root->data){
		root->right = deletion(root->right, x);
	}
	else{
		if(root->left == NULL){
			node *temp = root->right;
			delete root;
			return temp;
		}
		else if(root->right == NULL){
			node *temp = root->left;
			delete root;
			return temp;
		}

		node *sucParent = root;
		node *suc = root->right;
		while(suc->left != NULL){
			sucParent = suc;
			suc = suc->left;
		}

		//now if sucParent == root that means either there is no successor or either root's right child is its successor
		//in this case the we make the suc's right child, the sucParent's right child
		//else if sucParent != root  that means successor other than the right child exists
		//in this case we can make the suc's right child, the sucParent's left child
		//because suc is the left child of sucParent
		if(sucParent != root){
			sucParent->left = suc->right;
		}
		else{
			sucParent->right = suc->right;
		}

		root->data = suc->data;
		delete suc;
		return root;
	}
	return root;
}

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
		cout << "1. Insert 2. Delete  3. Search  4. Show  5. Exit\n";
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
				cout << "Enter node to be Deleted: ";
				cin >> x;
				root = deletion(root, x);
				inorder(root);
				cout << endl;
				break;
			}
			case 3:{
				cout << "Enter key to search: ";
				cin >> x;
				node *key = search(root, x);
				if(key == NULL){
					cout << "Not FOUND\n";
				}
				else cout << "FOUND\n";
				break;
			}
			case 4:{
				inorder(root);
				cout << endl;
				break;
			}
		}
	}while(n != 5);
	return 0;
}