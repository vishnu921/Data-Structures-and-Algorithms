/*
Find the number of occurrences of a given search word in  a 2d-Array of characters where the word can go up, 
down, left, right and around 90 degree bends.
*/
#include <bits/stdc++.h>
using namespace std;
#define vvc vector<vector<char>>
#define vc vector<char>
int x[] = { 1, 0, -1, 0};
int y[] = {0, 1, 0, -1};

bool isP(int r, int c, int n, int m){
    if(r >= 0 && r < n && c >= 0 && c < m){
        return true;
    }
    return false;
}
void dfs(int r, int c, int n, int m, int idx, int len, int &res, vvc &mat, string &target){
    if(idx == len-1){
        res++;
        return;
    }

    //marking visited characters of matrix
    //because one character cannot be taken twice or more
    char ch = mat[r][c];
    mat[r][c] = '#';
    for(int k = 0; k < 4; k++){
        int i = r + x[k];
        int j = c + y[k];
        if(isP(i, j, n, m) && mat[i][j] == target[idx+1]){
            dfs(i, j, n, m, idx+1, len, res, mat, target);
        }
    }
    //unmarking visited
    mat[r][c] = ch;
}
int findOccurrence(vvc &mat, string target){
    int res = 0;
    int n = mat.size();
    int m = mat[0].size();
    int len = target.size();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(mat[i][j] == target[0]){
                dfs(i, j, n, m, 0, len, res, mat, target);
            }
        }
    }
    return res;
}

int main(){
	int n,m;
	string s;
	cin >> n >> m;
	vvc mat(n, vc(m));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> mat[i][j];
		}
	}
	cout << "Enter string: ";
	cin >> s;
	cout << findOccurrence(mat, s) << "\n";
	return 0;
}