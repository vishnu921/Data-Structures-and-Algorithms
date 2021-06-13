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

void verticalOrderTraversal(node *root){
	if(root == NULL) return;

	map<int, vector<int>> m;
	queue<pair<node *, int>> q;
	int hd = 0;
	q.push(make_pair(root, hd));

	while(!q.empty()){
		pair<node *, int> cur = q.front();
		q.pop();

		hd = cur.second;
		node *temp = cur.first;

		m[hd].push_back(temp->data);

		if(temp->left)
			q.push(make_pair(temp->left, hd-1));

		if(temp->right)
			q.push(make_pair(temp->right, hd+1));
	}

	for(auto x: m){
		for(int i = 0; i < x.second.size(); i++){
			cout << x.second[i] << " ";
		}
		cout << endl;
	}
}

int main(){
	string s;
	getline(cin,s);
	node *root = buildTree(s);
	verticalOrderTraversal(root);
	return 0;
}