#include <bits/stdc++.h>
using namespace std;

/*
Binary exponentiation is a technique to calculate a^n in O(logn) mulitplications
since a^(b+c) = (a^b)*(a^c)
therefore a^(2b) = (a^b)^2
*/
long long binpow(long long a, long long n){
	if(n == 0) return a;
	long long res = 1;
	while(n){
		if(n&1) res = res*a;
		a = a*a;
		n = n>>1;   //divided by 2
	}

	return res;
}

int main(){
	long long a, n;
	cin >> a >> n;
	cout << binpow(a, n) << endl;
	return 0;
}