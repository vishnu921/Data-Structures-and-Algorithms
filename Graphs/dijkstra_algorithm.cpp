/*
Dijkstra’s Algorithm:

This algorithm is used to find the shortest distance between any two vertices in a weighted non-cyclic graph.
Here, we will be using a slight modification of the algorithm according to which we will be figuring o
ut the minimum distance of all the vertices from the particular source vertex.

*/

#include <bits/stdc++.h>
using namespace std;
#define pi pair<int,int>

void printShortestPaths(int n, int s, int parent[], int dist[]){
	cout << "\nVertex\tdistance\tPath\n";
	for(int i = 0; i < n; i++){
		cout << "  " << i << " \t" << dist[i] << "\t\t"; 
		//printing path
		vector<int> path;
		int v = i;
		while(v > -1){
			path.push_back(v);
			v = parent[v];
		}
		for(int j = path.size()-1; j > 0; j--){
			cout << path[j] << "-";
		}
		cout << i << "\n";
	}

}

void Dijkstra_algorithm(int n, int src, vector<pi> adj[]){
	//parent array to store the node from which the distance is aquired
	int parent[n];
	//dist[i] stores shortest distance of node i from source
	int dist[n];

	//initialize all distances with INT_MAX
	for(int i = 0; i < n; i++){
		dist[i] = INT_MAX;
	}

	//min heap to store edges based their weights
	priority_queue<pi, vector<pi>, greater<pi>> pq;

	//push the source into the min heap
	pq.push({0, src});
	//distance of source from itself is always 0
	dist[src] = 0;
	//there is no parent node of source so parent[i] = -1
	parent[src] = -1;

	//iterate untill min heap is empty and shortest path to all
	//vertices are found
	while(!pq.empty()){
		//pick the minimum distance vertex from the set of vertices not yet
		//processed 
		int u = pq.top().second;
		pq.pop();

		//update the distance value and parent node of the adjacent node of the picked node
		for(auto e: adj[u]){
			int v = e.first;
			int weight = e.second;
			//update dist[v] only if there is a path from src to v through u
			//that is smaller than current value of dist[u]
			if(dist[v] > dist[u] + weight){
				dist[v] = dist[u] + weight;
				parent[v] = u;
				pq.push({dist[v], v});
			}
		}
	}

	//print the path of every vertex from source
	printShortestPaths(n, src, parent, dist);
}

int main(){
	int n, m, src;
	cin >> n >> m;
	vector<pi> adj[n];
	for(int i = 0; i < m; i++){
		int f,s,wt;
		cin >> f >> s >> wt;
		adj[f].push_back({s, wt});
		adj[s].push_back({f, wt});
	}

	cout << "Enter source: ";
	cin >> src;

	Dijkstra_algorithm(n, src, adj);
	return 0;
}

