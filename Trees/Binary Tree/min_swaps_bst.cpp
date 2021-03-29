/*
given an array implementation of complete binary tree
here if parent's index = i, then left child is given by 2*i+1 and right child is given by 2*i+2
find the minimum number swaps to convert the binary tree into binary search tree
*/
#include <bits/stdc++.h>
using namespace std;

void inorder(int a[],int n,vector<int> &v, int i){
	if(i >= n) return;
	inorder(a,n,v,2*i+1);
	v.push_back(a[i]);
	inorder(a,n,v,2*i+2);
}

/*
In this problem first we find the inorder traversal of the binary tree
then sort the inorder array
the minimum number of swaps to sort the array is the answer.
*/
int minSwapsToConvert(vector<int> &v,int n){
	int res = 0;
	vector<pair<int, int>> t(n);   //t[i] stores the pair of v[i] and the index i in inorder array 
	for(int i = 0; i < n; i++){
		t[i].first = v[i];
		t[i].second = i;
	}
	sort(t.begin(), t.end());
	for(int i = 0; i < n; i++){
		//this means there is no swaps required to put the current element in its correct position in the sorted array
		if(i == t[i].second)
			continue;
		else{
			swap(t[i].first, t[t[i].second].first);
			swap(t[i].second, t[t[i].second].second);
		}
		//this means that if even after swaping the current element does not obtain its original position
		//then we iterate this element again
		if(i != t[i].second)
			i--;
		//res is incremented everytime when swapping is required
		res++;
	}
	return res;
}

int main(){
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++) cin >> a[i];
	vector<int> v;        //this vector stores the inorder traversal of the binary tree
	inorder(a,n,v,0);
	cout << minSwapsToConvert(v,n) << endl;
	return 0;
}