/*
A group of edges that connects two set of vertices in a graph is called cut in graph theory. So, at every step 
of Prim’s algorithm, we find a cut (of two sets, one contains the vertices already included in MST and other 
contains rest of the vertices), pick the minimum weight edge from the cut and include this vertex to MST 
Set (the set that contains already included vertices).

How does Prim’s Algorithm Work? The idea behind Prim’s algorithm is simple, a spanning tree means all 
vertices must be connected. So the two disjoint subsets (discussed above) of vertices must be connected 
to make a Spanning Tree. And they must be connected with the minimum weight edge to make it a Minimum Spanning Tree.

<--------------------------------------------------------->
Algorithm 
1) Create a set mstSet that keeps track of vertices already included in MST. 
2) Assign a key value to all vertices in the input graph. Initialize all key values as INFINITE. Assign 
key value as 0 for the first vertex so that it is picked first. 
3) While mstSet doesn’t include all vertices 
….a) Pick a vertex u which is not there in mstSet and has minimum key value. 
….b) Include u to mstSet. 
….c) Update key value of all adjacent vertices of u. To update the key values, iterate through all adjacent
 vertices. For every adjacent vertex v, if weight of edge u-v is less than the previous key value of v, 
 update the key value as weight of u-v
<------------------------------------------------------------>

The idea of using key values is to pick the minimum weight edge from cut. The key values are
 used only for vertices which are not yet included in MST, the key value for these vertices 
 indicate the minimum weight edges connecting them to the set of vertices included in MST.
*/

#include <bits/stdc++.h>
using namespace std;
#define pi pair<int, int>

void PrimAlgorithm(int n, vector<pi> adj[]){
	//array to store the MST 
	int parent[n];        //parent[i] stores parent of ith node

	//key[i] stores minimum weight
	int key[n];

	//mstSet[i] = true if the ith node is included in MST
	bool mstSet[n];

	for(int i = 0; i < n; i++){
		key[i] = INT_MAX, mstSet[i] = false;
	}

	//prioirty queue stores pair of node and minimum weight of edge to reach at that node
	priority_queue<pi, vector<pi>, greater<pi>> pq;

	key[0] = 0;
	parent[0] = -1;
	pq.push({0, 0});

	while(!pq.empty()){
		int u = pq.top().second;
		pq.pop();

		//mark it added to MST
		mstSet[u] = true;

		//iteratre over its adjacent nodes and update their key and parent
		for(auto v: adj[u]){
			int i = v.first;
			int weight = v.second;

			if(mstSet[i] == false && weight < key[i]){
				parent[i] = u;
				key[i] = weight;
				pq.push({weight, i});
			}
		}
	}

	//printing MST
	for(int i = 1; i < n; i++){
		cout << parent[i] << "-" << i << " weight: " << key[i] << "\n";
	}
}

int main(){
	int n, m;
	cin >> n >> m;
	vector<pi> adj[n];
	for(int i = 0; i < m; i++){
		int f,s,w;
		cin >> f >> s >> w;
		adj[f].push_back({s, w});
		adj[s].push_back({f, w});
	}

	PrimAlgorithm(n, adj);
	return 0;
}


/*
Input:  9 14
		0 1 4
		0 7 8
		1 2 8
		1 7 11
		2 3 7
		2 5 4
		2 8 2
		3 4 9
		3 5 14
		4 5 10
		5 6 2
		6 7 1
		6 8 6
		7 8 7

Output: 0-1 weight: 4
		1-2 weight: 8
		2-3 weight: 7
		3-4 weight: 9
		2-5 weight: 4
		5-6 weight: 2
		6-7 weight: 1
		2-8 weight: 2

cost of MST = 4+8+7+9+4+2+1+2 = 37
*/
