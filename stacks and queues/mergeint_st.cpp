//we have done merge intervals using arrays now do it using stack
#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> merge_intervals(vector<pair<int,int>> v,int n)
{
	stack<pair<int, int>> s;
	sort(v.begin(), v.end());
	s.push(v[0]);
	for(int i = 1; i < n; i++)
	{
		pair<int, int> p = s.top();
		if(p.second < v[i].first)
		{
			s.push(v[i]);
		}
		else if(p.second < v[i].second){
			p.second = v[i].second;
			s.pop();
			s.push(p);
		}
	}
	vector<pair<int, int>> res;
	while(!s.empty())
	{
		res.push_back(s.top());
		s.pop();
	}
	sort(res.begin(), res.end());
	return res;
}

int main()
{
	int n,x,y;
	cin >> n;
	vector<pair<int, int>> v;
	for(int i = 0; i < n; i++)
	{
		cin >> x >> y;
		v.push_back(make_pair(x, y));
	}
	vector<pair<int,int>> res;
	res = merge_intervals(v, n);
	for(int i = 0; i < res.size(); i++)
	{
		cout << res[i].first << " " << res[i].second << " ";
	}
	cout << endl;
	return 0;
}