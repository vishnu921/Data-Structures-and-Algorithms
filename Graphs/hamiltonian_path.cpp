/*
A hamiltonian path is a path in an undirected or directed graph in which each vertex is visited only once.
A hamiltonian cycle is a hamiltonian path which is a cycle
*/

#include <bits/stdc++.h>
using namespace std;

bool dfs(int u, int count, int n, vector<int> adj[], bool visited[]){
	//if count of nodes in current path is equal to total number of vertex
	if(count == n) return true;

	//mark current node visited
	visited[u] = true;

	//recur for each adjacent vertex
	for(auto v: adj[u]){
		if(!visited[v]){
			if(dfs(v, count+1, n, adj, visited))
				return true;
		}
	}

	//we do backtracking since we need to check each path
	visited[u] = false;
	return false;
}

bool hasHamiltonianPath(vector<int> adj[], int n){
	bool visited[n];
	memset(visited, false, sizeof(visited));

	//the hamiltonian path can start from any vertex
	//so we check for every vertex
	for(int i = 0; i < n; i++){
		if(dfs(i, 1, n, adj, visited)){
			return true;
		}
	}

	//if no hamiltonian path found
	return false;
}

int main(){
	int n, m;
	cin >> n >> m;
	vector<int> adj[n];
	for(int i =0; i < m; i++){
		int f,s;
		cin >> f >> s;
		adj[f].push_back(s);
		adj[s].push_back(f);
	}

	if(hasHamiltonianPath(adj, n)){
		cout << "Hamiltonian path exists\n";
	}
	else cout << "Hamiltonian path doesn't exists\n";
	return 0;
}