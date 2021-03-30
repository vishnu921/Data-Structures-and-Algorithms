//return the size of largest BST in the given binary tree
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
			queue.push(cur->right);
		}
		i++;
	}
	return root;
}

class bst{
public:
	//this size is the size of largest BST upto current root
	int size;
	int min;
	int max;

	bst(){size = 0; min = 0; max = 0;}
};

bool isBST(node *root, bst &my){
	if(root == NULL){
		my.min = INT_MAX;
		my.max = INT_MIN;
		return true;
	}

	bst left, right;
	bool l = isBST(root->left, left);
	bool r = isBST(root->right, right);

	//if both left and right subtree BST
	//and root is also a BST as a node
	if(l && r && root->data > left.max && root->data < right.min){
		my.size = 1+left.size+right.size;
		my.min = min(root->data, left.min);
		my.max = max(root->data, right.max);
		return true;
	}

	//else return false
	//and set the size of largest bst upto current root to max of left and right size
	my.min = left.min;
	my.max = right.max;
	my.size = max(left.size, right.size);
	return false;
}

int largestBST(node *root){
	if(root == NULL) return 0;
	//this object will contain the data about largest bst till current root
	bst mine;
	bool check = isBST(root, mine);
	return mine.size;

}

int main(){
	string s;
	getline(cin,s);
	node *root = buildTree(s);
	cout << largestBST(root) << endl;
	return 0;
}