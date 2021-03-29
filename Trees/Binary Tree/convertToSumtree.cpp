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

void ConvertToSumTree(node *root){
	if(root == NULL) return;
	int l = 0, r = 0, sum = 0;
	if(root->left){
		l = root->left->data;
	}
	if(root->right){
		r = root->right->data;
	}
	sum = l+r;

	ConvertToSumTree(root->left);
	ConvertToSumTree(root->right);

	if(root->left){
		l = root->left->data;
	}
	if(root->right){
		r = root->right->data;
	}

	root->data = sum+l+r;
}

void inorderTraversal(node *root){
	if(root == NULL) return;
	inorderTraversal(root->left);
	cout << root->data << " ";
	inorderTraversal(root->right);
}

int main(){
	string s;
	getline(cin,s);
	node *root = buildTree(s);
	ConvertToSumTree(root);
	inorderTraversal(root);
	return 0;
}