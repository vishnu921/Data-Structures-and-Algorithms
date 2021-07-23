/*
Given a square chessboard, the initial position of Knight and position of a target. Find out the 
minimum steps a Knight will take to reach the target position.

Note:
The initial and the target position co-ordinates of Knight have been given accoring to 1-base indexing.
*/

#include <bits/stdc++.h>
using namespace std;
//knight's moves
int x[] = {-1, 1, 2, 2, 1, -1, -2, -2};
int y[] = {2, 2, 1, -1, -2, -2, -1, 1};

//function to check whether a given cell is inside chessboard or not
bool isInsideBoard(int i, int j, int n){
    if(i > n || j > n || i < 1 || j < 1)
        return false;
        
    return true;
}

int MinStepsToReachTarget(vector<int> &KnightPos, vector<int> &target, int n){
	//board[i][j] stores whether we have visited the cell or not
	vector<vector<int>> board(n+1, vector<int>(n+1, -1));

	queue<pair<int, int>> q;

	q.push({KnightPos[0], KnightPos[1]});
	board[KnightPos[0]][KnightPos[1]] = 0;

	while(!q.empty()){
		pair<int, int> cur = q.front();
		q.pop();
		int i = cur.first;
		int j = cur.second;
		int dist = board[i][j];

		//if target is reached(BFS traversal ensures
		//that if a node is reached then it is also the
		//shortest path of it from the source)
		if(i == target[0] && j == target[1]){
			return dist;
		}

		for(int k = 0; k < 8; k++){
			int r = i + x[k];
			int c = j + y[k];

			//if the cell is inside and not visited
			if(isInsideBoard(r, c, n) && board[r][c] == -1){
				board[r][c] = dist+1;
				q.push({r, c});
			}
		}
	}

	//if no path found
	return INT_MAX;
}

int main(){
	int n;
	cin >> n;
	vector<int> KnightPos(2), target(2);
	cin >> KnightPos[0] >> KnightPos[1];
	cin >> target[0] >> target[1];

	cout << MinStepsToReachTarget(KnightPos, target, n) << "\n";
	return 0;
}