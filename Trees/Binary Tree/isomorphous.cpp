/*
Write a function to detect if two trees are isomorphic. Two trees are called isomorphic if one of them can be obtained from other by a series of flips, i.e. by swapping left and right children of a number of nodes. Any number of nodes at any level can have their children swapped. Two empty trees are isomorphic.
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

bool isIsomorphous(node *root1, node *root2){
	if(root1 == NULL && root2 == NULL) return true;
	if(root1 == NULL || root2 == NULL) return false;

	if(root1->data != root2->data) return false;

	return ((isIsomorphous(root1->left, root2->right) && isIsomorphous(root1->right, root2->left)) || (isIsomorphous(root1->left, root2->left) && isIsomorphous(root1->right, root2->right)));
}

int main(){
	string s1;
	string s2;
	getline(cin,s1);
	getline(cin,s2);
	node *root1 = buildTree(s1);
	node *root2 = buildTree(s2);
	if(isIsomorphous(root1,root2)){
		cout << "YES\n";
	}
	else{
		cout << "NO\n";
	}
	return 0;
}