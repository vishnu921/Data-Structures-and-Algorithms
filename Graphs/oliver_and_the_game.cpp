#include <bits/stdc++.h>
using namespace std;

//this problem can be solved using euler tour of tree
void dfs(int u, int &time, vector<int> adj[], int disc[], int out[], bool visited[]){
	visited[u] = true;
	disc[u] = ++time;

	for(auto v: adj[u]){
		if(!visited[v]){
			dfs(v, time, adj, disc, out, visited);
		}
	}
	out[u] = ++time;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<int> adj[n+1];
	for(int i = 1; i < n; i++){
		int f,s;
		cin >> f >> s;
		adj[f].push_back(s);
		adj[s].push_back(f);
	}


	//we solve this problem using euler tour of tree
	bool visited[n+1];
	memset(visited, false, sizeof(visited));
	int disc[n+1], out[n+1];
	int time = 1;
	dfs(1, time, adj, disc, out, visited);
	int q;
	cin >> q;
	while(q--){
		int a,b,c;
		cin >> a >> b >> c;
		//if a = 0 bob move from house c to 1 and we check that is b in between
		//the path from c to 1 if yes then we print "YES" else print "NO"
		//now if a = 1 bob move from house c 'away' from 1 so we now check
		//is house 'c' is between 1 & b or not if it is between 1 & 'b' that means
		//moving away from 1 starting from c we will reach b. This is the reason we
		//swap b&c if a == 1
		if(a==1) swap(c,b);
		if(disc[b] <= disc[c] && out[b] >= out[c]){
			cout << "YES\n";
		}
		else cout << "NO\n";
	}
	return 0;
}
/*
sample input:
9
1 2
1 3
2 6
2 7
6 9
7 8
3 4
3 5
5
0 2 8
1 2 8
1 6 5
0 6 5
1 9 1
*/