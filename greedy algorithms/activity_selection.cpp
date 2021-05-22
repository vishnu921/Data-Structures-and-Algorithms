/*
Given N activities with their start and finish time given in array start[ ] and end[ ]. Select the maximum number of activities that can be performed by a single person, assuming that a person can only work on a single activity at a given day.
*/
#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int,int> a, pair<int,int> b){
	return (a.second < b.second);
}

int activitySelection(vector<pair<int,int>> arr, int n){
	//sort arr based on end time in ascending order;
	sort(arr.begin(), arr.end(), compare);

	//select the activity that is finished first and set the count to 1
	int count = 1;
	int last = arr[0].second;

	//check for every activity if its start time is greater than finish time of last selected activity
	//if yes then select the activity and increment the count
	for(int i = 1; i < n; i++){
		if(arr[i].first >= last){
			last = arr[i].second;
			count++;
		}
	}
	return count;
}

int main(){
	//vector to store start and end time of n activity
	vector<pair<int,int>> arr;
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		int start, end;
		cin >> start >> end;
		arr.push_back(make_pair(start, end));
	}

	cout << activitySelection(arr, n) << endl;
	return 0;
}