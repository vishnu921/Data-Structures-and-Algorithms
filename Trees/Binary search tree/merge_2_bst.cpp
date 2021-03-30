#include <bits/stdc++.h>
using namespace std;

class node{
public:
	int data;
	node *left, *right;

	node(int x){
		data = x;
		left = NULL;
		right = NULL;
	}
};

vector<int> mergeBST(node *root1, node *root2){
	vector<int> res;
	stack<node*> s1, s2;
	while(root1 != NULL || !s1.empty() || root2 != NULL || !s2.empty()){
		while(root1 != NULL){
			s1.push(root1);
			root1 = root1->left;
		}
		while(root2 != NULL){
			s2.push(root2);
			root2 = root2->left;
		}

		if(!s1.empty() && !s2.empty()){
			if(s1.top()->data < s2.top()->data){
				root1 = s1.top();
				s1.pop();
				res.push_back(root1->data);
				root1 = root1->right;
			}
			else{
				root2 = s2.top();
				s2.pop();
				res.push_back(root2->data);
				root2 = root2->right;
			}
		}
		else if(!s1.empty()){
			root1 = s1.top();
			s1.pop();
			res.push_back(root1->data);
			root1 = root1->right;
		}
		else if(!s2.empty()){
			root2 = s2.top();
			s2.pop();
			res.push_back(root2->data);
			root2 = root2->right;
		}
	}
	return res;
}

int main(){
	node *root1 = NULL;
	node *root2 = NULL;

	root1 = new node(4);
	root1->left = new node(2);
	root1->right = new node(6);

	root2 = new node(3);
	root2->left = new node(1);
	root2->right = new node(5);

	vector<int> res = mergeBST(root1,root2);

	for(int i = 0; i < res.size(); i++){
		cout << res[i] << " ";
	}
	cout << endl;
}