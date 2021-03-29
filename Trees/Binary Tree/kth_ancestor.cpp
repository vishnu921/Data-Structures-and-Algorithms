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

//temp is a temperory variable to keep track of node returned from previous calls during backtracking
node *temp = NULL;
node *kthAncestor(node *root, int a, int k){
	if(root == NULL) return NULL;

	if(root->data == a || (temp = kthAncestor(root->left, a, k)) || (temp = kthAncestor(root->right, a, k))){
		if(k > 0)
			k--;
		else if(k == 0){
			cout << "Kth ancestor: " << root->data;
			return NULL;
		}

		return root;
	}
	return NULL;
}

int main(){
	string s;
	getline(cin,s);
	node *root = buildTree(s);
	int a,k;
	cin >> a >> k;
	node *parent = kthAncestor(root,a,k);

	//if parent is not equal to NULL that means
	//we have backtracked upto root node of the tree and kth ancestor of 'a' doesn't exist
	if(parent) cout << "-1\n";
	return 0;
}