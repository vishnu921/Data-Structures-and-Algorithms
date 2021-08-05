/*
Following is complete algorithm for finding shortest distances. 
1) Initialize dist[] = {INF, INF, ….} and dist[s] = 0 where s is the source vertex. 
2) Create a topological order of all vertices. 
3) Do following for every vertex u in topological order. 
	-> Do following for every adjacent vertex v of u 
		-> if (dist[v] > dist[u] + weight(u, v)) 
			-> dist[v] = dist[u] + weight(u, v) 
*/

#include <bits/stdc++.h>
using namespace std;
#define pi pair<int,int>

void topo_DFS(int u, vector<pi> adj[], bool visited[], stack<int> &st){
	visited[u] = true;

	//recur for all adjacent nodes
	for(pi p: adj[u]){
		int v = p.first;
		if(!visited[v]){
			topo_DFS(v, adj, visited, st);
		}
	}

	//when we have recurred for all nodes to which ith node has
	//outgoing edge, store the ith node in stack
	st.push(u);
}

void shortestPath(vector<pi> adj[], int n){
	//first we find the topological order of graph
	bool visited[n];
	int dist[n];
	for(int i = 0; i < n; i++){
		dist[i] = INT_MAX;
	}
	memset(visited, false, sizeof(visited));
	//stack to store topoSort in reverse order
	stack<int> st;

	for(int i = 0; i < n; i++){
		if(!visited[i]){
			topo_DFS(i, adj, visited, st);
		}
	}
	
	dist[0] = 0;
	while(!st.empty()){
		int u = st.top();
		st.pop();
		if(dist[u] != INT_MAX){
			for(pi p: adj[u]){
				int v = p.first;
				int weight = p.second;
				if(dist[v] > dist[u] + weight){
					dist[v] = dist[u] + weight;
				}
			}
		}
	}

	//print the distance
	cout <<"\nvertex dist\n";
	for(int i = 0; i < n; i++){
		cout << "  " << i << " \t" << dist[i] << "\n";
	}
}

int main(){
	int n,m;
	cin >> n >> m;
	vector<pi> adj[n];
	for(int i = 0; i < m; i++){
		int f,s,wt;
		cin >> f >> s >> wt;
		adj[f].push_back({s, wt});
	}

	shortestPath(adj, n);
	return 0;
}