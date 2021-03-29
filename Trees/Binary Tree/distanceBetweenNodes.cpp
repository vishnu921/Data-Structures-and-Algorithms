//Given a binary tree and two node values your task is to find the minimum distance between them.
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

node *lca(node *root, int n1, int n2){
	if(root == NULL) return NULL;

	if(root->data == n1 || root->data == n2)
		return root;

	node *leftans = lca(root->left, n1, n2);
	node *rightans = lca(root->right, n1, n2);

	if(leftans != NULL && rightans != NULL) return root;

	if(leftans != NULL) return leftans;
	else return rightans;
}

int getLevel(node *root, int a, int level){
	if(root == NULL) return 0;

	if(root->data == a) return level;

	int ans = getLevel(root->left, a, level+1);
	if(ans != 0)
		return ans;
	ans = getLevel(root->right, a, level+1);
	return ans;
}

//in this problem the minimum distance between two nodes is calculated as shown below
int getDistance(node *root, int a, int b){
	if(root == NULL) return 0;

	//we first find the lowest common ancestor of the two nodes
	node *ans = lca(root, a, b);

	//then we find the depth of both nodes from their lowest common ancestor
	int da = getLevel(ans, a, 0);
	int db = getLevel(ans, b, 0);

	//return the sum of both depth
	return (da+db);
}

int main(){
	string s;
	getline(cin,s);
	node *root = buildTree(s);
	int a, b;
	cin >> a >> b;
	cout << getDistance(root, a, b) << endl;
	return 0;
}