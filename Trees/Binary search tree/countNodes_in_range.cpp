//Given a Binary Search Tree (BST) and a range, count number of nodes that lie in the given range.
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

int getCount(node *root, int l, int h){
	if(root == NULL) return 0;
	if(root->data == h && root->data == l){
		return 1;
	}

	if(root->data < l){
		return getCount(root->right, l, h);
	}
	else if(root->data > h){
		return getCount(root->left, l, h);
	}
	else{
		return 1+getCount(root->left, l, h)+getCount(root->right,l,h);
	}
}

int main(){
	string s;
	getline(cin,s);
	node *root = buildTree(s);
	cout << "Enter range separated by space: ";
	int l, h;
	cin >> l >> h;
	cout << getCount(root,l,h) << endl;
	return 0;
}