/*
Topological sort is an ordering of vertices in a directed acyclic graph in which each node comes 
before all the nodes to which it has outgoing edges.
*/
#include <bits/stdc++.h>
using namespace std;

void topo_DFS(int i, vector<int> adj[], bool visited[], stack<int> &st){
	visited[i] = true;

	//recur for all adjacent nodes
	for(int u: adj[i]){
		if(!visited[u]){
			topo_DFS(u, adj, visited, st);
		}
	}

	//when we have recurred for all nodes to which ith node has
	//outgoing edge, store the ith node in stack
	st.push(i);
}

vector<int> TopoSort(vector<int> adj[], int n){
	bool visited[n];
	memset(visited, false, sizeof(visited));
	//stack to store topoSort in reverse order
	stack<int> st;

	for(int i = 0; i < n; i++){
		if(!visited[i]){
			topo_DFS(i, adj, visited, st);
		}
	}

	vector<int> res;
	while(!st.empty()){
		res.push_back(st.top());
		st.pop();
	}

	return res;
}

int main(){
	int n, m;
	cin >> n >> m;
	vector<int> adj[n];
	for(int i = 0; i < m; i++){
		int f, s;
		cin >> f >> s;
		adj[f].push_back(s);
	}

	vector<int> res = TopoSort(adj, n);
	for(int i = 0; i < n; i++){
		cout << res[i] << " ";
	}
	cout << endl;
	return 0;
}