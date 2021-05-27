/*
Theodore implements a new strategy game “Defense of a Kingdom”. On each level a player defends the Kingdom that is
 represented by a rectangular grid of cells. The player builds crossbow towers in some cells of the grid. The tower 
 defends all the cells in the same row and the same column. No two towers share a row or a column.

The penalty of the position is the number of cells in the largest undefended rectangle. For example, the position 
shown on the picture has penalty 12.

This position has a penalty of 12.
*/
#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int,int> a, pair<int,int> b){
	return (a.second < b.second);
}

int solve(int w, int h, int n, vector<pair<int,int>> v){
	if(n == 0) return w*h;
	if(n == min(w,h)) return 0;
	sort(v.begin(), v.end());
	int mx = v[0].first-1;
	for(int i = 1; i < n; i++){
		mx = max(mx, v[i].first-v[i-1].first-1);
	}
	mx = max(mx,w - v[n-1].first);
	
	sort(v.begin(), v.end(), compare);
	int my = v[0].second-1;
	for(int i = 1; i < n; i++){
		my = max(my, v[i].second-v[i-1].second-1);
	}
	my = max(my, h-v[n-1].second);
	
	return mx*my;
}

int main() {
	int t;
	cin >> t;
	while(t--){
		int n,w,h;
		cin >> w >> h >> n;
		vector<pair<int,int>> v;
		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			v.push_back(make_pair(x,y));
		}
		cout << solve(w,h,n,v) << endl;
	}
	// your code goes here
	return 0;
}