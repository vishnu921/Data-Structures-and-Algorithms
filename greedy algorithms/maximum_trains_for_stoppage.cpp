/*
We are given n-platform and two main running railway track for both direction. Trains which needs to stop at your station 
must occupy one platform for their stoppage and the trains which need not to stop at your station will run away through either
of main track without stopping. Now, each train has three value first arrival time, second departure time and third required 
platform number. We are given m such trains you have to tell maximum number of train for which you can provide stoppage 
at your station.
*/
#include <bits/stdc++.h>
using namespace std;

int maxstop(int a[][3], int n, int m){
	//for each platform we have a vector that stores pair of start and end time of every train
	vector<pair<int,int>> v[n+1];
	for(int i=0; i < m; i++){
		v[a[i][2]].push_back(make_pair(a[i][1], a[i][0]));
	}

	//sorting every vector based on end time
	for(int i = 1; i <= n; i++){
		sort(v[i].begin(), v[i].end());
	}

	int count = 0;
	//for every platform count maximum train stopped similar to activity selection problem
	for(int i = 1; i <= n; i++){
		if(v[i].size() == 0) continue;

		int last_selected = 0;
		count++;
		//if start time of current train is greater than end time of previously selected train
		//then select the current train and increase count by 1
		for(int j = 1; j < v[i].size(); i++){
			if(v[i][j].second > v[i][last_selected].first){
				last_selected = j;
				count++;
			}
		} 
	}

	return count;
}

int main(){
	//n = number of platforms
	//m = number of trains
	int n,m;
	cin >> n >> m;
	int a[m][3];
	//a[i][0] stores start time
	//a[i][1] stores end time
	//a[i][2] stores platform number
	for(int i = 0; i < m; i++){
		cin >> a[i][0] >> a[i][1] >> a[i][2];
	}
	cout << "Max. train stopped: " << maxstop(a, n, m) << endl;
	return 0;
}