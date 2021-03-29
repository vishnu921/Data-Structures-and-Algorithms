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

bool isBSTutil(node *root, int min, int max){
	if(root == NULL) return true;

	//min and max is the allowed range of the value in root
	if(root->data <= min || root->data >= max)
		return false;

	//for the left subtree the min value does not changes but the max value allowed will be root->data
	//similarly for the right subtree the max value is same and the min value allowed = root->data
	return (isBSTutil(root->left, min, root->data) && isBSTutil(root->right, root->data, max));
}

bool isBST(node *root){
	//here we are using a utility function which takes 3 arguments:
	//1. root node
	//2. min(INT_MIN) this the minimum value allowed for the root node(root->data must be > min)
	//3. max(INT_MAX) this the maximum value allowed for the root node(root->data must be < max)
	return isBSTutil(root, INT_MIN, INT_MAX);
}

int main(){
	string s;
	getline(cin,s);
	node *root = buildTree(s);
	if(isBST(root)){
		cout << "It is a binary search tree\n";
	}
	else cout << "NOT a BST\n";
	return 0;
}