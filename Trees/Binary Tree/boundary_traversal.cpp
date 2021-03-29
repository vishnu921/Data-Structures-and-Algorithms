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

void printleaves(node *root, vector<int> &lea){
    if(root == NULL) return;
    printleaves(root->left, lea);
    
    if(root->left == NULL && root->right == NULL)
        lea.push_back(root->data);
        
    printleaves(root->right, lea);
}

void printleft(node *root, vector<int> &left){
    if(root == NULL) return;
    if(root->left){
        left.push_back(root->data);
        printleft(root->left, left);
    }
    else if(root->right){
        left.push_back(root->data);
        printleft(root->right, left);
    }
}

void printright(node *root, vector<int> &right){
    if(root == NULL) return;
    if(root->right){
        printright(root->right, right);
        right.push_back(root->data);
    }
    else if(root->left){
        printright(root->left, right);
        right.push_back(root->data);
    }
}

vector <int> printBoundary(node *root)
{
    if(root == NULL) return {};
    vector<int> res;
    res.push_back(root->data);
    
    printleft(root->left, res);
    
    printleaves(root->left,res);
    printleaves(root->right, res);
    
    printright(root->right, res);
    return res;
     //Your code here
}
int main(){
	string s;
	getline(cin,s);
	node *root = buildTree(s);
	vector<int> res = printBoundary(root);
	for(int i = 0; i < res.size(); i++){
		cout << res[i] << " ";
	}
	cout << endl;
	return 0;
}