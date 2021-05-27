/*
Ishika got stuck on an island. There is only one shop on this island and it is open on all days of the week except 
for Sunday. Consider following constraints:

    N – The maximum unit of food you can buy each day.
    S – Number of days you are required to survive.
    M – Unit of food required each day to survive.

Currently, it’s Monday, and she needs to survive for the next S days.
Find the minimum number of days on which you need to buy food from the shop so that she can survive the next S days,
 or determine that it isn’t possible to survive. 
*/
#include <bits/stdc++.h>
using namespace std;

int isPossibleToSurvive(int s, int n, int m){
	// m*s = total required food to survive s days
	//min_days = minimum days required to purchase m*s unit of food
	int min_days = (m*s)/n;
	if((m*s)%n != 0) min_days++;

	//if min_days is less than or equal to the available days of purchase return it
	if(min_days <= (s-s/7)){
		return min_days;
	}
	//else return -1
	return -1;
}

int main(){
	int s,n,m;
	cin >> s >> n >> m;
	cout << isPossibleToSurvive(s, n, m) << endl;
	return 0;
}