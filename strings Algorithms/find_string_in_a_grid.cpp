/*
Given a 2D grid of n*m of characters and a word, find all occurrences of given word in grid. 
A word can be matched in all 8 directions at any point. Word is said be found in a direction 
if all characters match in this direction (not in zig-zag form). The 8 directions are, horizontally 
left, horizontally right, vertically up, vertically down and 4 diagonal directions.
*/
#include <bits/stdc++.h>
using namespace std;
#define vvi vector<vector<int>>
#define vvc vector<vector<char>>
#define vi vector<int>
int x[] = {-1, 0, 1, 1, 1, 0, -1, -1};
int y[] = {1, 1, 1, 0, -1, -1, -1, 0};

bool found(vvc &grid, string &word, int r, int c){
    
    for(int k = 0; k < 8; k++){
        bool cur = true;
        int i = r, j = c;
        for(int idx = 0; idx < word.length(); idx++){
            if(i < 0 || j < 0 || i >= grid.size() || j > grid[0].size()){
                cur = false;
                break;
            }

            if(grid[i][j] != word[idx]){
                cur = false;
                break;
            }
            i += x[k];
            j += y[k];
        }
        if(cur == true) return true;
    }
    
    return false;
}

vvi searchWord(vvc grid, string word){
	vvi res;
    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[0].size(); j++){
            if(found(grid, word, i, j)){
                res.push_back({i, j});
            }
        }
    }
    
    return res;
}

int main(){
	int m, n;
	cin >> m >> n;
	vvc grid(m, vector<char>(n));
	string word;

	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			cin >> grid[i][j];
		}
	}

	cin >> word;
	vvi res = searchWord(grid, word);
	for(auto v: res){
		for(auto i: v){
			cout << i << " ";
		} cout << "\n";
	}
	return 0;
}