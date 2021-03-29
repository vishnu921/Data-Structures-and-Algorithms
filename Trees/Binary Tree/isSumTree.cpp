//check if a binary tree is a sum tree
//Sum tree is a binary tree in which each node except leaf node represent sum of left subtree and right subtree
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

bool isleaf(node *root){
	if(root == NULL) return false;
	if(!root->left && !root->right) return true;
	return false;
}

bool isSumtree(node *root){
	if(root==NULL || isleaf(root)) return true;

	//lsum and rsum stores the sum of left subtee and right subtree
	int lsum, rsum;

	//if a node is a leaf node then the sum of subtree formed when current node is root node is the data of this node
	//else sum is twice the data of the current node assuming the subtree is sumtree
	if(isSumtree(root->left) && isSumtree(root->right)){
		if(root->left == NULL) lsum = 0;
		else if(isleaf(root->left)) lsum = root->left->data;
		else lsum = 2*root->left->data;

		if(root->right == NULL) rsum = 0;
		else if(isleaf(root->right)) rsum = root->right->data;
		else rsum = 2*root->right->data;

		return (root->data == lsum+rsum);
	}
	return false;
}

int main(){
	string s;
	getline(cin,s);
	node *root = buildTree(s);
	if(isSumtree(root)){
		cout << "It is sumtree\n";
	}
	else cout << "Not a sumtree\n";
	return 0;
}