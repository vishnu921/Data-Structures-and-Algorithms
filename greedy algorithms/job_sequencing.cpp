/*
Given a set of N jobs where each job i has a deadline and profit associated to it. Each job takes 1 unit of time to complete and only one job can be scheduled at a time. We earn the profit if and only if the job is completed by its deadline. The task is to find the maximum profit and the number of jobs done.
*/
#include <bits/stdc++.h>
using namespace std;

struct Job{
	int id;
	int dead;
	int profit;
};

bool compare(Job a, Job b){
	return (a.profit > b.profit);
}

vector<int> JobSequencing(Job arr[], int n){
	//sort array based on profit in descending order
	sort(arr, arr+n, compare);
	//maximum time we have
	int t = 0;
	for(int i = 0; i < n; i++){
		t = max(t, arr[i].dead);
	}

	//array to store time slot remaining and job sequence. seq[i] = 0 means time slot is available
	int seq[t+1] = {};
	int count = 0;
	int net_profit = 0;

	for(int i = 0; i < n; i++){
		int d = arr[i].dead;
		while(d > 0){
			if(seq[d] == 0){
				seq[d] = arr[i].id;
				count++;
				net_profit += arr[i].profit;
				break;
			}
			d--;
		}
	}
	return {count, net_profit};
}

int main(){
	int n;
	cin >> n;
	Job arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i].id >> arr[i].dead >> arr[i].profit;
	}
	vector<int> res = JobSequencing(arr, n);
	cout << res[0] << " " << res[1] << endl;
	return 0;
}