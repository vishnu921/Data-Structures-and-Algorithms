/*
Given an undirected graph and an integer M. The task is to determine if the graph can be colored 
with at most M colors such that no two adjacent vertices of the graph are colored with the same color. 
Here coloring of a graph means the assignment of colors to all vertices. Print 1 if it is possible to 
colour vertices and 0 otherwise.
*/

#include <bits/stdc++.h>
using namespace std;

//function to check if it is safe to assign color c to vertex v
bool issafe(bool graph[100][100], int v, int n, int c, int color[]){
	//check v's adjecent vertices whether they are assigned same color or not
	for(int i = 0; i < n; i++){
		if(graph[i][v] == 1 && color[i] == c){
			return false;
		}
	}
	return true;
}

bool solveColoring(bool graph[100][100], int v, int m, int n, int color[]){
	//if all vertices are coloured return true
	if(v == n){
		//print all v vs their color
		for(int i = 0; i < n; i++){
			cout << i+1 << ": " << color[i] << endl;
		}
		return true;
	}

	//considering current vertex v try different colours
	for(int i = 1; i <= m; i++){
		//check if it is safe to assign color i to vertex v
		if(issafe(graph, v, n, i, color)){
			color[v] = i;
			//recur for rest of the vertices
			if(solveColoring(graph, v+1, m, n, color))
				return true;

			//if assigning color i to vertex v didn't lead to
			//any solution them remove it
			color[v] = 0;
		}
	}
	return false;
}

bool graphColoring(bool graph[100][100], int m, int n){
	//array to store colours assigned to the vertices
	int color[n] = {0};
	//start from first vertix
	return solveColoring(graph, 0, m, n, color);
}

int main(){
	int n, m, e;
	cin >> n >> m >> e;
	bool graph[100][100];
	for(int i = 0; i < n; i++){
		memset(graph[i], 0, sizeof(graph[i]));
	}

	for(int i = 0; i < e; i++){
		int v1, v2;
		cin >> v1 >> v2;
		graph[v1-1][v2-1] = 1;
		graph[v2-1][v1-1] = 1;
	}

	cout << graphColoring(graph, m, n) << "\n";
	return 0;
}