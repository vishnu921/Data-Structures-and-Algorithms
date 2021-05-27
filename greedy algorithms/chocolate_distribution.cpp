/*
Given an array A[ ] of positive integers of size N, where each value represents the number of chocolates in a packet. 
Each packet can have a variable number of chocolates. There are M students, the task is to distribute chocolate packets 
among M students such that :
1. Each student gets exactly one packet.
2. The difference between maximum number of chocolates given to a student and minimum number of chocolates given to a 
   student is minimum.
*/
#include <bits/stdc++.h>
using namespace std;

int chocolatesDistribution(int a[], int n, int m){
	//first sort the array
	sort(a, a+n);
	//now use window technique to find the subarray of size m with minimum difference
	int mn = a[m-1]-a[0];
	for(int i = m; i < n; i++){
		mn = min(mn, a[i]-a[i-m+1]);
	}
	return mn;
}

int main(){
	//n = no. of packets
	//m = no. of students
	int n,m;
	cin >> n >> m;

	//a[i] stores number of chocolate in ith packet
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	cout << chocolatesDistribution(a, n, m) << endl;
	return 0;
}