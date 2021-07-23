#include <bits/stdc++.h>
using namespace std;

void makeSet(int parent[], int rank[], int n){
	for(int i = 0; i < n; i++){
		parent[i] = i;
		rank[i] = 0;
	}
}

//path compressed find
int find(int i, int parent[]){
	//if the ith node is its parent
	if(parent[i] == i){
		return i;
	}

	return parent[i] = find(parent[i], parent);
}

//union by rank
void unionByRank(int u, int v, int parent[], int rank[]){
	u = find(u, parent);       //find the set of u
	v = find(v, parent);       //find the set of v

	if(rank[u] < rank[v]){
		parent[u] = v;
	}
	else if(rank[u] > rank[v]){
		parent[v] = u;
	}
	else{
		parent[v] = u;    //if same ranked sets are union then
		rank[u]++;		  //increase the rank of parent set by 1
	}
}

int main(){
	int n = 10;
	int parent[n];
	int rank[n];

	makeSet(parent, rank, n);
	unionByRank(1, 2, parent, rank);
	unionByRank(3, 4, parent, rank);
	unionByRank(2, 4, parent, rank);
	unionByRank(5, 6, parent, rank);
	unionByRank(7, 8, parent, rank);
	unionByRank(5, 8, parent, rank);
	unionByRank(3, 8, parent, rank);

	//node
	for(int i = 0; i < n; i++){
		cout << i << " ";
	}cout << "\n";

	//parent
	for(int i = 0; i < n; i++){
		cout << parent[i] << " ";
	}cout << "\n";

	//rank
	for(int i = 0; i < n; i++){
		cout << rank[i] << " ";
	}
	return 0;
}