/*
Given a binary tree with a value associated with each node, we need to choose a subset of these nodes such that the sum of chosen nodes is maximum under a constraint that no two chosen node in the subset should be directly connected that is, if we have taken a node in our sum then we can’t take any of its children in consideration and vice versa. 
*/
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

//This problem can be solved by using the fact that if a node is chosen than its children cannot be chosen in sum
//when we chose the current node then we call recursively for its grandchildren 
//and when do not chose the current node we chose its left and right children for the sum
//then we can get maximum of the above 2 cases and return the maximum value for the current node
//to optimise the solution we can use DP to memoise the answer for every node so that we do not have to calculate for it again
int getMaxSumutil(node *root, unordered_map<node *, int> &dp){
	if(root == NULL) return 0;

	if(dp.find(root) != dp.end()) return dp[root];

	//getting the maximum sum when the current node is chosen
	int inc = root->data;
	if(root->left){
		inc += getMaxSumutil(root->left->left, dp);
		inc += getMaxSumutil(root->left->right, dp);
	}
	if(root->right){
		inc += getMaxSumutil(root->right->left, dp);
		inc += getMaxSumutil(root->right->right, dp);
	}

	//maximum sum when current node is not chosen
	int exc = getMaxSumutil(root->left,dp) + getMaxSumutil(root->right, dp);

	//maximum adjacent sum is the maximum of both above answers
	dp[root] = max(inc, exc);
	return dp[root];
}

int getMaxSum(node *root){
	if(root == NULL) return 0;

	unordered_map<node*,int> dp;
	return getMaxSumutil(root, dp);
}

int main(){
	string s;
	getline(cin,s);
	node *root = buildTree(s);
	int ans = getMaxSum(root);
	cout << ans << endl;
	return 0;
}