/*
There are n computers numbered from 0 to n-1 connected by ethernet cables connections forming a network 
where connections[i] = [a, b] represents a connection between computers a and b. Any computer can reach 
any other computer directly or indirectly through the network.

Given an initial computer network connections. You can extract certain cables between two directly connected 
computers, and place them between any pair of disconnected computers to make them directly connected. Return 
the minimum number of times you need to do this in order to make all the computers connected. If it's not 
possible, return -1. 
*/

#include <bits/stdc++.h>
using namespace std;

//simple dfs function to mark nodes visited
void dfs(int s, vector<int> adj[], bool visited[]){
    visited[s] = true;
    
    for(auto i: adj[s]){
        if(!visited[i]){
            dfs(i, adj, visited);
        }
    }
}

int makeConnected(int n, vector<vector<int>>& connections) {
	//we need minimum of (n-1) connections/wire to connect all computers
    if(connections.size() < n-1) return -1;
    
    bool visited[n];
    memset(visited, false, sizeof(visited));
    vector<int> adj[n];
    int ans = 0;
    
    //construct a adjacency list to reduce time complexity
    for(auto c: connections){
        int f = c[0], s = c[1];
        adj[f].push_back(s);
        adj[s].push_back(f);
    }
    
    //simply find number of connected components
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            dfs(i, adj, visited);
            ans++;
        }
    }

    //minimum number of operations to make = connected networks - 1 
    return ans-1;
}

int main(){
	int n, m;
	cin >> n >> m;
	vector<vector<int>> connections;
	for(int i = 0; i < m; i++){
		int f,s;
		cin >> f >> s;
		connections.push_back({f,s});
	}

	cout << "Minimum operations to make network connected: " << makeConnected(n, connections) << "\n";
	return 0;
}