#include <bits/stdc++.h>
using namespace std;

class Edge{
public:
	int u,v,weight;
	Edge(int f, int s, int wt){
		u = f;
		v = s;
		weight = wt;
	}
};

void bellmanFord_Algorithm(int n, int s, vector<Edge> &edges){
	int dist[n];
	for(int i = 0; i < n; i++){
		dist[i] = INT_MAX;
	}
	dist[s] = 0;

	//relax every node exactly n-1 times
	for(int i = 0; i < n-1; i++){
		for(auto e: edges){
			if(dist[e.u] != INT_MAX && dist[e.v] > dist[e.u] + e.weight){
				dist[e.v] = dist[e.u] + e.weight;
			}
		}
	}

	//check for negetive cycle
	bool flag = false;
	for(auto e: edges){
		if(dist[e.u] != INT_MAX && dist[e.v] > dist[e.u] + e.weight){
			flag = true;
			break;
		}
	}

	if(flag){
		cout << "Negetive cycle present\n";
		return;
	}

	for(int i=0; i < n; i++){
		cout << i  << "\t" << dist[i] << "\n";
	}
}

int main(){
	int n,m,src;
	cin >> n >> m;
	vector<Edge> edges;
	for(int i = 0; i < m; i++){
		int f,s,wt;
		cin >> f >> s >> wt;
		edges.push_back(Edge(f,s,wt));
	}
	cout << "Enter source: ";
	cin >> src;

	bellmanFord_Algorithm(n, src, edges);
	return 0;
}