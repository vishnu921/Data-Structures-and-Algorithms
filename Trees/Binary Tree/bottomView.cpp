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

vector<int> Bottom_View(node *root){
	if(root == NULL) return {};
    map<int, int> m;
    queue<pair<node *, int>> q;
    int hd = 0;
    q.push(make_pair(root, hd));
    
    while(!q.empty()){
        pair<node *, int> temp = q.front();
        q.pop();
        
        node* cur = temp.first;
        hd = temp.second;
        
        m[hd] = cur->data;
        
        if(cur->left != NULL) q.push(make_pair(cur->left, hd-1));
        if(cur->right != NULL) q.push(make_pair(cur->right, hd+1));
    }
    
    vector<int> res;
    for(auto x: m){
        res.push_back(x.second);
    }
    return res;
}

int main(){
	string s;
	getline(cin,s);
	node *root = buildTree(s);
	vector<int> res = Bottom_View(root);
	for(int i = 0; i < res.size(); i++){
		cout << res[i] << " ";
	}
	cout << endl;
	return 0;
}