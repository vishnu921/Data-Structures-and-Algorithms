#include <bits/stdc++.h>
using namespace std;

void printBFS(vector<int> adj[], int s, bool visited[]){
	queue<int> q;
	q.push(s);
	visited[s] = true;

	while(!q.empty()){
		int i = q.front();
		q.pop();
		//process the node
		cout << i << " ";
		//push adjacent nodes of i which are not
		// visited yet into queue
		for(auto u: adj[i]){
			if(visited[u]) continue;
			q.push(u);
			visited[u] = true;
		}
	}
}

void BFS(vector<int> adj[], int n){
	//visited[] array to store if we have visited a node or not
	bool visited[n];
	memset(visited, false, sizeof(visited));

	//since we can have a disconnected graph we use
	//this for loop
	for(int i = 0; i < n; i++){
		if(!visited[i]){
			printBFS(adj, i, visited);
			cout << "\n";
		}
	}
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

	BFS(adj, n);
	return 0;
}