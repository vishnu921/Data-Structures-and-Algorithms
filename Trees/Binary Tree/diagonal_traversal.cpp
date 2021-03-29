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

void diagonalUtil(node *root, int d, map<int, vector<int>> &m){
    if(root == NULL) return;
    
    m[d].push_back(root->data);
    
    diagonalUtil(root->left, d+1, m);
    diagonalUtil(root->right, d, m);
}

vector<int> diagonal(node *root)
{
    if(root == NULL) return {};
    map<int, vector<int>> m;
    diagonalUtil(root, 0, m);
    
    vector<int> res;
    for(auto x: m){
        for(int i = 0; i < x.second.size(); i++){
            res.push_back(x.second[i]);
        }
    }
    return res;
}

int main(){
	string s;
	getline(cin,s);
	node *root = buildTree(s);
	vector<int> res = diagonal(root);
	for(int i = 0; i < res.size(); i++){
		cout << res[i] << " ";
	}
	cout << endl;
	return 0;
}