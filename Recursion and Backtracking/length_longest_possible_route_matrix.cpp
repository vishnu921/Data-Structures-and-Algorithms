/*
Given an M x N matrix, with a few hurdles arbitrarily placed, calculate the length of longest possible
 route possible from source to destination within the matrix. We are allowed to move to only adjacent 
 cells which are not hurdles. The route cannot contains any diagonal moves and a location once visited 
 in a particular path cannot be visited again.
*/

#include <bits/stdc++.h>
using namespace std;
#define vvi vector<vector<int>> 
#define vi vector<int>
int x[4] = {1, -1, 0, 0};
int y[4] = {0, 0, 1, -1};


bool issafe(int m, int n, int r, int c, vvi &mat, vvi &visited){
	return (r >= 0 && c >= 0 && r < m && c < n && mat[r][c] != 0 && visited[r][c] == 0);
}


/*
mat = input matrix with safe cell marked as 1
visited = matrix with visited cells marked as 1
m = number of rows, n = number of columns
cur = length of current path
ans = length of longest possible path
r, c = current cell
end[] = target position
*/
void solve(vvi &mat, int m, int n, int r, int c, int end[], int cur, int &ans, vvi &visited){
	//base case: if target position reached update ans if cur >= ans
	if(r == end[0] && c == end[1]){
		ans = max(ans, cur);
		return;
	}
	int nr, nc;
	//solve for every(up,down,right,left) direction
	for(int i = 0; i < 4; i++){
		nr = r+x[i];
		nc = c+y[i];
		//if it is safe to move to mat[nr][nc]
		if(issafe(m, n, nr, nc, mat, visited)){
			//mark mat[nr][nc] visited
			visited[nr][nc] = 1;
			//recur 
			solve(mat, m, n, nr, nc, end, cur+1, ans, visited);
			//backtracking
			visited[nr][nc] = 0;
		}
	}
}

int longestPossibleRoute(vvi &mat, int m, int n, int r, int c, int end[]){
	vvi visited(m, vi(n,0));
	int ans = 0;
	visited[r][c] = 1;
	solve(mat, m, n, r, c, end, 0, ans, visited);
	return ans;
}

int main(){
	int m, n;
	cin >> m >> n;
	vvi mat(m, vi(n));
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			cin >> mat[i][j];
		}
	}
	int start[2], end[2];
	cin >> start[0] >> start[1] >> end[0] >> end[1];
	cout << longestPossibleRoute(mat, m, n, start[0], start[1], end) << endl;
	return 0;
}