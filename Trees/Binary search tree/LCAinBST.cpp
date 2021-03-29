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

node *LCA(node *root, int n1, int n2){
	while(root != NULL){
		//root is greater than both n1 and n2 then LCA is present in left subtree
		if(root->data > n1 && root->data > n2)
			root = root->left;

		//else if it si less than both n1 & n2 then LCA is present in right subtree
		else if(root->data < n1 && root->data < n2)
			root = root->right;

		else break;  //that means current node is the LCA of n1 and n2
	}
	return root;
}

int main(){
	string s;
	getline(cin,s);
	node *root = buildTree(s);
	int n1,n2;
	cin >> n1 >> n2;
	node *lca = LCA(root, n1, n2);
	if(lca) cout << lca->data << endl;
	else cout << "lca does not exist\n";
	return 0;
}