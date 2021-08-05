#include <bits/stdc++.h>
using namespace std;
#define vvi vector<vector<int>>
#define vi vector<int>

void floydWarshall_algorithm(int n, vvi &adj){
	//in this problem we use dynamic programming
	//we consider every element as intermediate vertex of each path
	//i.e. let there is a path node i to node j. let there exist a 
	//node k such that if we put k as an intermediate node between i to j i.e. path becomes
	// i to k then k to j and distance between i and j decreases then we select k as intermediate node
	int dist[n][n];
	//initialize distance matrix same as adjacency matrix
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(i == j) dist[i][j] = 0;
			else dist[i][j] = adj[i][j];
		}
	}

	//floyd-warshall algorithm
	for(int k = 0; k < n; k++){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(i == j) continue;
				if(dist[i][k] != INT_MAX && dist[k][j] != INT_MAX){
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}
	}

	//print dist[][] matrix
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << dist[i][j] << " ";
		}cout << endl;
	}
}

int main(){
	int n,m;
	cin >> n >> m;
	vvi adj(n, vi(n, INT_MAX));
	for(int i = 0; i < m; i++){
		int f,s,wt;
		cin >> f >> s >> wt;
		adj[f][s] = wt;            //weighted directed graph
	}

	floydWarshall_algorithm(n, adj);
	return 0;
}