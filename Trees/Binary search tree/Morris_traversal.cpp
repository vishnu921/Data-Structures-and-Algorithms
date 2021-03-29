//this is a technique to traversal a binary tree without 
//recursion and without stack in O(1) space

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

/*In inorder traversal of binary tree we use recursion or stack
because we need a way to come back to root node after processing
the left subtree but with morris traversal we create links to 
inorder successors and print data using these link and then revert
the changes to restore the original tree
*/
void MorrisTraversal(node *root){
	node *current, *pre;
	if(root == NULL) return;

	current = root;
	while(current != NULL){
		//if left subtree doesn't exist that means 
		//we need not to return the current node again
		//so we print it and move the right subtree
		if(current->left == NULL){
			cout << current->data << " ";
			current = current->right;
		}
		else{
			//find the inorder predecessor of the current
			pre = current->left;
			while(pre->right != NULL && pre->right != current){
				pre = pre->right;
			}

			//make current as the right child of its inorder predecessor
			//in this way we have established the link to current which will
			//help later to return to the current node after processing its left subtree
			if(pre->right == NULL){
				pre->right = current;
				current = current->left;
			}
			//revert the changes made in if part to restore original binary tree
			else{
				pre->right = NULL;
				cout << current->data << " ";
				current = current->right;
			}
		}
	}
}

int main(){
	string s;
	getline(cin,s);
	node *root = buildTree(s);
	MorrisTraversal(root);
	return 0;
}