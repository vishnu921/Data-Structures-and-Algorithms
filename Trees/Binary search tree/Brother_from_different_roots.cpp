/*
Given two BSTs containing n1 and n2 distinct nodes respectively
and given a value x. Your task is to fidn the count of all pairs from both 
the BSTs whose sum is equal to x.*/
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


//traverse one tree from left to right and another from right to left
//in iteratively inorder fashion
int countpairs(node *root1, node *root2, int x){
	if(root1 == NULL || root2 == NULL) return 0;

	int count = 0;
	stack<node*> s1, s2;
	node* top1, *top2;
	while(1){
		while(root1 != NULL){
			s1.push(root1);
			root1 = root1->left;
		}
		while(root2 != NULL){
			s2.push(root2);
			root2 = root2->right;
		}

		if(s1.empty() || s2.empty()) break;

		top1 = s1.top();
		top2 = s2.top();

		if(top1->data+top2->data == x){
			count++;
			s1.pop();
			s2.pop();

			root1 = top1->right;
			root2 = top2->left;
		}
		else if(top1->data+top2->data < x){
			s1.pop();
			root1 = top1->right;
		}
		else{
			s2.pop();
			root2 = top2->left;
		}
	}
	return count;
}

int main(){
	string s1,s2;
	getline(cin,s1);
	node *root1 = buildTree(s1);
	getline(cin,s2);
	node *root2 = buildTree(s2);
	int x;
	cout << "Enter sum: ";
	cin >> x;
	cout << countpairs(root1, root2, x) << "\n";
	return 0;
}