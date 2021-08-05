#include <bits/stdc++.h>
using namespace std;
#define MAX 100

class TrieNode{
    public:
    bool isLeaf;          //boolean variable: true if a row ends here
    TrieNode *child[2];       //child[0] represents 0 in the row and child[1] represents 1
    
    TrieNode(){
        isLeaf = false;
        child[0] = NULL;
        child[1] = NULL;
    }
};

/*
to solve this problem in o(r*c) we modify insert function
this insert function returns true only when a new row is created and return false otherwise
*/
bool insert(TrieNode *root, int M[MAX][MAX], int row, int col){
    TrieNode *cur = root;
    
    for(int i = 0; i < col; i++){
        int x = M[row][i];
        if(cur->child[x] == NULL){
            cur->child[x] = new TrieNode();
        }
        
        cur = cur->child[x];
    }
    if(cur->isLeaf){
        return false;
    }
    
    cur->isLeaf = true;
    return true;
}

vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col)
{
	//we create a trie of rows
    vector<vector<int>> res;
    TrieNode *root = new TrieNode();
    for(int i = 0; i < row; i++){
    	//if a new row is created add it to result
        if(insert(root, M, i, col)){
            vector<int> v;
            for(int j = 0; j < col; j++){
                v.push_back(M[i][j]);
            }
            res.push_back(v);
        } 
    }
    
    return res;
}

int main(){
	int n,m;
	cin >> n >> m;
	int M[MAX][MAX];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> M[i][j];
		}
	}

	vector<vector<int>> res = uniqueRow(M, n, m);
	cout << "Unique Rows:\n";
	for(auto v: res){
		for(auto i: v){
			cout << i << " ";
		} cout << endl;
	}
	return 0;
}