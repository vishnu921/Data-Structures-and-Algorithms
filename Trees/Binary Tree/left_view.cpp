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

void printLeftView(node *root){
	if(root == NULL) return;
	queue<node *> q;
	q.push(root);

	while(!q.empty()){
		int n = q.size();
		for(int i = 1; i <= n; i++){
			node *cur = q.front();
			q.pop();

			if(i == 1) cout << cur->data << " ";

			if(cur->left) q.push(cur->left);
			if(cur->right) q.push(cur->right);
		}
	}
	cout << endl;
}

int main(){
	string s;
	getline(cin,s);
	node *root = buildTree(s);
	printLeftView(root);
	return 0;
}