/*
A vertex in an undirected connected graph is an articulation point (or cut vertex) if removing it 
(and edges through it) disconnects the graph. 

In DFS tree, a vertex u is articulation point if one of the following two conditions is true. 
1) u is root of DFS tree and it has at least two children. 
2) u is not root of DFS tree and it has a child v such that no vertex in subtree 
rooted with v has a back edge to one of the ancestors (in DFS tree) of u.
*/

#include <bits/stdc++.h>
using namespace std;

void dfs(int u, int parent, vector<int> adj[], int in[], int low[], bool ap[], bool visited[]){
	static int time = 0;
	int children = 0;				//this is used to check the case of root
	visited[u] = true;				//a root node must have atleast 2 children in DFS tree to be articulation point
	in[u] = low[u] = ++time;

	for(auto v: adj[u]){
		//if adjacent node is parent then do not
		if(v == parent) continue;
		if(!visited[v]){
			//if adjacent node is not visited recur for it
			children++;
			dfs(v, u, adj, in, low, ap, visited);

			//check if it is possible to reach earlier visited vertex from u using 1 back edge
			//if yes update its low value
			low[u] = min(low[u], low[v]);

			//if current node is root node and children in DFS tree is more than 1 then it is AP
			if(parent == -1 && children > 1){
				ap[u] = true;
			}

			//else if it is not root node and there is no ancestor of u(ancestor in dfs tree) 
			//reachable from subree rooted with v then u is AP
			if(parent != -1 && low[v] >= in[u]){
				ap[u] = true;
			}
		}
		else{
			//else if adjacent node is visited and not a parent, it may be an ancestor(ancestor in dfs tree) 
			// to which we can reach if yes then update its low value
			low[u] = min(low[u], in[v]);
		}
	}
}

void articulationPoints(vector<int> adj[], int n){
	bool visited[n];
	int in[n];			//in[i] stores time when it was visited first
	int low[n];			//low[i] stores earliest visited node reachable from v by taking 1 back edge
	bool ap[n];      //to store articulation points
	for(int i = 0; i < n; i++){
		visited[i] = ap[i] = false;
	}

	for(int i = 0; i < n; i++){
		if(!visited[i]){
			dfs(i, -1, adj, in, low, ap, visited);
		}
	}

	for(int i; i < n; i++){
		if(ap[i] == true){
			cout << i << " ";
		}
	} cout << endl;
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

	articulationPoints(adj, n);
	return 0;
}