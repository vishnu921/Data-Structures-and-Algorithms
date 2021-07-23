#include <bits/stdc++.h>
using namespace std;

void printDFS(vector<int> adj[], int s, bool visited[]){
	//process the node
	cout << s << " ";
	//mark the node visited
	visited[s] = true;

	//recursively call this function for its each adjacent node
	for(auto u: adj[s]){
		if(!visited[u]){
			printDFS(adj, u, visited);
		}
	}
}

void DFS(vector<int> adj[], int n){
	bool visited[n];
	memset(visited, false, sizeof(visited));

	for(int i = 0; i < n; i++){
		if(!visited[i]){
			printDFS(adj, i, visited);
			cout << "\n";
		}
	}
}

int main(){
	int n, m;
	cin >> n >> m;
	vector<int> adj[n];
	for(int i = 0; i < m; i++){
		int f, s;
		cin >> f >> s;
		adj[f].push_back(s);
		adj[s].push_back(f);
	}

	DFS(adj, n);
	return 0;
}