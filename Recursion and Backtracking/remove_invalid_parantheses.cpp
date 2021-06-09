/*
Given a string s that contains parentheses and letters, remove the minimum number of invalid parentheses
 to make the input string valid.

Return all the possible results. You may return the answer in any order.
*/
#include <bits/stdc++.h>
using namespace std;

//function to return minimum number of invalid parantheses in the string
int isvalid(string s){
    if(s.empty()) return 0;
    stack<char> st;
    
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '('){
            st.push(s[i]);
        }
        else if(s[i] == ')'){
            if(st.empty() || (st.top() == ')')) st.push(s[i]);
            else if(st.top() == '('){
                st.pop();
            }            
        }
    }
    
    return st.size();
}

void solve(string s, int rem, vector<string> &ans, unordered_set<string> &rep){
	//if rem = 0 that means we cannot remove more parantheses
	//check if current string is valid, if valid push it into the answer
   if(rem == 0){
   //	cout << rem << " " << s << endl;
       int x = isvalid(s);
       if(x == 0) ans.push_back(s);
       return;
   }
    
    //remove every parantheses one by one
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '(' || s[i] == ')'){
            string s2 = s.substr(0, i)+s.substr(i+1);
            //if same string is generated again then continue
            if(rep.find(s2) != rep.end()) continue;
            rep.insert(s2);
            //recursively call for remaining string s2 and decrease rem(minimum removes allowed)
            solve(s2, rem-1, ans, rep);
        }
    }
}

vector<string> removeMinInvalidParantheses(string s){
	int n = isvalid(s);
	if(n == 0) return {s};
	if(n == s.length()) return {""};
	//set to ensure we do not repeat previously created strings
	unordered_set<string> rep;
	//result array of string
	vector<string> ans;

	solve(s, n, ans, rep);
	return ans;
}


int main(){
	string s;
	cin >> s;
	vector<string> res = removeMinInvalidParantheses(s);
	for(auto x: res){
		cout << x << "\n";
	}
	return 0;
}