#include <bits/stdc++.h>
using namespace std;

//this needs to updated :(
bool match(string wild, string s)
{
    int m = wild.length();
    int n = s.length();
    bool dp[m+1][n+1];
    dp[0][0] = true;
    for(int i = 1; i <= n; i++){
        if(wild[0] == '*') dp[0][i] = true;
        else dp[0][i] = false;
    }
    for(int i = 1; i <= m; i++){
        if(wild[i-1] == '*') dp[i][0] = dp[i-1][0];
        else dp[i][0] = false;
    }
    
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(wild[i-1] == '*'){
                dp[i][j] = dp[i-1][j] || dp[i-1][j-1] || dp[i][j-1];
            } 
            else if(wild[i-1] == '?' || wild[i-1] == s[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                dp[i][j] = false;
            }
        }
    }
    
    return dp[m][n];
}

int main(){
	string s,wild;
	cin >> s >> wild;
	cout << match(wild, s) << "\n";
	return 0;
}