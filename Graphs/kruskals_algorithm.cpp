/*
Kruskal’s Algorithm builds the spanning tree by adding edges one by one into a growing spanning tree. 
Kruskal's algorithm follows greedy approach as in each iteration it finds an edge which has least 
weight and add it to the growing spanning tree.

Algorithm Steps:

    Sort the graph edges with respect to their weights.
    Start adding edges to the MST from the edge with the smallest weight until the edge of the largest weight.
    Only add edges which doesn't form a cycle , edges which connect only disconnected components.
*/

#include <bits/stdc++.h>
using namespace std;

class Edge{
public:
	int u, v, weight;

	Edge(int src, int dest, int wt){
		u = src;
		v = dest;
		weight = wt;
	}
};

bool comp(Edge a, Edge b){
	return (a.weight < b.weight);
}

//find operation for union-find algorithm of disjoint-sets data structure
int find(int i, int parent[]){
	if(i == parent[i]){
		return i;
	}

	return parent[i] = find(parent[i], parent);
}


//union operation for union-find algorithm of disjoint-sets data structure
void makeUnion(int u, int v, int parent[], int rank[]){
	u = find(u, parent);
	v = find(v, parent);

	if(rank[u] < rank[v]){
		parent[u] = v;
	}
	else if(rank[u] > rank[v]){
		parent[v] = u;
	}
	else{
		parent[v] = u;
		rank[u]++;
	}
}


int KruskalAlgorithm(int n, int m, vector<Edge> &edges){
	//sort the edges based on their weights
	sort(edges.begin(), edges.end(), comp);

	//create disjoint set
	int parent[n], rank[n];
	for(int i = 0; i < n; i++){
		parent[i] = i;
		rank[i] = 0;
	}

	int mstCost = 0;
	vector<Edge> mst;

	//iterate over each edge from min. weight to max. weight
	for(Edge e: edges){
		//if the nodes at the end of this edge 'e' are already in 
		//same set then do not
		//else add this edge to mst
		if(find(e.u, parent) != find(e.v, parent)){
			mstCost += e.weight;
			mst.push_back(e);
			makeUnion(e.u, e.v, parent, rank);
		}
	}

	for(Edge e: mst){
		cout << e.u << "-" << e.v << " weight: " << e.weight << endl;
	}

	return mstCost;
}

int main(){
	int n, m;
	cin >> n >> m;
	vector<Edge> edges;
	for(int i = 0; i < m; i++){
		int f, s, wt;
		cin >> f >> s >> wt;
		edges.push_back(Edge(f,s,wt));
	}

	int mstCost = KruskalAlgorithm(n, m, edges);
	cout << "cost of MST: " << mstCost << "\n";
	return 0;
}