// Given a Binary Tree, write a function to populate next pointer for all nodes. The next pointer for every node should be set to point to inorder successor.
#include <bits/stdc++.h>
using namespace std;

class node{
public:
	int data;
	node *left;
	node *right; 
	node *next;

	node(int x){
		data = x;
		left = NULL;
		right = NULL;
		next = NULL;
	}
};

node *buildTree(string s){
	if(s.length() == 0 || s[0] == 'N') return NULL;
	vector<string> ip;

	istringstream iss(s);
	for(string s; iss >> s;) ip.push_back(s);

	node *root = new node(stoi(ip[0]));

	queue<node *> queue;
	queue.push(root);

	int i = 1;
	while(!queue.empty() && i < ip.size()){
		node *cur = queue.front();
		queue.pop();

		string currval = ip[i];
		if(currval != "N"){
			cur->left = new node(stoi(currval));
			queue.push(cur->left);
		}

		i++;
		if(i >= ip.size()) break;
		currval = ip[i];

		if(currval != "N"){
			cur->right = new node(stoi(currval));
			queue.push(cur->left);
		}
		i++;
	}
	return root;
}

void print_successor(node *root){
	while(root->left != NULL)
		root = root->left;
	while(root != NULL){
		cout << root->data << "->" << (root->next?root->next->data:-1) << " ";
		root = root->next;
	}
}

void populate(node *root, node* &prev){
	if(root == NULL) return;
	populate(root->left, prev);

	if(prev != NULL){
		prev->next = root;
	}
	prev = root;
	populate(root->right, prev);
}

void populate_inorder_successor(node *root){
	node *prev = NULL;
	populate(root, prev);
	prev->next = NULL;
}

int main(){
	string s;
	getline(cin,s);
	node *root = buildTree(s);
	populate_inorder_successor(root);
	print_successor(root);
	return 0;
}