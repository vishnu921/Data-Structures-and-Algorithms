/*
Given a Binary Tree with all unique values and two nodes value n1 and n2. The task is to find the lowest common ancestor of the given two nodes. We may assume that either both n1 and n2 are present in the tree or none of them is present.
*/
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

node *lca(node *root, int n1, int n2){
	if(root == NULL) return NULL;

	//if either n1 or n2 matches with root's data return the root
	if(root->data == n1 || root->data == n2)
		return root;

	node *leftans = lca(root->left, n1, n2);
	node *rightans = lca(root->right, n1, n2);

	//if both left and right return NON-NULL nodes that means
	//one node is in left subtree and other node is in right subtree
	//so the current node is the lowest common ancestor of n1 and n2 
	if(leftans != NULL && rightans != NULL) return root;

	//if left != NULL that means right == NULL hence
	// the LCA of n1 and is present in the left subtree
	//so return the leftans, else return rightans
	if(leftans != NULL) return leftans;
	else return rightans;
}

int main(){
	string s;
	getline(cin,s);
	node *root = buildTree(s);
	int n1, n2;
	cin >> n1 >> n2;
	node *res = lca(root, n1, n2);
	cout << "Lowest common ancestor: " << res->data << endl;
	return 0;
}