//Given a binary tree, task is to find subtree with maximum sum in tree.
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

int LargestSubtreeSumUtil(node *root, int &res){
	if(root == NULL) return 0;
	int cursum = root->data+LargestSubtreeSumUtil(root->left, res)+LargestSubtreeSumUtil(root->right,res);
	res = max(res,cursum);
	return cursum;
}

int LargestSubtreeSum(node *root){
	if(root == NULL) return 0;
	int res = INT_MIN;
	int cur = LargestSubtreeSumUtil(root, res);
	return res;
}

int main(){
	string s;
	getline(cin,s);
	node *root = buildTree(s);
	cout << LargestSubtreeSum(root);
	return 0;
}