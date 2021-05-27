/*
 We are given a bar of chocolate composed of m*n square pieces. One should break the chocolate into single squares. 
 Parts of the chocolate may be broken along the vertical and horizontal lines as indicated by the broken lines in the picture.

A single break of a part of the chocolate along a chosen vertical or horizontal line divides that part into two smaller 
ones. Each break of a part of the chocolate is charged a cost expressed by a positive integer. This cost does not depend 
on the size of the part that is being broken but only depends on the line the break goes along. Let us denote the costs 
of breaking along consecutive vertical lines with x1, x2, ..., xm-1 and along horizontal lines with y1, y2, ..., yn-1.

The cost of breaking the whole bar into single squares is the sum of the successive breaks. One should compute the 
minimal cost of breaking the whole chocolate into single squares. 
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int m,n;
		cin >> m >> n;
		priority_queue<pair<int,char>> pq;
		for(int i = 1; i < m; i++){
			int x;
			cin >> x;
			pq.push(make_pair(x, 'h'));
		}
		for(int i = 1; i < n; i++){
			int y;
			cin >> y;
			pq.push(make_pair(y, 'v'));
		}

		//to get the minimum cost take the cut which have maximum cost first
		long long ans = 0;
		int hcut = 0;
		int vcut = 0;
		while(!pq.empty()){
			pair<int,char> cur = pq.top();
			pq.pop();
			if(cur.second == 'h'){
				ans += cur.first*(vcut+1);
				hcut++;
			}
			else{
				ans += cur.first*(hcut+1);
				vcut++;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}