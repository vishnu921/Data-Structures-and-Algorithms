#include <bits/stdc++.h>
using namespace std;

int main()
{
	priority_queue <int, vector<int>, greater<int>> pq;
	int n,k;
	cin >> n >> k;
	for(int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		pq.push(x);
	}
	while(k > 1)
	{
		pq.pop();
		k--;
	}
	cout << "kth smallest number in array : " << pq.top() << endl;
	/* code */
	return 0;
}