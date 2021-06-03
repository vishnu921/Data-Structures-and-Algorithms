/*
Given a binary tree, we need to check it has heap property or not, Binary tree need to fulfill the 
following two conditions for being a heap – 

    1. It should be a complete tree (i.e. all levels except last should be full).
    2. Every node’s value should be greater than or equal to its child node (considering max-heap).
*/
#include <bits/stdc++.h>
using namespace std;
class node{
public:
	int data;
	node *left, *right;

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

//is maxheap in O(n)
bool ismaxHeap(node* root){
	if(root == NULL) return true;

	//queue for level order traversal
	queue<node*> q;
	//nullish whether null node is found before or not
	//this is used to check completeness of binary tree
	bool nullish = false;
	q.push(root);

	while(!q.empty()){
		node *cur = q.front();
		q.pop();
		if(cur->left){
			//if any null node found before or left child >= root node
			if(nullish || cur->left->data >= cur->data)
				return false;
			//else push left child in the queue
			q.push(cur->left);
		}
		else nullish = true;

		//do the same for right child
		if(cur->right){
			if(nullish || cur->right->data >= cur->data)
				return false;

			q.push(cur->right);
		}
		else nullish = true;
	}
	//if full traversal is done successful then it is heap
	return true;
}

int main(){
	string s;
	getline(cin,s);
	node *root = buildTree(s);
	if(ismaxHeap(root))
		cout << "YES\n";
	else cout << "NO\n";
	return 0;
}