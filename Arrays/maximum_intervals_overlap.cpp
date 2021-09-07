/*
Consider a big party where N guests came to it and a log register for guest’s entry and exit times was 
maintained. Find the minimum time at which there were maximum guests at the party. Note that entries in 
the register are not in any order.

Example 1:
Input:  N = 5
		Entry= {1, 2,10, 5, 5}
		Exit = {4, 5, 12, 9, 12}
Output: 3 5
Explanation: At time 5 there were 
             guest number 2, 4 and 5 present.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> MaximumOverlaps(int Entry[], int Exit[], int n){
	//first we sort both arrays individually
	sort(Entry, Entry+n);
	sort(Exit, Exit+n);

	//guest_in stores number of guest present at current time
	//max_guests stores all time maximum guests at a time
	//inTime stores minimum time when max_guests are present
	int guest_in = 1, max_guests = 1, inTime = Entry[0];
	int i = 1, j = 0;

	while(i < n && j < n){
		if(Entry[i] <= Exit[j]){
			//if a guest has entered without someone exiting
			guest_in++;

			//update max_guests and inTime
			if(guest_in > max_guests){
				max_guests = guest_in;
				inTime = Entry[i];
			}

			i++;
		} else{
			//else a guest has exitted 
			guest_in--;
			j++;
		}
	}

	return {max_guests, inTime};
}

int main(){
	int n;
	cin >> n;
	int Entry[n], Exit[n];
	for(int i = 0; i < n; i++) cin >> Entry[i];
	for(int i = 0; i < n; i++) cin >> Exit[i];

	vector<int> res = MaximumOverlaps(Entry, Exit, n);
	cout << res[0] << " " << res[1] << "\n";
	return 0;
}