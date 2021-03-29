//given a BST and a positive integer, find the kth smallest
//element in the BST
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

int kthSmallestUsingMorris(node *root, int k){
	//count to iterate over nodes till we get kth smallest
	int count = 0;
	int ans = INT_MIN;
	node *cur = root;

	while(cur != NULL){
		if(cur->left == NULL){
			count++;

			if(count == k){
				ans = cur->data;
			}
			cur = cur->right;
		}
		else{
			node *pre = cur->left;
			while(pre->right != NULL && pre->right != cur){
				pre = pre->right;
			}

			if(pre->right == NULL){
				pre->right = cur;
				cur = cur->left;
			}
			else{
				count++;
				pre->right = NULL;
				if(count == k){
					ans = cur->data;
				}
				cur = cur->right;
			}
		}
	}
	return ans;
}

int main(){
	string s;
	getline(cin,s);
	node *root = buildTree(s);
	cout << "Enter K: ";
	int k;
	cin >> k;
	cout << kthSmallestUsingMorris(root, k) << "\n"; 
	return 0;
}