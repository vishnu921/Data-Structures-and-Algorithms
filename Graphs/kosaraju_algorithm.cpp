/*
A directed graph is strongly connected if there is a path between all pairs of vertices. 
A strongly connected component (SCC) of a directed graph is a maximal strongly connected subgraph.
*/
#include <bits/stdc++.h>
using namespace std;

//function to push nodes into stack according to their finish time in DFS traversal
void topoDFS(int u, vector<int> adj[], bool visited[], stack<int> &s){
	visited[u] = true;
	for(auto v: adj[u]){
		if(!visited[v]){
			topoDFS(v, adj, visited, s);
		}
	}

	s.push(u);
}

//function to print nodes in DFS manner
void dfs(int u, vector<int> adj[], bool visited[]){
	visited[u] = true;
	cout << u << " ";

	for(auto v: adj[u]){
		if(!visited[v]){
			dfs(v, adj, visited);
		}
	}
}

//function implementation of kosaraju algorithm
void kosarajuAlgorithm(vector<int> adj[], int n){
	bool visited[n];
	memset(visited, false, sizeof(visited));
	stack<int> s;

	//first fill the stack according to finish time in DFS traversal
	for(int i = 0; i < n; i++){
		if(!visited[i]){
			topoDFS(i, adj, visited, s);
		}
	}

	//create transpose graph(basically reversing all edges)
	vector<int> transpose[n];
	for(int i = 0; i < n; i++){
		for(auto j: adj[i]){
			transpose[j].push_back(i);
		}
	}

	//for each node in stack from top iterate
	memset(visited, false, sizeof(visited));
	while(!s.empty()){
		int i = s.top();
		s.pop();

		//if node i is not visited visit it and it will visit only those
		//nodes which are present in its corresponding SCC
		if(!visited[i]){
			dfs(i, transpose, visited);
			cout << "\n";
		}
	}
}

int main(){
	int n,m;
	cin >> n >> m;
	vector<int> adj[n];
	for(int i = 0; i < m; i++){
		int f,s;
		cin >> f >> s;
		adj[f].push_back(s);
	}

	kosarajuAlgorithm(adj, n);
	return 0;
}