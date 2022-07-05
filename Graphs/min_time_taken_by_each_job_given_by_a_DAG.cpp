/*
Given a Directed Acyclic Graph having V vertices and E edges, where each edge {U, V} 
represents the Jobs U and V such that Job V can only be started only after completion of 
Job U. The task is to determine the minimum time taken by each job to be completed where 
each Job takes unit time to get completed.

Problem: https://www.geeksforgeeks.org/minimum-time-taken-by-each-job-to-be-completed-given-by-a-directed-acyclic-graph/
*/

#include <bits/stdc++.h>
using namespace std;

void printOrder(vector<int> adj[], int n) {
	vector<int> indegree(n);      // vector to store indegree of node i
	vector<int> job(n);           // job[i] stores the time in which job i can be done

	for (int i = 0; i < n; i++) {
		for (auto j: adj[i]) {
			indegree[j]++;
		}
	}

	queue<int> q;

	for (int i = 0; i < n; i++) {
		if (indegree[i] == 0) {
			job[i] = 1;
			q.push(i);
		}
	}

	while (!q.empty()) {
		int u = q.front();
		q.pop();

		for (auto v: adj[u]) {
			indegree[v]--;
			if (indegree[v] == 0) {
				q.push(v);
				job[v] = job[u]+1;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cout << job[i] << " ";
	} cout << "\n";
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> adj[n];
	for (int i = 0; i < m; i++) {
		int f, s;
		cin >> f >> s;
		adj[f].push_back(s);
	}

	printOrder(adj, n);
	return 0;
}