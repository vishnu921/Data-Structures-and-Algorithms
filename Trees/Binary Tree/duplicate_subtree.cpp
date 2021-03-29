//Given a binary tree, find out whether it contains a duplicate sub-tree of size two or more, or not.
#include <bits/stdc++.h>
using namespace std;

class node{
public:
	char data;
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

string dupsubUtil(node *root, unordered_set<string> &subtree){
	//if root == NULL then return $ to show that this part of the subtree is NULL
	if(root == NULL) return "$";

	string s = "";

	//find left subtree, if leftsubtree contains duplicate subtrees then l will be empty string
	string l = dupsubUtil(root->left, subtree);
	if(l.length() == 0) return s;

	//similarly do it for right subtree
	string r = dupsubUtil(root->right, subtree);
	if(r.length() == 0) return s;

	//serialize the current tree
	s = root->data+l+r;

	//length of s in leaf node is 3(1 char for root node and 2 char for "$"(NULL))
	//if s is already present in the set then return empty string indicating duplicate subtree is found
	if(s.length() > 3 && subtree.find(s) != subtree.end()){
		return "";
	}

	//else insert the current subtree in the set and return it
	subtree.insert(s);

	return s;
}

bool dupSub(node *root){
	if(root==NULL) return false;
	unordered_set<string> subtree;
	string s = dupsubUtil(root, subtree);
	if(s.length() == 0) return true;
	return false;
}

int main(){
	string s;
	getline(cin,s);
	node *root = buildTree(s);
	if(dupSub(root)) cout << "Duplicate subtree exists\n";
	else cout << "Duplicate subtree doesn't exists\n";
	return 0;
}