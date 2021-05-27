/*
In a stock market, there is a product with its infinite stocks. The stock prices are given for N days,
 where arr[i] denotes the price of the stock on the ith day. There is a rule that a customer can buy at 
 most i stock on the ith day. If the customer has an amount of k amount of money initially, find out the 
 maximum number of stocks a customer can buy.
*/
#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int,int> a, pair<int,int> b){
	return (a.first*b.second < b.first*a.second);
}

int maximumStocks(int a[], int n, int k){
	//first stores stock price and second stores day number
	vector<pair<int,int>> v;
	for(int i = 0; i < n; i++){
		v.push_back(make_pair(a[i], i+1));
	}
	//sort according the price/(maximum stock we can buy on that day) ratio in ascending order
	sort(v.begin(), v.end(), compare);
	
	int result = 0;
	for(int i = 0; i < n; i++){
		if(k <= 0) break;
		//if we can buy all the stock on the current day we buy them
		if(k/v[i].first >= v[i].second){
			result += v[i].second;
			k -= v[i].first*v[i].second;
		}
		//else buy stocks as much money is remaining
		else{
			result += k/v[i].first;
			k -= v[i].second*(k/v[i].first);
		}
	}

	return result;
}

int main(){
	int n,k;
	cin >> n >> k;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	cout << maximumStocks(a, n, k) << endl;
	return 0;
}