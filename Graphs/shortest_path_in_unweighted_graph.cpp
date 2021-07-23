#include <bits/stdc++.h>
using namespace std;

int ShortestPath_BFS(vector<int> adj[], int n, int src, int dest){
	//dist[] array stores distance of each node from the source node
	int dist[n];
	for(int i = 0; i < n; i++){
		dist[i] = INT_MAX;
	}

	queue<int> q;
	q.push(src);
	dist[src] = 0;

	//do BFS traversal, BFS traversal ensures that if we reach
	//a node first time then it is also the shortest path between 
	//source and that node in an unweighted graph
	while(!q.empty()){
		int i = q.front();
		q.pop();

		for(auto u: adj[i]){
			if(dist[i] + 1 < dist[u]){
				dist[u] = dist[i] + 1;
				q.push(u);
			}
		}
	}

	return dist[dest];
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

	int src, dest;
	cout << "Enter source: ";
	cin >> src;
	cout << "Enter Destination: ";
	cin >> dest;

	cout << ShortestPath_BFS(adj, n, src, dest) << "\n";
	return 0;
}