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

void fill_array(node *root, vector<int> &res){
	if(root == NULL) return;
	fill_array(root->left, res);
	res.push_back(root->data);
	fill_array(root->right, res);
}

void arrayToBST(node *root, vector<int> &res, int &i){
	if(root == NULL) return;
	arrayToBST(root->left, res, i);

	root->data = res[i];
	i++;

	arrayToBST(root->right, res, i);
}

void convertToBST(node *root){
	if(root == NULL) return;
	vector<int> res;
	fill_array(root, res);

	sort(res.begin(), res.end());

	int i = 0;
	arrayToBST(root, res, i);
}

void inorder(node *root){
	if(root == NULL) return;
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

int main(){
	string s;
	getline(cin,s);
	node *root = buildTree(s);
	cout << "Before conversion: ";
	inorder(root);
	convertToBST(root);
	cout << "\nAfter conversion: ";
	inorder(root);
	return 0;
}