/*
The set [1, 2, 3, ..., n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

    "123"
    "132"
    "213"
    "231"
    "312"
    "321"

Given n and k, return the kth permutation sequence.
*/

#include <bits/stdc++.h>
using namespace std;

string getPermutation(int n, int k){
	if(n == 1) return "1";
	string res = "";
	int fact = 1;
	vector<int> a;
	for(int i = 1; i <= n; i++){
		fact *= i;
		a.push_back(i);
	}

	k--;
	for(int i = 0; i < n; i++){
		fact = fact/(n-i);
		int index = (k/fact);
		res += to_string(a[index]);
		a.erase(a.begin()+index);
		k = k-index*fact;
	}
	return res;
}

int main(){
	int n, k;
	cin >> n >> k;
	cout << getPermutation(n, k) << "\n";
	return 0;
}