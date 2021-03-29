//Given a Binary Tree, check if all leaves are at same level or not.
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

bool checkUtil(node *root, int level, int &first){
	if(root == NULL) return true;
	if(root->left == NULL && root->right == NULL){
		if(first == 0){
			first = level;
			return true;
		}

		return (first == level);
	}
	bool l,r;
	l = checkUtil(root->left, level+1, first);
	r = checkUtil(root->right, level+1, first);
	return (l&&r);
}

bool check(node *root){
	int first = 0, level = 0;
	return checkUtil(root, level, first);
}

int main(){
	string s;
	getline(cin,s);
	node *root = buildTree(s);
	if(check(root)){
		cout << "All leaves are at same level\n";
	}
	else{
		cout << "Leaves are not at same level\n";
	}
	return 0;
}