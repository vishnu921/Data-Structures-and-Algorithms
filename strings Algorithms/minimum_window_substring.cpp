/*
Given a string 's'. The task is to find the smallest window length that contains all the characters of the 
given string at least one time.
For eg. A = “aabcbcdbca”, then the result would be 4 as of the smallest window will be “dbca”.
*/

#include <bits/stdc++.h>
using namespace std;

//O(N) variable sized slinding window with hashmap
string findSubString(string s){
    unordered_map<char, int> mp;
    
    int n = s.length();
    for(int i = 0; i < n; i++){
        mp[s[i]] = 0;
    }
    
    int i = 0, j = 0, start = 0;
    int ans = INT_MAX, cur = 0;
    while(j < n){
        if(mp[s[j]] == 0) cur++;
        mp[s[j]]++;
        
        while(cur == mp.size()){
            if(mp[s[i]] == 1) break;
            else{
                mp[s[i]]--;
                i++;
            }
        }
        if (cur >= mp.size() && ans > j-i+1){
            ans = min(ans, j-i+1);
            start = i;
        }
        j++;
    }
    
    return s.substr(start, ans);
}

int main(){
	string s;
	cin >> s;
	cout << findSubString(s) << "\n";
	return 0;
}