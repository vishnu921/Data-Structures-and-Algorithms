/*
https://www.geeksforgeeks.org/function-to-find-number-of-customers-who-could-not-get-a-computer/
*/

#include <bits/stdc++.h>
using namespace std;
#define max_char 256

int runCustomerSimulation(int n, string s){
	
	//	seen[i] = 0, indicates that customer 'i' is not in cafe
	//	seen[1] = 1, indicates that customer 'i' is in cafe but computer is not assigned yet.
	//	seen[2] = 2, indicates that customer 'i' is in cafe and has occupied a computer.
	int seen[max_char] = {};
	int res = 0, occupied = 0;
	for(int i = 0; i < s.length(); i++){
		if(seen[s[i]] == 0){

			seen[s[i]] = 1;

			if(occupied < n){
				seen[s[i]] = 2;
				occupied++;
			} else{
				seen[s[i]] = 1;
				res++;
			}

		} else{

			if(seen[s[i]] == 2){
				occupied--;
			}
			seen[s[i]] = 0;

		}
	}

	return res;
}

int main(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	cout << runCustomerSimulation(n, s) << "\n";
	return 0;
}