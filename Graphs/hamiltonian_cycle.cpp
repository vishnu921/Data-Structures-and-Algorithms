/*
find if a graph has hamiltonian cycle or not
*/
#include <bits/stdc++.h>
using namespace std;

bool dfs(int u, int count, int n, vector<int> adj[], bool visited[]){
	//if count of nodes in current path is equal to total number of vertex
	if(count == n){
		//if there is a edge from last vertex to starting vertex
		for(auto v: adj[u]){
			if(v == 0) return true;
		}
		// else return false
		return false;
	}

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

bool hasHamiltonianCycle(vector<int> adj[], int n){
	bool visited[n];
	memset(visited, false, sizeof(visited));

	//if a hamiltonian cycle exists in a graph
	//then it can start at any vertex so let's start at 0
	if(dfs(0, 1, n, adj, visited)){
		return true;
	}

	//if no hamiltonian cycle found
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

	if(hasHamiltonianCycle(adj, n)){
		cout << "Hamiltonian Cycle exists\n";
	}
	else cout << "Hamiltonian Cycle doesn't exists\n";
	return 0;
}