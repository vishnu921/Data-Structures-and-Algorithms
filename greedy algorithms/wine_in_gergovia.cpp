/*
Gergovia consists of one street, and every inhabitant of the city is a wine salesman. Everyone buys wine from other 
inhabitants of the city. Every day each inhabitant decides how much wine he wants to buy or sell. Interestingly, demand 
and supply is always the same, so that each inhabitant gets what he wants.

There is one problem, however: Transporting wine from one house to another results in work. Since all wines are equally 
good, the inhabitants of Gergovia don't care which persons they are doing trade with, they are only interested in selling 
or buying a specific amount of wine.

In this problem you are asked to reconstruct the trading during one day in Gergovia. For simplicity we will assume 
that the houses are built along a straight line with equal distance between adjacent houses. Transporting one bottle 
of wine from one house to an adjacent house results in one unit of work.
*/
#include <bits/stdc++.h>
using namespace std;

//Greedy solution
int minimum_work1(int a[], int n){
	int work = 0;
	//true for buy and false for sell
	for(int i = 0; i < n-1; i++){
		work += abs(a[i]);
		a[i+1] += a[i];
	}
	return work;
}

//o(n^2) solution
// int minimum_work(int a[], int n){
// 	int work = 0; 
// 	int i = 0; 
// 	while(i < n){
// 		while(a[i] <= 0){
// 			i++;
// 		}
// 		int closest = 0;
// 		int diff = INT_MAX;
// 		for(int j = 0; j < n; j++){
// 			if(a[j] < 0 && abs(i-j) < diff){
// 				diff = abs(i-j);
// 				closest = j;
// 			}
// 		}

// 		if(a[i] >= a[closest]*(-1)){
// 			a[i] = a[i]+a[closest];
// 			work += abs(i-closest)*a[closest]*(-1);
// 			a[closest] = 0;
// 		}
// 		else{
// 			work += abs(i-closest)*a[i];
// 			a[closest] = a[closest]+a[i];
// 			a[i] = 0;
// 		}
// 	}
// 	return work;
// }

int main(){
	int n;
	while(1){
		cin >> n;
		if(n == 0) break;
		int a[n];
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		cout << minimum_work1(a, n) << endl;
	}
	return 0;
}