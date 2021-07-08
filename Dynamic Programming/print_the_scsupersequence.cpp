/*
Given two strings s and t, return the shortest string that has both s and t as subsequences.  
If multiple answers exist, you may return any of them.

(A string A is a subsequence of string B if deleting some number of characters from B (possibly 0, and the 
characters are chosen anywhere from B) results in the string A.)
*/

#include <bits/stdc++.h>
using namespace std;

//function to return longest common subsequence of 2 strings
string print_lcs(string s, string t){
	int n = s.length();
	int m = t.length();

	//first build the dp matrix to calculate length of lcs
	int dp[n+1][m+1];
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= m; j++){
			if(i == 0 || j == 0) dp[i][j] = 0;
			else if(s[i-1] == t[j-1]){
				dp[i][j] = 1 + dp[i-1][j-1];
			}
			else{
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}

	string res = "";
	int i = n, j = m;
	//traverse the path for finding lcs
	while(i > 0 && j > 0){
		if(s[i-1] == t[j-1]){
			res += s[i-1];
			i--;
			j--;
		}
		else if(dp[i-1][j] > dp[i][j-1]){
			i--;
		}
		else j--;
	}

	//the string we get from above is reverse of lcs since we are traversing dp from last
	//therefore first reverse it and then return it
	reverse(res.begin(), res.end());
	return res;
}

string shortest_common_supersequence(string s, string t, int n, int m){
	//we first find the lcs of both strings
	string lcs = print_lcs(s, t);
    string res = "";
    int i = 0, j = 0;
    
    //now for every character in lcs we count it only once and other characters to the result string
    for(char c: lcs){
        while(s[i] != c){
            res += s[i++];
        }
        while(t[j] != c){
            res += t[j++];
        }
        
        res += c;
        i++; j++;
    }
    
    //add remaining strings to result
    res = res + s.substr(i) + t.substr(j);
    return res;
}


int main(){
	string s, t;
	cin >> s >> t;
	int m = s.length();
	int n = t.length();

	cout << shortest_common_supersequence(s, t, m, n) << "\n";
	return 0;
}
