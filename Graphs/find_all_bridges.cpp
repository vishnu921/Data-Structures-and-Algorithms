/*
An edge in an undirected connected graph is a bridge iff removing it disconnects the graph. For a 
disconnected undirected graph, definition is similar, a bridge is an edge removing which increases 
number of disconnected components.
*/
#include <bits/stdc++.h>
using namespace std;

void dfs(int u, int parent, int &time, vector<int> adj[], bool visited[], int in[], int low[]){
	visited[u] = true;

	in[u] = low[u] = ++time;
	for(auto v: adj[u]){
		//if the adjacent is parent we do nothing
		if(v == parent) continue;
		//iv adjacent node is not visited
		if(!visited[v]){
			//recur for it
			dfs(v, u, time, adj, visited, in, low);

			//check if the subtree rooted with v has connection to one
			//of the ancestors of u
			low[u] = min(low[u], low[v]);

			//if lowest vertex reachable from subtree of v is greater
			//than visit time of u that means this edge is a bridge
			if(low[v] > in[u]){
				cout << u << " " << v << endl;
			}
			//update low value of u for parent function calls
		} else{
			low[u] = min(low[u], in[v]);
		}
	}

}

void getBridges(vector<int> adj[], int n){
	bool visited[n];
	memset(visited, false, sizeof(visited));
	//in[i] stores time when it was visited first
	//low[i] stores earliest visited node reachable from v by taking 1 back edge
	int in[n], low[n];
	int time = 0;

	for(int i = 0; i < n; i++){
		if(!visited[i]){
			dfs(i, -1, time, adj, visited, in, low);
		}
	}
}

int main(){
	int n, m;
	cin >> n >> m;
	vector<int> adj[n];
	for(int i = 0; i < m; i++){
		int f,s;
		cin >> f >> s;
		adj[f].push_back(s);
		adj[s].push_back(f);
	}

	getBridges(adj, n);
	return 0;
}