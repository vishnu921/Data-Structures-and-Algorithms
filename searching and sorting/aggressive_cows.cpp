#include <bits/stdc++.h>
using namespace std;

bool isPossible(int a[], int n, int c, int x){
	int cur = 1, prev = 0;
	for(int i = 1; i < n; i++){
		if(a[i] - a[prev] >= x){
			cur++;
			prev = i;
		}
		if(cur == c){
			return true;
		}
	}

	return false;
}

int aggressiveCows(){
	int n,c;
	cin >> n >> c;
	int a[n];
	int mx = INT_MIN;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		mx = max(a[i], mx);
	}
	sort(a,a+n);
	int l = 0, h = mx;
	int res = 0;
	while(l <= h){
		int mid = l + (h-l)/2;
		// cout << l << " " << h << " " << mid << "\n";
		if(isPossible(a, n, c, mid)){
			l = mid+1;
			res = max(res,mid);
		} else{
			h = mid-1;
		}
	}

	return res;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		cout << aggressiveCows() << "\n";
	}
	return 0;
}