/*
Suppose there is a circle. There are N petrol pumps on that circle. You will be given two sets of data.
1. The amount of petrol that every petrol pump has.
2. Distance from that petrol pump to the next petrol pump.
Find a starting point where the truck can start to get through the complete circle without exhausting its petrol in between.
Note :  Assume for 1 litre petrol, the truck can go 1 unit of distance.
*/
#include <bits/stdc++.h>
using namespace std;

class PetrolPump{
public:
	int petrol;
	int distance;
};
/*
in this approach we use queue DS. We enqueue first petrol pump into the queue.
now we keep on enqueing petrolpumps until either tour is completed or cur becomes negetive
if cur becomes negetive we keep on dequeuing petrolpumps until the queue becomes empty or cur >= 0
if start == 0 that means we are starting again at index 0 hence return -1
at last return start
*/
int tour_usingQue(PetrolPump p[], int n){
	int start = 0;
	int end = 1;
	int cur = p[start].petrol - p[start].distance;

	while(start != end || cur < 0){
		while(cur < 0 && start != end){
			cur -= p[start].petrol - p[start].distance;
			start = (start+1)%n;

			if(start == 0) return -1;
		}

		cur += p[end].petrol - p[end].distance;
		end = (end+1)%n;
	}
	return start;
}

int tour_usingDef(PetrolPump p[], int n){
	int start = 0, balance = 0;
	int deficit = 0;
	for(int i = 0; i < n; i++)
	{
		balance += p[i].petrol - p[i].distance;
		if(balance < 0){
			start = i+1;
			deficit += balance;
			balance = 0;
		}
	}
	if(balance+deficit >= 0) return start;
	return -1;
}

int main(){
	int n;
	cin >> n;
	PetrolPump p[n];
	for(int i = 0; i < n; i++)
	{
		cin >> p[i].petrol >> p[i].distance;
	}
	cout << tour_usingQue(p, n) << endl;
	cout << tour_usingDef(p, n) << endl;
	return 0;
}