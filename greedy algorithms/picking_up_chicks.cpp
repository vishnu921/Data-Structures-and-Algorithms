/*
A flock of chickens are running east along a straight, narrow road. Each one is running with its own constant speed. 
Whenever a chick catches up to the one in front of it, it has to slow down and follow at the speed of the other chick. 
You are in a mobile crane behind the flock, chasing the chicks towards the barn at the end of the road. The arm of the 
crane allows you to pick up any chick momentarily, let the chick behind it pass underneath and place the picked up chick 
back down. This operation takes no time and can only be performed on a pair of chicks that are immediately next to each 
other, even if 3 or more chicks are in a row, one after the other.

Given the initial locations (Xi) at time 0 and natural speeds (Vi) of the chicks, as well as the location of the 
barn (B), what is the minimum number of swaps you need to perform with your crane in order to have at least K of 
the N chicks arrive at the barn no later than time T?

You may think of the chicks as points moving along a line. Even if 3 or more chicks are at the same location, next 
to each other, picking up one of them will only let one of the other two pass through. Any swap is instantaneous, 
which means that you may perform multiple swaps at the same time, but each one will count as a separate swap.
*/
#include <bits/stdc++.h>
using namespace std;

long long b;


template <typename T>
void printcase(T c,int f){
	cout << "Case #" << f << ": " << c << "\n";
}


int main(){
	int c;
	cin >> c;
	for(int f = 1; f <= c; f++){
		int n,k,t;
		b = 0;
		cin >> n >> k >> b >> t;
		long long x[n],v[n];
		for(int i = 0; i < n; i++){
			cin >> x[i];
		}

		//count of chickens finishing the race on time
		int count = 0;
		//boolean array to check if ith chicken will be able to finish race on time t
		bool isfast[n];

		for(int i = 0; i < n; i++){
			cin >> v[i];
			if((x[i]+v[i]*t) >= b){
				count++;
				isfast[i] = true;
			}
			else{
				isfast[i] = false;
			}
		}
		
		//if number of chickens finishing the race is less than k return impossible
		if(count < k){
			printcase("IMPOSSIBLE",f);
			continue;
		}
		
		//we traverse from right to left
		//if we encounter a finisher increase count and swaps if we previously encountered slow chicks
		//if we found a slow chicken, we have to swap it with all the upcoming finishers so increase the price by 1
		//if finishers == k break
		int price = 0;
		int swaps = 0;
		count = 0;
		for(int i = n-1; i >= 0; i--){
			if(isfast[i]){
				count++;
				swaps += price;
			}
			else{
				price++;
			}
			if(count == k) break;
		}
		
		printcase(swaps,f);
	}
	return 0;
}