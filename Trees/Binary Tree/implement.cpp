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

class BinaryTree{
	node *root;
public:
	BinaryTree(){
		root = NULL;
	}

	//Level order insertion 
	void insertLevelOrder(int x){
		node *temp = new node(x);
		if(root == NULL){
			root = temp;
			return;
		}

		queue<node *> q;
		q.push(root);
		while(!q.empty()){
			node *cur = q.front();
			q.pop();

			if(cur->left != NULL){
				q.push(cur->left);
			}
			else{
				cur->left = temp;
				return;
			}

			if(cur->right != NULL){
				q.push(cur->right);
			}
			else{
				cur->right = temp;
				return;
			}
		}
	}

	void display_LevelOrder(){
		if(root == NULL){
			return;
		}
		queue<node *> q;
		q.push(root);
		while(!q.empty()){
			node *temp = q.front();
			q.pop();

			if(temp->left != NULL) q.push(temp->left);
			if(temp->right != NULL) q.push(temp->right);
			cout << temp->data << " ";
		}
		cout << endl;
	}
};

int main()
{
	BinaryTree bt;
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		bt.insertLevelOrder(x);
	}
	bt.display_LevelOrder();
	return 0;
}