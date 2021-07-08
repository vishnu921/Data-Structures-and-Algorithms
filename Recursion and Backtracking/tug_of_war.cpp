#include <bits/stdc++.h>
using namespace std;
#define pi pair<int, int>

void solve(int a[], int n, int i, int s1, int s2, int &mn, int &sum){
	if(i == n){
		if(mn > abs(s1-s2)){
			mn = abs(s1-s2);
			sum = s1;
		}
		return;
	}

	solve(a, n, i+1, s1+a[i], s2, mn, sum);
	solve(a, n, i+1, s1, s2+a[i], mn, sum);
}

int main(){
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	int mn_diff = INT_MAX;
	int sum = 0;
	solve(a, n, 0, 0, 0, mn_diff, sum);
	cout << sum << "\n";
	return 0;
}