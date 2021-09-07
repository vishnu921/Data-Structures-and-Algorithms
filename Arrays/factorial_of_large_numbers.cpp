#include <bits/stdc++.h>
using namespace std;

//function to multiply number x to a number represented in res array in reversed form
void multiply(int x, vector<int> &res){
    int carry = 0;
    for(int i =0; i < res.size(); i++){
        int pr = res[i]*x + carry;
        res[i] = pr%10;
        carry = pr/10;
    }
    
    while(carry){
        res.push_back(carry%10);
        carry /= 10;
    }
}

//O(n^2)
vector<int> factorial(int n){
    vector<int> res;
    res.push_back(1);
    for(int i = 2; i <= n; i++){
        multiply(i, res);
    }
    
    reverse(res.begin(), res.end());
    return res;
}

int main(){
	int n;
	cin >> n;
	vector<int> res = factorial(n);
	for(auto digit: res){
		cout << digit;
	} cout << "\n";
	return 0;
}