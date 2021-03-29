/*
In a threaded binary tree, we make all the right/left pointers which were normally NULL pointers
point to there inorder successor/predecessors
*/
#include <bits/stdc++.h>
using namespace std;

class node{
public:
	int data;
	node *left;
	node *right;
	//true if points to inorder predecessor
	bool lthread;
	//true if points to inorder successor
	bool rthread;

	node(int x){
		data = x;
		left = NULL;
		right = NULL;
		lthread = true;
		rthread = true;
	}
};

node *insert(node *root, int key){
	node *ptr = root;
	node *par = NULL;  //parent of the key to be inserted
	while(ptr != NULL){
		if(key == ptr->data){
			cout << "Duplicate key\n";
			return root;
		}

		par = ptr;
		if(key < ptr->data){
			if(ptr->lthread == false){
				ptr = ptr->left;
			}
			else break;
		}
		else{
			if(ptr->rthread == false){
				ptr = ptr->right;
			}
			else break;
		}
	}

	node *temp = new node(key);
	//insertion to empty tree
	if(par == NULL){
		root = temp;
	}
	else if(key < par->data){
		temp->left = par->left;
		temp->right = par;
		par->lthread = false;
		par->left = temp;
	}
	else{
		temp->left = par;
		temp->right = par->right;
		par->rthread = false;
		par->right = temp;
	}
	return root;
}

node *leftMost(node *n){
	if(n == NULL) return NULL;

	while(n->left != NULL){
		n = n->left;
	}
	return n;
}

node *inorderSuccessor(node *ptr){
	if(ptr->rthread == true){
		return ptr->right;
	}
	ptr = ptr->right;
	while(ptr->lthread == false){
		ptr = ptr->left;
	}
	return ptr;
}

void inorder(node *root){
	if(root == NULL) return;
	node *ptr = root;
	while(ptr->lthread == false)
		ptr = ptr->left;

	while(ptr != NULL){
		cout << ptr->data << " ";
		ptr = inorderSuccessor(ptr);
	}
}

int main(){
	int n;
	cin >> n;
	node *root = NULL;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		root = insert(root, x);
	}
	inorder(root);
	return 0;
}