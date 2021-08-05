/*
You are given an n x n integer matrix board where the cells are labeled from 1 to n2 in a Boustrophedon style 
starting from the bottom left of the board (i.e. board[n - 1][0]) and alternating direction each row.

You start on square 1 of the board. In each move, starting from square curr, do the following:

-> Choose a destination square next with a label in the range [curr + 1, min(curr + 6, n2)].
    This choice simulates the result of a standard 6-sided die roll: i.e., there are always at most 6 destinations, 
    regardless of the size of the board.
-> If next has a snake or ladder, you must move to the destination of that snake or ladder. Otherwise, you move to next.
	The game ends when you reach the square n2.

A board square on row r and column c has a snake or ladder if board[r][c] != -1. The destination of that snake or 
ladder is board[r][c]. Squares 1 and n2 do not have a snake or ladder.

Note that you only take a snake or ladder at most once per move. If the destination to a snake or ladder is the start 
of another snake or ladder, you do not follow the subsequent snake or ladder.

For example, suppose the board is [[-1,4],[-1,3]], and on the first move, your destination square is 2. 
You follow the ladder to square 3, but do not follow the subsequent ladder to 4.

Return the least number of moves required to reach the square n2. If it is not possible to reach the square, return -1.
*/

#include <bits/stdc++.h>
using namespace std;
#define vvi vector<vector<int>>
#define vi vector<int>
#define pi pair<int,int>

//function to convert a number to its position in the board
pair<int,int> numToPos(int num, int n){
    int r = (num-1)/n, c = (num-1)%n;
    
    int x = n-1-r;
    int y = r%2 == 0 ? c : n-1-c;
    
    return {x,y};
}

//in this problem we consider each i from 1 to n*n as a node and there is a edge
//between i and each node between [i+1, min(i+6, n*n)]
//also we are provided snakes and ladders, for this follow below conditions
// -> lets there is a node i and there is a ladder from i+3 to j
// -> since there is a ladder at i+3 as soon as we reach from i to i+3
//	  we have to move to j, hence it concludes that we must provide edge
//	  between i and j
//Now we have a unweighted digraph we do simple BFS to find shortes path(minimum throws)
//from 1 to n*n
int snakesAndLadders(vvi &board, int n){
    int nsq = n*n;                   //nsq stores value of n^2
    
    vector<bool> visited(nsq+1, false);
    queue<int> q;
    q.push(1);
    visited[1] = true;
    int count = 0;
    
    while(!q.empty()){
        int m = q.size();
        for(int i = 0; i < m; i++){
            int u = q.front();
            q.pop();
            
            if(u == nsq) return count;
            
            for(int i  = 1; i <= 6 && u+i <= nsq; i++){
                int v = u+i;
                pair<int,int> p = numToPos(v,n);
                if(board[p.first][p.second] != -1){
                    v = board[p.first][p.second];
                }
                if(!visited[v]){
                    q.push(v);
                    visited[v] = true;
                }
            }
        }
        //increase the throw count after each level increases
        count++;
    }
    return -1;
}

int main(){
	int n, m;          //m is no. of snakes and ladders
	cin >> n >> m;
	vvi board(n, vi(n, -1));
	for(int i = 0; i < m; i++){
		int x,y,num;
		cin >> x >> y >> num;
		board[x][y] = num;
	}

	cout << snakesAndLadders(board, n) << "\n";
	return 0;
}