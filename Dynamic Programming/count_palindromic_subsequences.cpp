#include <bits/stdc++.h>
using namespace std;

long long int  countPalindromicSubsequence(string s) {
  int n = s.length();
  long long int dp[n][n] = {};
  long long mod = 1e9+7;
  for(int gp = 0; gp < n; gp++){
      for(int i = 0, j = gp; j < n; i++, j++){
          if(gp == 0) dp[i][j] = 1;
          else if(s[i] == s[j]){
              dp[i][j] = (dp[i][j-1] + dp[i+1][j] + 1)%mod;
          } else{
              long long int x = (dp[i][j-1] + dp[i+1][j])%mod;
              long long int y = dp[i+1][j-1];
              dp[i][j] = ((x-y)%mod + mod)%mod;
          }
      }
  }
  
  return dp[0][n-1]%mod;
}

int main(){
	string s;
	cin >> s;
	cout << countPalindromicSubsequence(s) << "\n";
	return 0;
}