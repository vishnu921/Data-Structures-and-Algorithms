/*
Given a 2D board of letters and a word. Check if the word exists in the board. The word can be 
constructed from letters of adjacent cells only. ie - horizontal or vertical neighbors. The same 
letter cell can not be used more than once.
*/
#include <bits/stdc++.h>
using namespace std;
#define vvc vector<vector<char>>
#define vvi vector<vector<int>>
#define vi vector<int>
int x[4] = {1, -1, 0, 0};
int y[4] = {0, 0, 1, -1};

bool solve(vvc &board, int m, int n, int r, int c, string &word, int idx, vvi &visited){
	//base case if whole word is traversed
	if(idx == word.size()){
		return true;
	}

	//return false if r, c or idx are out of bound or if r,c already visited
	if(r < 0 || c < 0 || r >= m || c >= n || idx >= word.size() || visited[r][c] != 0)
		return false;

	if(word[idx] == board[r][c]){
		//mark current cell visited
		visited[r][c] = 1;
		int nr, nc;                    //nr = new row and nc = new column
		//recur in all 4 direction(up,down,right,left)
		for(int i = 0; i < 4; i++){
			nr = r+x[i];
			nc = c+y[i];
			//if selecting board[nr][nc] lead to solution return true
			if(solve(board, m, n, nr, nc, word, idx+1, visited)){
				return true;
			}
		}
		//backtracking
		visited[r][c] = 0;
	}

	return false;
}

bool isWordExists(vvc &board, int m, int n, string &word){
	vvi visited(m, vi(n, 0));

	//find first character of the word in the matrix
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			if(board[i][j] == word[0]){
				if(solve(board, m, n, i, j, word, 0, visited))
					return true;
			}
		}
	}

	return false;
}

int main(){
	int m, n;
	cin >> m >> n;
	vvc board(m, vector<char>(n));
	string word;
	for(int i=0; i < m; i++){
		for(int j = 0; j < n; j++){
			cin >> board[i][j];
		}
	}

	cin >> word;

	if(isWordExists(board, m, n, word)){
		cout << "YES\n";
	}
	else cout << "NO\n";

	return 0;
}