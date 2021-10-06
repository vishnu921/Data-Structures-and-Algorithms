/*
https://www.spoj.com/problems/PRATA/
*/

#include <bits/stdc++.h>
using namespace std;

bool isPossible(int rank[], int p, int n, int time){
	int cur_Prata = 0;
	for(int i = 0; i < n; i++){
		int t = 0, j = 1;
		while(1){
			t += rank[i]*j;
			j++;
			if(t > time) break;
			cur_Prata++;
		}
	}

	return (cur_Prata >= p);
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int p,n;
		cin >> p >> n;
		int rank[n];
		for(int i = 0; i < n; i++){
			cin >> rank[i];
		}
		sort(rank, rank+n);

		int l = 0, h = rank[0]*(p*(p+1)/2);
		int res = h;
		while(l <= h){
			int mid = l + (h-l)/2;
			if(isPossible(rank, p, n, mid)){
				res = mid;
				h = mid-1;
			} else{
				l = mid+1;
			}
		}

		cout << res << "\n";
	}
	return 0;
}