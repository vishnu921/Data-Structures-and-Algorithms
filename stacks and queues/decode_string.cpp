/*
Decode String
Given a string(S) consisting of ‘I’ and ‘D’ where ‘I’ denotes an increasing order and ‘D’ denotes the decreasing order. Decode S to construct a minimum number without repeating digits. Every character in S represents how the relationship between the adjacent digits should be while constructing the number. The digits should be in the range 1 to 9 (inclusive).
Note: The number of digits in the output is one more than the number of characters in the input.
*/
#include <bits/stdc++.h>
using namespace std;

string decode_string(string s){
    string res = "";
    int n = s.length();
    stack<int> st;
    for(int i = 0; i <= n; i++){
        st.push(i+1);
        if(i == n || s[i] == 'I'){
            while(!st.empty()){
                res += to_string(st.top());
                st.pop();
            }
        }
    }
    return res;
}

int main(){
    string s;
    cin >> s;
    cout << decode_string(s) << endl;
    return 0;
}