/*
There are a total of N tasks, labeled from 0 to N-1. Some tasks may have prerequisites, 
for example to do task 0 you have to first complete task 1, which is expressed as a pair: [0, 1]
Given the total number of tasks N and a list of prerequisite pairs P, find if it is possible to finish all tasks.
*/
#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>

//function to detect cycle in a graph using DFS traversal
bool isCycle(int s, vector<int> adj[], vi &visited, vi &recStack){
    visited[s] = true;
    recStack[s] = true;
    
    for(auto i: adj[s]){
        if(!visited[i]){
            if(isCycle(i, adj, visited, recStack)) return true;
        }
        else if(recStack[i]) return true;
    }
    
    recStack[s] = false;
    return false;
}

bool isPossible(int n, vector<pair<int, int> >& prerequisites) {
	//building Directed graph which is stored in adjacency list
    vector<int> adj[n];
    for(auto e: prerequisites){
        adj[e.first].push_back(e.second);
    }

    //Now a cycle is present in this digraph then no topological order
    //exists for the tasks hence it is not possible to complete the task
    vi visited(n, false);
    vi recStack(n, false);

    for(int i = 0; i < n; i++){
        if(!visited[i] && isCycle(i, adj, visited, recStack)){
            return false;
        }
    }
    
    //if no cycle is present return true
    return true;
}

int main(){
	int n, m;
	cin >> n >> m;
	vector<pair<int,int>> prerequisites;
	for(int i = 0; i < m; i++){
		int f,s;
		cin >> f >> s;
		prerequisites.push_back(make_pair(f,s));
	}

	if(isPossible(n, prerequisites)){
		cout << "Yes\n";
	}
	else cout << "NO\n";
	return 0;
}