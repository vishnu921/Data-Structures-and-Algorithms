/*
Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the 
destination at (N - 1, N - 1). Find all possible paths that the rat can take to reach 
from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 
'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat 
cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.

Note: In a path, no cell can be visited more than one time.
*/
#include <bits/stdc++.h>
using namespace std;
#define vvi vector<vector<int>>
#define vi vector<int>
#define vs vector<string>

char dir[] = {'U', 'R', 'D', 'L'};
int x[] = {-1, 0, 1, 0};
int y[] = {0, 1, 0, -1};

void DFS(vvi &maze, int n, int i, int j, string cur, vs &res){
	if(i >= n || j >= n || i < 0 || j < 0 || maze[i][j] == 0){
		return;
	}

	//if we reach the destination push the path
	//in the result array of paths
	if(i == n-1 && j == n-1){
		res.push_back(cur);
		return;
	}

	//visit current cell
	maze[i][j] = 0;

	//check path for each of the 4 directions
	for(int k = 0; k < 4; k++){
		int r = i + x[k];
		int c = j + y[k];
		DFS(maze, n, r, c, cur+dir[k], res);
	}

	//backtracking
	maze[i][j] = 1;
}

vs RatinMaze(vvi &maze, int n){
	vs res;

	DFS(maze, n, 0, 0, "", res);

	sort(res.begin(), res.end());

	if(res.size() == 0) res.push_back("NO Path found");
	return res;
}

int main(){
	int n;
	cin >> n;
	vvi maze(n, vi(n));
	for(int i = 0; i < n; i++){
		for (int j = 0; j < n; ++j){
			cin >> maze[i][j];
		}
	}

	vs res = RatinMaze(maze, n);
	for(string path: res){
		cout << path << "\n";
	}
	return 0;
}