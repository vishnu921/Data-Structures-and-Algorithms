//given an BST, the task is to flatten it to a sorted list. 
//the value of each node must be lesser than the values of all the nodes at its right,
//and its left node must be NULL after flattening 
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

void inorder(node *root, node* &prev){
	if(root == NULL) return;
	inorder(root->left, prev);
	prev->left = NULL;
	prev->right = root;
	prev = root;
	inorder(root->right,prev);
}

node* flatten(node *root){
	node *dummy = new node(-1);
	node *prev = dummy;
	inorder(root, prev);

	prev->left = NULL;
	prev->right = NULL;
	node *head = dummy->right;
	delete dummy;

	return head;
}

void print(node *head){
	if(head == NULL) return;
	while(head != NULL){
		cout << head->data << " ";
		head = head->right;
	}
	cout << endl;
}

int main(){
	string s;
	getline(cin,s);
	node *root = buildTree(s);
	node *head = flatten(root);
	print(head);
	return 0;
}