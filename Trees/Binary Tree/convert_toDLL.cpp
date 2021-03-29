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

//in this function we perform inorder traversal instead of printing the node we perform conversion operation
//this function takes parameters root, head of the DLL, and a prev node which updates at every recursion
// prev points to the most recent node encountered

void convert_Util(node *root, node* &head, node* &prev){
	if(root == NULL) return;

	convert_Util(root->left, head, prev);
	if(prev == NULL){
		head = root;
	}
	else{
		prev->right = root;
		root->left = prev;
	}
	prev = root;
	convert_Util(root->right, head, prev);
}

node *Convert_binaryToDLL(node *root){
	if(root == NULL) return NULL;

	node *head = NULL;
	node *prev = NULL;
	convert_Util(root, head, prev);
	return head;
}

int main(){
	string s;
	getline(cin,s);
	node *root = buildTree(s);
	node *head = Convert_binaryToDLL(root);
	while(head != NULL){
		cout << head->data << " ";
		head = head->right;
	}
	cout << endl;
	return 0;
}