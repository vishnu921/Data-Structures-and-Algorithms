//calculate diameter of the binary tree
//The diameter of a tree is the number of nodes on the longest path between two end nodes in the tree. The diagram below shows two trees each with diameter nine, the leaves that form the ends of a longest path are shaded (note that there is more than one path in each tree of length nine, but no path longer than nine nodes).
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

node *insertLevelorder(node *root, int x){
	node *temp = new node(x);
	if(root == NULL){
		root = temp;
		return root;
	}
	queue<node *> q;
	q.push(root);
	while(!q.empty()){
		node *cur = q.front(); q.pop();
		if(cur->left != NULL) q.push(cur->left);
		else{
			cur->left = temp;
			break;
		}

		if(cur->right != NULL) q.push(cur->right);
		else{
			cur->right = temp;
			break;
		}
	}
	return root;
}

//this function returns the height of the current tree and the longest diamter of the tree formed when the current node is root
pair<int, int> diameter(node *root){
	if(root == NULL) return {0,0};

	pair<int,int> lt = diameter(root->left);
	pair<int, int> rt = diameter(root->right);

	pair<int,int> my;
	//assigning the height to the current tree
	my.first = max(lt.first, rt.first) + 1;

	//longest diameter is the maximum of either left diameter, right diamter or (nodes between deepest node on left subtree and the deepest node in the right subtree)
	my.second = max(lt.first+rt.first+1, max(lt.second, lt.second));

	return my;
}

int main(){
	int n;
	cin >> n;
	node *root = NULL;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		root = insertLevelorder(root, x);
	}
	pair<int, int> ans = diameter(root);

	cout << "diameter of the binary tree: " << ans.second << endl;
	return 0;
}