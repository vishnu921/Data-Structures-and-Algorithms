#include <bits/stdc++.h>
using namespace std;

bool isCycle_DFS(int s, vector<int> adj[], bool visited[], bool recStack[]){
	visited[s] = true;
	recStack[s] = true;

	for(auto i: adj[s]){
		//if the ith node is not visited[] recur to visit it
		//and if it returns true return true
		if(!visited[i] && isCycle_DFS(i, adj, visited, recStack)){
			return true;
		}
		//else if ith node is visited and is present in recursion stack
		//that means cycle is present
		else if(recStack[i]) return true;
	}

	//remove current node from recursion stack as we move out from its function
	recStack[s] = false;
	return false;
}

bool isCycle(vector<int> adj[], int n){
	bool visited[n];
	//recStack[i] = true if the ith node is visited and is present in the recursion stack
	//if(visited[i] == true and recStack[i] == false) this means that 
	//the ith node is visited but is not present in the recursion stack
	bool recStack[n];
	memset(visited, false, sizeof(visited));
	memset(recStack, false, sizeof(recStack));

	for(int i = 0; i < n; i++){
		if(!visited[i] && isCycle_DFS(i, adj, visited, recStack)){
			return true;
		}
	}

	return false;
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

	if(isCycle(adj, n)){
		cout << "cycle is found\n";
	}
	else cout << "cycle not Found\n";
	return 0;
}