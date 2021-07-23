/*
Given a sorted dictionary of an alien language having N words and k starting alphabets of standard dictionary. 
Find the order of characters in the alien language.

Note: Many orders may be possible for a particular test case, thus you may return any valid order and output 
will be 1 if the order of string returned by the function is correct else 0 denoting incorrect string returned.
 
Example 1:

Input: 
N = 5, K = 4
dict = {"baa","abcd","abca","cab","cad"}
Output: bdac

Example 2:

Input: 
N = 3, K = 3
dict = {"caa","aaa","aab"}
Output: cab
*/
#include <bits/stdc++.h>
using namespace std;

//function to get topoSort of DAG
void topoSort(int i, vector<int> adj[], bool visited[], string &res){
    visited[i] = true;
    
    for(auto u: adj[i]){
        if(!visited[u]){
            topoSort(u, adj, visited, res);
        }
    }
    
    //Note: here character is added before the res
    //if added after we need to reverse the string before returning
    //it in the main function
    res = char(i+'a') + res;
}

string findOrder(string dict[], int n, int k){
	//create graph with adjaceny list
	vector<int> adj[k];
	bool visited[k];
    memset(visited, false, sizeof(visited));
    
    for(int i = 0; i < n-1; i++){
        int j = 0;
        //find first mismatching character of adjacent words
        while(j < min(dict[i].size(), dict[i+1].size())){
            if(dict[i][j] != dict[i+1][j]){
                int ind1 = dict[i][j]-'a';
                int ind2 = dict[i+1][j]-'a';
                
                //make an edge between mismatching characters
                adj[ind1].push_back(ind2);
                break;
            }
            j++;
        }
    }
    
    //get the topoSort
    string res = "";
    for(int i = 0; i < k; i++){
        if(!visited[i]){
            topoSort(i, adj, visited, res);
        }
    }
    
    return res;
}

int main(){
	int n, k;
	cin >> n >> k;
	string dict[n];
	for(int i = 0; i < n; i++){
		cin >> dict[i];
	}

	cout << findOrder(dict, n, k) << "\n";
	return 0;
}