#include <bits/stdc++.h>
using namespace std;

bool isSafe(int u, int c, int n, bool graph[101][101], int color[]){
    for(int i = 0; i < n; i++){
        if(graph[u][i] == 1 && color[i] == c)
            return false;
    }
    
    return true;
}


bool helper(int u, int n, int m, bool graph[101][101], int color[]){
    if(u == n) return true;
    
    for(int i = 1; i <= m; i++){
        if(isSafe(u, i, n, graph, color)){
        	//color the adjacent node with next color
            color[u] = i;
            //recur for next node
            if(helper(u+1, n, m, graph, color)) return true;
            //if this doesn't give answer backtracking
            color[u] = 0;
        }
    }
    
    return false;
}

//Function to determine if graph can be coloured with at most M colours such
//that no two adjacent vertices of graph are coloured with same colour.
bool graphColoring(bool graph[101][101], int m, int v)
{
    int color[v] = {};
    return helper(0, v, m, graph, color);
}

int main(){
	int n, m, e;
	cin >> n >> m >> e;
	bool graph[101][101];
	for(int i = 0; i < e; i++){
		int f,s;
		cin >> f >> s;
		graph[f-1][s-1] = 1;
		graph[s-1][f-1] = 1;
	}

	for(int i=0; i < n; i++){
		cout << "{";
		for(int j = 0; j < n; j++){
			cout << graph[i][j] << ", ";
		} cout << "},\n";
	}

	if(graphColoring(graph, m, n)){
		cout << "YES\n";
	} else{
		cout << "NO\n";
	}
	return 0;
}