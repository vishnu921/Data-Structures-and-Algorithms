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

void utility(node *root, int &h, int &sum){
	if(root == NULL) return;
	int lh = 0, rh = 0, lsum = 0, rsum = 0;
	utility(root->left, lh, lsum);
	utility(root->right, rh, rsum);

	h = max(lh,rh)+1;
	if(lh > rh){
		sum = lsum+root->data;
	}
	else if(lh < rh){
		sum = rsum+root->data;
	}
	else{
		sum = max(lsum,rsum)+root->data;
	}
}

int sum_of_longest_rootToleafPath(node *root){
	int h = 0, sum = 0;
	utility(root,h,sum);
	return sum;
}

int main(){
	string s;
	getline(cin,s);
	node *root = buildTree(s);
	cout << sum_of_longest_rootToleafPath(root) << endl;
	return 0;
}