#include <bits/stdc++.h>
using namespace std;

//function to detect cycle in undirected graph using DFS
bool isCycle_DFS(int s, int parent, vector<int> adj[], bool visited[]){

	visited[s] = true;
	for(auto u: adj[s]){
		//if the adjacent node is not visited and recur for visiting it
		if(!visited[u]){
			if(isCycle_DFS(u, s, adj, visited))
				return true;
		}
		//else if adjacent node is not parent and visited that means
		//cycle is present hence return true
		else if(u != parent){
			return true;
		}
	}

	return false;
}

//function to detect cycle in undirected graph using BFS
bool isCycle_BFS(int s, vector<int> adj[], bool visited[]){
	//queue stores pair of node and its parent
	queue<pair<int,int>> q;

	//push the first node of component into the queue
	q.push({s, -1});
	//mark first node of component visited
	visited[s] = true;

	//do BFS traversal and if cycle is found return true
	while(!q.empty()){
		pair<int, int> cur = q.front();
		q.pop();
		int i = cur.first;             //i = current node
		int parent = cur.second;        //parent = parent node of i
		for(auto u: adj[i]){
			//if adjacent node is not visited push it into the 
			//queue with parent as current node
			if(!visited[u]){
				q.push({u, i});
				visited[u] = true;
			}
			//else if adjacent node is not parent and visited that
			//means cycle is present
			else if(u != parent){
				return true;
			}
		}
	}

	return false;
}

bool isCycle(vector<int> adj[], int n){

	bool visited[n];

	memset(visited, false, sizeof(visited));
	bool DFS_ans = false;
	for(int i = 0; i < n; i++){
		if(!visited[i]){
			if(isCycle_DFS(i, -1, adj, visited)){
				DFS_ans = true;
				break;
			}
		}
	}

	memset(visited, false, sizeof(visited));
	bool BFS_ans = false;
	for(int i = 0; i < n; i++){
		if(!visited[i]){
			if(isCycle_BFS(i, adj, visited)){
				BFS_ans = true;
				break;
			}
		}
	}

	return (DFS_ans && BFS_ans);
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

	if(isCycle(adj, n)){
		cout << "cycle is found\n";
	}
	else cout << "cycle not Found\n";
	return 0;
}