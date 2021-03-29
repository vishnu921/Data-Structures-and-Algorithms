//check if the given binary tree is balanced or not 
/*
A balanced tree satisfy following constraints:
1. the heights of left subtree and right subtree differ by atmost 1
2. left subtree is balanced, and
3. right subtree is balanced
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

//this is an efficient solution in which we calculate the height simultaneously while checking the balance condition
bool isBalanced_Util(node *root, int &height){
	//empty tree has height = 0 and is always balanced so return true
	if(root == NULL){
		height = 0; 
		return true;
	}

	int lh = 0, rh = 0;
	bool l = false, r = false;

	//here lh and rh are passed by reference so their values will be updated accordingly
	l = isBalanced_Util(root->left, lh);
	r = isBalanced_Util(root->right, rh);

	height = max(lh,rh) + 1;

	//if current node fail the first property then return false
	if(abs(lh-rh) > 1) return false;

	//since the current node satisfies the 1st property
	//now we check if both left and right subtree are balanced return true else return false 
	else return (l && r);
}

bool isBalanced(node *root){
	if(root == NULL) return true;

	int h = 0;
	return isBalanced_Util(root, h);
}

int main(){
	string s;
	getline(cin,s);
	node *root = buildTree(s);
	if(isBalanced(root)){
		cout << "Tree is balanced\n";
	}
	else
		cout << "Tree is Unbalanced\n";
	return 0;
}