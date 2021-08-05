/*
problem link: https://www.hackerrank.com/challenges/journey-to-the-moon/problem
TO PASS ALL TEST CASES use long long instead of int
*/

#include <bits/stdc++.h>
using namespace std;
#define pi pair<int,int>

//simple dfs function to count nodes in each connected components
void dfs(int u, vector<int> adj[], bool visited[], int &count){
	visited[u] = true;
	count++;

	for(auto v: adj[u]){
		if(!visited[v]){
			dfs(v, adj, visited, count);
		}
	}
}


int JourneyToMoon(int n, vector<pi> &astronaut){
	//first we create adjacency list by considering edge between given pair of astronauts
	vector<int> adj[n];
	for(int i = 0; i < astronaut.size(); i++){
		int f = astronaut[i].first, s = astronaut[i].second;
		adj[f].push_back(s);
		adj[s].push_back(f);
	}

	//Now in this graph each connected component represents a country
	//so we get the count of connected components and the number of nodes in them
	//and store them in an array
	bool visited[n];
	memset(visited, false, sizeof(visited));
	vector<int> res;                            //array to store count of astronauts in each country
	for(int i = 0; i < n; i++){
		if(!visited[i]){
			int count = 0;
			dfs(i, adj, visited, count);
			res.push_back(count);
		}
	}

	//now we have count of astronauts in each country
	//lets connected components be (0,1), (2,3,4), (5,6)
	//in this graph the number of valid pairs we can make = 16 ((2*5 + 3*4 + 2*5)/2)
	int ans = 0;
	for(int i = 0; i < res.size(); i++){
		ans += res[i]*(n-res[i]);
	}

	//we counted each pair twice so we return half
	return ans/2;
}

int main(){
	int n,m;
	cin >> n >> m;
	vector<pi> astronaut;
	for(int i = 0; i < m; i++){
		int f,s;
		cin >> f >> s;
		astronaut.push_back({f,s});
	}

	cout << JourneyToMoon(n, astronaut);
	return 0;
}