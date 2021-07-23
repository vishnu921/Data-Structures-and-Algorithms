/*
A graph is bipartite in which all the vertices in it can be divided into 2 mutually exclusive and mutually exhaustive
sets and every edges are across sets i.e. there should not be any edge between 2 vertices in same set

Given an adjacency list of a graph adj  of V no. of vertices having 0 based index. 
Check whether the graph is bipartite or not.
*/

#include <bits/stdc++.h>
using namespace std;

//a bipartite graph is possible if the vetices of graph can be colored using 2 colors
//such that no 2 adjacent nodes have same color
//A graph with cycle of odd number of nodes can never be bipartite
bool isBipartite(vector<int> adj[], int n){
	int color[n];
	memset(color, -1, sizeof(color));

	for(int i = 0; i < n; i++){			//handling connected components
		if(color[i] == -1){
			queue<int> q;
			q.push(i);
			color[i] = 0;			//assign a color letsay '0' to starting node of this component

			while(!q.empty()){
				int s = q.front();
				q.pop();

				for(auto u: adj[s]){
					//if the adjacent node is unvisited assign it color and push it into the queue
					if(color[u] == -1){
						//assign the color node other than its parent's color
						//if parent's color = 0 assign color = 1 to current node
						//else if parent's color = 1 assign color = 0 to current node
						color[u] = 1 - color[s];
						q.push(u);
					}
					//else if adjacent node is visited and if its color is same as its parent
					//then it is not a bipartite graph
					else if(color[u] == color[s]) return false;
				}
			}
		}
	}

	return true;
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

	if(isBipartite(adj, n)){
		cout << "Graph is bipartite\n";
	}
	else cout << "Graph is not bipartite\n";
	return 0;
}