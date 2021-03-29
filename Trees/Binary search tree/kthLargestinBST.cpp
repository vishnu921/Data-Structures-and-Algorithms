//Given a Binary search tree. Your task is to complete the function which will return the Kth largest element without doing any modification in Binary Search Tree.
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

void kthLargestUtil(node *root, int &k, int &ans){
	if(root == NULL) return;
	kthLargestUtil(root->right, k, ans);
	k--;
	if(k == 0){
		ans = root->data;
		return;
	}
	kthLargestUtil(root->left, k, ans);
}

int kthLargest(node *root, int k){
	if(root == NULL) return -1;
	int ans = -1;
	kthLargestUtil(root, k, ans);
	return ans;
}

int main(){
	string s;
	getline(cin,s);
	node *root = buildTree(s);
	cout << "Enter k: ";
	int k;
	cin >> k;
	cout << kthLargest(root,k) << endl;
	return 0;
}