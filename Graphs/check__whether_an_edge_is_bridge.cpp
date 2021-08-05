/*
Given an undirected graph of V vertices and E edges and another edge (c-d), the task is to find if the given 
edge is a bridge in graph, i.e., removing the edge disconnects the graph.
*/
#include <bits/stdc++.h>
using namespace std;

void dfs(int u, vector<int> adj[], bool visited[]){
	visited[u] = true;

	for(auto v: adj[u]){
		if(!visited[v]){
			dfs(v, adj, visited);
		}
	}
}

bool isBridge(vector<int> adj[], int n, int c, int d){
	//remove the edge
	adj[c].erase(remove(adj[c].begin(), adj[c].end(), d), adj[c].end());
	adj[d].erase(remove(adj[d].begin(), adj[d].end(), c), adj[d].end());

	//do simple dfs with c as starting node and visit all nodes
	bool visited[n];
	memset(visited, false, sizeof(visited));
	dfs(c, adj, visited);

	//check if the node d is visited or not
	//if visited that means there exist a back edge which implies 
	//the c-d edge is not a bridge
	if(visited[d] == true){
		return false;
	}
	
	//else if d is not visited that means removing the edge has disconnected
	//the graph hence c-d edge is a bridge
	return true;
}

int main(){
	int n, m;
	int f,s;
	cin >> n;
	vector<int> adj[n];
	for(int i = 0; i < m; i++){
		cin >> f >> s;
		adj[f].push_back(s);
		adj[s].push_back(f);
	}
	cout << "Enter Edge: ";
	cin >> f >> s;

	if(isBridge(adj, n, f, s)){
		cout << "YES\n";
	} else{
		cout << "NO\n";
	}
	return 0;
}