#include <bits/stdc++.h>
using namespace std;

int search(int a[], int n, int x){
	int l = 0, r = n-1;
	while(l <= r){
		int mid = l + (r-l)/2;
		if(a[mid] <= x && (mid == n-1 || a[mid+1] > x)) return mid;
		else if(a[mid] > x){
			r = mid-1;
		} else{
			l = mid+1;
		}
	}

	return -1;
}

void solve(int a[], int cum[], int n){
	int m;
	cin >> m;

	int pos = search(a, n, m);
	cout << pos+1 << " " << cum[pos] << "\n";
}

int main(){
    int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a, a+n);
	int cum[n];
	cum[0] = a[0];
	for(int i = 1; i < n; i++){
		cum[i] = cum[i-1] + a[i];
	}
	int q;
	while(q--){
		solve(a, cum, n);
	}
    return 0;
}