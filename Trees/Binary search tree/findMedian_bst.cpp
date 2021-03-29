//Given a Binary Search Tree, find median of it.
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

int countNodes(node *root){
	if(root == NULL) return 0;
	node *cur, *pre;
	int count = 0;
	cur = root;
	while(cur != NULL){
		if(cur->left == NULL){
			count++;
			cur = cur->right;
		}
		else{
			pre = cur->left;
			while(pre->right != NULL && pre->right != cur){
				pre = pre->right;
			}

			if(pre->right == NULL){
				pre->right = cur;
				cur = cur->left;
			}
			else{
				count++;
				pre->right = NULL;
				cur = cur->right;
			}
		}
	}
	return count;
}

int findMedian(node *root){
	if(root == NULL) return 0;
	int count = countNodes(root);
	int curCount = 0;
	node *cur, *pre, *prev;
	cur = root;
	while(cur != NULL){
		if(cur->left == NULL){
			curCount++;
			if(count%2 != 0 && curCount == (count+1)/2)
				return cur->data;
			else if(count%2 == 0 && curCount == count/2+1)
				return (prev->data+cur->data)/2;

			prev = cur;
			cur = cur->right;
		}
		else{
			pre = cur->left;
			while(pre->right != NULL && pre->right != cur){
				pre = pre->right;
			}
			if(pre->right == NULL){
				pre->right = cur;
				cur = cur->left;
			}
			else{
				pre->right = NULL;
				curCount++;

				if(count%2 != 0 && curCount == (count+1)/2)
				return cur->data;
				else if(count%2 == 0 && curCount == count/2+1)
				return (prev->data+cur->data)/2;

				prev = cur;
				cur = cur->right;
			}
		}
	}
	return 0; 
}

int main(){
	string s;
	getline(cin,s);
	node *root = buildTree(s);
	cout << findMedian(root) << endl;
	return 0;
}