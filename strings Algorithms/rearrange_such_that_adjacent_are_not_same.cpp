#include <bits/stdc++.h>
using namespace std;
typedef pair<int,char> pic;

string rearrangeString(string s){
   int n = s.length();
    vector<int> count(26,0);
    priority_queue<pic, vector<pic>> pq;
    
    for(int i = 0; i < n; i++){
        count[s[i]-'a']++;
    }
    
    for(int i = 0; i < 26; i++){
        if(count[i])
            pq.push(make_pair(count[i], i+'a'));
    }
    
    if(2*pq.top().first > n+1) return "-1";
    
    pic prev = {-1, '#'};
    int i = 0;
    while(!pq.empty()){
        pic cur = pq.top();
        pq.pop();
        cur.first--;
        s[i++] = cur.second;
        if(prev.first > 0) pq.push(prev);
        prev = cur;
    }
    
    return s;
}
int main(){
	string s;
	cin >> s;
	cout << rearrangeString(s) << "\n";
	return 0;
}