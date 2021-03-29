//traverse the tree in zig-zag or spiral 
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

vector<int> zigZagTraversal(node *root){
	if(root == NULL) return {};
    
    stack<node *> s1,s2;
    vector<int> res;
    s1.push(root);

    while(!s1.empty() || !s2.empty()){
    	while(!s1.empty()){
    		root = s1.top(); s1.pop();
    		res.push_back(root->data);

    		//pop the top of s1 stack and push its children from left to right in s2 stack
    		if(root->left) s2.push(root->left);
    		if(root->right) s2.push(root->right);
    	}

    	while(!s2.empty()){
    		root = s2.top(); s2.pop();
    		res.push_back(root->data);

    		//pop the top of s2 stack and push its children from right to left in s1 stack
    		if(root->right) s1.push(root->right);
    		if(root->left) s1.push(root->left);
    	}
    }
    return res;
}

//Another way but same approach
vector<int> SpiralTraversal(node *root){
	if(root == NULL) return {};

	stack<node *> current, next;
	bool leftToright = true;
	vector<int> res;

	current.push(root);

	while(!current.empty()){
		root = current.top();
		current.pop();

		res.push_back(root->data);

		if(leftToright){
			if(root->left)
				next.push(root->left);
			if(root->right)
				next.push(root->right);
		}
		else{
			if(root->right)
				next.push(root->right);
			if(root->left)
				next.push(root->left);
		}

		if(current.empty()){
			leftToright = !leftToright;
			swap(current, next);
		}
	}
	return res;
}

int main(){
	string s;
	getline(cin,s);
	node *root = buildTree(s);
	vector<int> res = zigZagTraversal(root);
	for(int i = 0; i < res.size(); i++){
		cout << res[i] << " ";
	}
	cout << endl;
	return 0;
}