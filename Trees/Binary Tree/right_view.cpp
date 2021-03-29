//Given a Binary Tree, print left view of it. Left view of a Binary Tree is set of nodes visible when tree is visited from left side
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

void printRightView_util(node *root, int level, int &max_level){
	if(root == NULL) return;

	if(max_level < level){
		cout << root->data << " ";
		max_level = level;
	}

	printRightView_util(root->right, level+1, max_level);
	printRightView_util(root->left, level+1, max_level);
}

void printRightView(node *root){
	int max_level = 0;
	printRightView_util(root,1,max_level);
	cout << endl;
}

int main(){
	string s;
	getline(cin,s);
	node *root = buildTree(s);
	printRightView(root);
	return 0;
}