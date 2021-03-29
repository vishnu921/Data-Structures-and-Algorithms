//implement stack using 2 queues
#include <bits/stdc++.h>
using namespace std;

class Queuestack{
	queue<int> q1;
	queue<int> q2;

public:
	void push(int x)
	{
		q1.push(x);
	}
	int pop(){
		if(q1.empty()) return -1;

		while(q1.size() != 1){
			q2.push(q1.front());
			q1.pop();
		}

		int x = q1.front();
		q1.pop();

		queue<int> q = q1;
		q1 = q2;
		q2 = q;
		return x;
	}
};

int main(){
	int n,q,x;
	cin >> n;
	Queuestack *qs = new Queuestack();
	while(n--)
	{
		cin >> q;
		if(q == 1){
			cin >> x;
			qs->push(x);
		}
		else{
			cout << qs->pop() << " ";
		}
	}
	cout << endl;
	return 0;
}