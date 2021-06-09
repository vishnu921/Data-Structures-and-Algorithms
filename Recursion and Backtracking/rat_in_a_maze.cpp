/*
Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach 
the destination at (N - 1, N - 1). Find all possible paths that the rat can take to 
reach from source to destination. The directions in which the rat can move are 'U'(up), 
'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it 
is blocked and rat cannot move to it while value 1 at a cell in the matrix represents 
that rat can be travel through it.
Note: In a path, no cell can be visited more than one time.
*/
#include <bits/stdc++.h>
using namespace std;

void printSolution(vector<vector<int>> &sol, int n){
	cout << "---------------\n";
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << sol[i][j] << " ";
		}
		cout << '\n';
	}
}

void findPath(vector<vector<int>> &m, int n, int r, int c, vector<vector<int>> &sol){
	if(r == n-1 && c == n-1){
		sol[r][c] = 1;
		printSolution(sol, n);
		return;
	}

	//we return if positions is out of bound
	//or position is blocked or position is already visited
	if(r >= n || c >= n || r<0 || c<0 || m[r][c] == 0 || sol[r][c] == 1){
		return;
	}

	sol[r][c] = 1;
	findPath(m, n, r+1, c, sol);
	findPath(m, n, r, c-1, sol);
	findPath(m, n, r, c+1, sol);
	findPath(m, n, r-1, c, sol);
	sol[r][c] = 0;
}

void RatinMaze(vector<vector<int>> &m, int n){
	if(m[0][0] == 0 || m[n-1][n-1] == 0){
		cout << "No Path Possible\n";
		return;
	}
	vector<vector<int>> sol(n, vector<int>(n,0));

	findPath(m, n, 0, 0, sol);
}

#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<vector<int>> m(n, vector<int>(n,0));

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> m[i][j];
		}
	}

	RatinMaze(m, n);

	return 0;
}

//This is simple solution to understand clearly
// bool ispossible(vector<vector<int>> &m, int n, int r, int c, char dir){
//     if(dir == 'U'){
//         if(r == 0 || m[r-1][c] == 0) return false;
//     }
    
//     if(dir == 'R'){
//         if(c == n-1 || m[r][c+1] == 0) return false;
//     }
    
//     if(dir == 'D'){
//         if(r == n-1 || m[r+1][c] == 0) return false;
//     }
    
//     if(dir == 'L'){
//         if(c == 0 || m[r][c-1] == 0) return false;
//     }
    
//     return true;
// }

// void ratMaze(vector<vector<int>> &m, int n, int r, int c, string path, vector<string> &res){
//     if(r == n-1 && c == n-1){
//         res.push_back(path);
//         return;
//     }
    
//     if(ispossible(m, n, r, c, 'D')){
//         m[r][c] = 0;
//         ratMaze(m, n, r+1, c, path+'D', res);
//         m[r][c] = 1;
//     }
    
//     if(ispossible(m, n, r, c, 'L')){
//         m[r][c] = 0;
//         ratMaze(m, n, r, c-1, path+'L', res);
//         m[r][c] = 1;
//     }
    
      
//     if(ispossible(m, n, r, c, 'R')){
//         m[r][c] = 0;
//         ratMaze(m, n, r, c+1, path+'R', res);
//         m[r][c] = 1;
//     }
    
//     if(ispossible(m, n, r, c, 'U')){
//         m[r][c] = 0;
//         ratMaze(m, n, r-1, c, path+'U', res);
//         m[r][c] = 1;
//     }
// }

// vector<string> findPath(vector<vector<int>> &m, int n){
// 	vector<string> ans;
// 	if(m[n-1][n-1] == 0 || m[0][0] == 0) return {};
// 	ratMaze(m, n, 0, 0, "", ans);

// 	return ans;
// }
