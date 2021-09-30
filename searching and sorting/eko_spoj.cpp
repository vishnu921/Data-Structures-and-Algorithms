/*
 Lumberjack Mirko needs to chop down M metres of wood. It is an easy job for him since he has a nifty new 
 woodcutting machine that can take down forests like wildfire. However, Mirko is only allowed to cut a single row of trees.

Mirko‟s machine works as follows: Mirko sets a height parameter H (in metres), and the machine raises a giant 
sawblade to that height and cuts off all tree parts higher than H (of course, trees not higher than H meters remain intact). 
Mirko then takes the parts that were cut off. For example, if the tree row contains trees with heights of 20, 15, 10, and 
17 metres, and Mirko raises his sawblade to 15 metres, the remaining tree heights after cutting will be 15, 15, 10, and 
15 metres, respectively, while Mirko will take 5 metres off the first tree and 2 metres off the fourth tree (7 metres of 
wood in total).

Mirko is ecologically minded, so he doesn‟t want to cut off more wood than necessary. That‟s why he wants to set his 
sawblade as high as possible. Help Mirko find the maximum integer height of the sawblade that still allows him to cut 
off at least M metres of wood.
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool isPossible(ll height[], ll n, ll m, ll cur_height){
	ll wood = 0;
	for(ll i = 0; i < n; i++){
		if(height[i] > cur_height){
			wood += height[i] - cur_height;
		}

		if(wood >= m){
			return true;
		}
	}

	return false;
}
int main(){
	ll n,m;
	cin >> n >> m;
	ll height[n];
	ll mx = 0;
	for(ll i = 0; i < n; i++){
		cin >> height[i];
		mx = max(mx, height[i]);
	}

	ll res = 0;
	ll l = 0, h = mx;
	while(l <= h){
		ll mid = (l+h) >> 1;
		if(isPossible(height, n, m, mid)){
			res = mid;
			l = mid+1;
		}else{
			h = mid-1;
		}
	}

	cout << res << "\n";
	return 0;
}