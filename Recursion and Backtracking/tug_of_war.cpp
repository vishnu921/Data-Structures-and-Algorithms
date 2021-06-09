#include <bits/stdc++.h>
using namespace std;

bool solve(int a[], int n, int i, int s1, int s2){
	if(i == n){
		if(s1 == s2) return true;
		else return false;
	}

	if(s1 == s2) return true;

	solve(a, n, i+1, s1+a[i], s2);
}

int main(){
	int t,n;
	cin >> t;
	while(t--){
		cin >> n;
		int a[n];
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		if(solve(a,n,0,0,0)){
			cout << "YES\n";
		}
		else cout << "NO\n";
	}
	return 0;
}