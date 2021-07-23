#include <bits/stdc++.h>
using namespace std;

vector<int> kahns_algorithm_TopoSort(vector<int> adj[], int n){
	//consrtuct an array inDegree to store indegree of every node
	vector<int> inDegree(n, 0);
	for(int i = 0; i < n; i++){
		for(auto u: adj[i]){
			inDegree[u]++;
		}
	}

	vector<int> res;
	queue<int> q;
	//store all nodes with indegree = 0 in queue
	for(int i = 0; i < n; i++){
		if(inDegree[i] == 0){
			q.push(i);
		}
	}

	while(!q.empty()){
		//extract front of the queue and add it to topological order
		int i = q.front();
		q.pop();
		res.push_back(i);

		//iterate through all adjacent nodes of dequeued node i
		//and decrease their indegree by 1
		for(auto u: adj[i]){
			inDegree[u]--;
			//if in-degree(u) becomes 0 after decrement push it into
			//the queue
			if(inDegree[u] == 0){
				q.push(u);
			}
		}
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

	vector<int> res = kahns_algorithm_TopoSort(adj, n);
	for(int i = 0; i < n; i++){
		cout << res[i] << " ";
	}
	cout << endl;
	return 0;
}