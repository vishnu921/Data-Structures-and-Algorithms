#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>> intervals, int n)
{
	if(n == 0) return intervals;
	vector<vector<int>> res;
	sort(intervals.begin(), intervals.end());
	vector<int> temp = intervals[0];
	for(auto it: intervals)
	{
		if(it[0] <= temp[1])
		{
			temp[1] = max(it[1], temp[1]);
		}
		else
		{
			res.push_back(temp);
			temp = it;
		}
	}
	res.push_back(temp);
	return res;
}

int main()
{
	int n;
	cin >> n;
	vector<vector<int>> intervals;
	for(int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		intervals.push_back({x, y});
	}
	vector<vector<int>> ans;
	ans = merge(intervals, n);
	for(int i = 0; i < ans.size(); i++)
	{
		cout << ans[i][0] << "  " << ans[i][1] << endl;
	}
	return 0;
}