// Given an array of numbers, return true if given array can 
// represent preorder traversal of a Binary Search Tree, else return false.
#include <bits/stdc++.h>
using namespace std;

bool CanRepresentBST(int pre[], int n){
	stack<int> s;
	int root = INT_MIN;
	for(int i = 0; i < n; i++){
		if(pre[i] < root) return false;

		//
		while(!s.empty() && s.top() < pre[i]){
			root = s.top();
			s.pop();
		}

		s.push(pre[i]);
	}
	return true;
}

int main(){
	int n;
	cin >> n;
	int pre[n];
	for(int i = 0; i < n; i++){
		cin >> pre[i];
	}
	if(CanRepresentBST(pre,n))
		cout << "True\n";
	else
		cout << "False\n";
	return 0;
}