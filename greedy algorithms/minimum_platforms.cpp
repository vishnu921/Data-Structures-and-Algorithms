/*
Given arrival and departure times of all trains that reach a railway station. Find the minimum number of platforms required 
for the railway station so that no train is kept waiting.
Consider that all the trains arrive on the same day and leave on the same day. Arrival and departure time can never be the 
same for a train but we can have arrival time of one train equal to departure time of the other. At any given instance of 
time, same platform can not be used for both departure of a train and arrival of another train. In such cases, we need 
different platforms.

Approach: The idea is to consider all events in sorted order. Once the events are in sorted order, trace the 
number of trains at any time keeping track of trains that have arrived, but not departed.

For example consider the above example.

arr[]  = {9:00,  9:40, 9:50,  11:00, 15:00, 18:00}
dep[]  = {9:10, 12:00, 11:20, 11:30, 19:00, 20:00}

All events are sorted by time.
Total platforms at any time can be obtained by
subtracting total departures from total arrivals
by that time.

 Time      Event Type     Total Platforms Needed 
                               at this Time                               
 9:00       Arrival                  1
 9:10       Departure                0
 9:40       Arrival                  1
 9:50       Arrival                  2
 11:00      Arrival                  3 
 11:20      Departure                2
 11:30      Departure                1
 12:00      Departure                0
 15:00      Arrival                  1
 18:00      Arrival                  2 
 19:00      Departure                1
 20:00      Departure                0

Minimum Platforms needed on railway station 
= Maximum platforms needed at any time 
= 3  
*/
#include <bits/stdc++.h>
using namespace std;

int findplatform(int arr[], int dep[], int n){
	//sorting the events
	sort(arr, arr+n);
	sort(dep, dep+n);
	//plat_needed stores required platforms at a time
	int plat_needed = 1, result = 1;
	int i = 1, j = 0;
	while(i < n && j < n){
		//if a new train is arriving before departure
		//that means we need one more platform
		if(arr[i] <= dep[j]){
			plat_needed++;
			i++;
		}
		//if a train has departed then we do not require
		//its platform anymore hence decrease plat_needed
		else if(arr[i] > dep[j]){
			plat_needed--;
			j++;
		}
		//minimum platform needed = maximum train at a time
		result = max(result,plat_needed);
	}
	return result;
}

int main(){
	int n;
	cin >> n;
	int arr[n],dep[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i] >> dep[i];
	}
	cout << findplatform(arr,dep,n) << endl;
	return 0;
}