#include <bits/stdc++.h>
using namespace std;

bool isCycle_kahnsAlgorithm(vector<int> adj[], int n){
	int inDegree[n] = {};
	for(int i = 0; i < n; i++){
		for(auto u: adj[i]){
			inDegree[u]++;
		}
	}

	queue<int> q;
	int count = 0;    //count the number of nodes visited
	for(int i = 0; i < n; i++){
		if(inDegree[i] == 0)
			q.push(i);
	}

	while(!q.empty()){
		int i = q.front();
		q.pop();
		count++;

		for(auto u: adj[i]){
			inDegree[u]--;
			if(inDegree[u] == 0) q.push(u);
		}
	}

	//if all nodes are able to visit i.e. cycle is not present
	if(count == n) return false;
	//else cycle is present
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
	}

	if(isCycle_kahnsAlgorithm(adj, n)){
		cout << "cycle found\n";
	}
	else cout << "cycle not found\n";
	return 0;
}