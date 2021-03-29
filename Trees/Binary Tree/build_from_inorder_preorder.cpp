//construct a binary tree from inorder and preorder traversal
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

/* In preorder the first element is the root node hence knowing the root node we can find the root node
   in inorder traversal. We get the index of the root node from the inorder array. hence the left side of the current node 
   is its left subtree and right side is right subtree
*/
node* buildTreeUtil(int in[], int pre[], int start, int end, int &preIndex, unordered_map<int, int> &m){
	if(start > end) return NULL;

	node *cur = new node(pre[preIndex++]);

	if(start == end) return cur;

	int index = m[cur->data];
	cur->left = buildTreeUtil(in, pre, start, index-1, preIndex, m);
	cur->right = buildTreeUtil(in, pre, index+1, end, preIndex, m);

	return cur;
}

void postorder(node *root){
	if(root == NULL) return;
	postorder(root->left);
	postorder(root->right);

	cout << root->data << " ";
}
node* buildTree(int in[], int pre[], int n){
	int preIndex = 0;
	unordered_map<int, int> m;
	for(int i = 0; i < n; i++){
		m[in[i]] = i;
	}
	node *root = buildTreeUtil(in, pre, 0, n-1, preIndex, m);
	return root;
}

int main(){
	int n;
	cin >> n;
	int in[n],pre[n];
	for(int i = 0; i < n; i++)
		cin >> in[i];
	for(int i = 0; i < n; i++)
		cin >> pre[i];

	node *root = buildTree(in,pre,n);
	postorder(root);
	return 0;
}