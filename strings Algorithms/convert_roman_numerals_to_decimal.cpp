#include <bits/stdc++.h>
using namespace std;

int romanToDecimal(string s){
	unordered_map<char, int> mp;
    mp['I'] = 1;
    mp['V'] = 5;
    mp['X'] = 10;
    mp['L'] = 50;
    mp['C'] = 100;
    mp['D'] = 500;
    mp['M'] = 1000;
    
    int res = 0;
    
    for(int i = 0; i < s.size(); i++)
    {
    	//if current value of numeral is less than next numeral
    	//we subtract it from the res
        if(i+1 < s.size() && mp[s[i]] < mp[s[i+1]])
        {
            res -= mp[s[i]];
        }
        //else add it to the result
        else res += mp[s[i]];
    }
    
    return res;
}

int main(){
	string s;
	cin >> s;

	cout << romanToDecimal(s) << "\n";
	return 0;
}