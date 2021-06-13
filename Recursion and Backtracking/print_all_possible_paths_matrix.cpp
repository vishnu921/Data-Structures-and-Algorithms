/*
The problem is to print all the possible paths from top left to bottom right of a mXn matrix with 
the constraints that from each cell you can either move only to right or down.

Examples : 

Input : 1 2 3
        4 5 6
Output : 1 4 5 6
         1 2 5 6
         1 2 3 6

Input : 1 2 
        3 4
Output : 1 2 4
         1 3 4
*/

#include <bits/stdc++.h>
using namespace std;
#define vvi vector<vector<int>>
#define vi vector<int>

//function returns true if it step is possible
bool ispossible(int m,int n, int r, int c){
	if(r < 0 || c < 0 || r >= m || c >= n) return false;
	return true;
}

/*
mat = input matrix
m = number of rows, n = number of columns
r = current row, c = current colomn
cur = current path
res = result vector of all possible paths
*/
void solve(vvi &mat, int m, int n, int r, int c, vi &cur, vvi &res){
	//if we reach destination push the current path to res vector
	if(r == m-1 && c == n-1){
		cur.push_back(mat[r][c]);
		res.push_back(cur);
		cur.pop_back();
		return;
	}

	//push mat[r][c] to current path
	cur.push_back(mat[r][c]);
	//if down movement is possible
	if(ispossible(m, n, r+1, c)){
		solve(mat, m, n, r+1, c, cur, res);
	}
	//if right movement is possible
	if(ispossible(m, n, r, c+1)){
		solve(mat, m, n, r, c+1, cur, res);
	}
	//backtracking
	cur.pop_back();
}

vvi printAllpaths(vvi &mat, int m, int n){
	vi cur;
	vvi res;
	solve(mat, m, n, 0, 0, cur, res);
	return res;
}

int main(){
	int m, n;
	cin >> m >> n;
	vvi mat(m, vi(n, 0));
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			cin >> mat[i][j];
		}
	}
	vvi res = printAllpaths(mat, m, n);
	for(auto v: res){
		for(auto i: v){
			cout << i << " ";
		}
		cout << "\n";
	}
	return 0;
}