/*
Given a graph, a source vertex in the graph, and a number k, find if there is a simple path, of path 
length greater than or equal to k,(without any cycle) starting from a given source and ending at any other vertex.
Source vertex should always be  0.
*/
#include <bits/stdc++.h>
using namespace std;
#define pi pair<int,int>

//dfs function with backtracking
bool helper(int u, int dis, int k, vector<pi> adj[], bool visited[]){
	//base case if path length is greater or equal to k return true
	if(dis >= k) return true;

	visited[u] = true;

	//recur for each adjacent nodes
	for(auto p: adj[u]){
		int v = p.first;
		int weight = p.second;
		if(!visited[v]){
			if(helper(v, dis+weight, k, adj, visited))
				return true;
		}
	}

	//if visiting node u doesn't give required path we remove it from
	//current path i.e. remove it from current recursion stack
	visited[u] = false;
	return false;
}

bool pathMoreThanK(vector<pi> adj[], int n, int k){
	bool visited[n];
	memset(visited, false, sizeof(visited));

	//we explore all the paths to find path with length greater than k
	if(helper(0, 0, k, adj, visited)){
		return true;
	}

	return false;
}

int main(){
	int n,m,k;
	cin >> n >> m;
	vector<pi> adj[n];
	for(int i = 0; i < m; i++){
		int f,s,wt;
		cin >> f >> s >> wt;
		adj[f].push_back({s, wt});
		adj[s].push_back({f, wt});
	}
	cout << "Enter path length: ";
	cin >> k;

	if(pathMoreThanK(adj, n, k)){
		cout << "YES\n";
	} else{
		cout << "NO\n";
	}
	return 0;
}