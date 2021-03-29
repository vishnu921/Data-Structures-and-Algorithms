//implement queue using 2 stacks
#include <bits/stdc++.h>
using namespace std;

class StackQueue{
	stack<int> s1;
	stack<int> s2;

public:
	void push(int x){
		s1.push(x);
	}

	int pop(){
		if(s1.empty() && s2.empty()) return -1;
		int x = -1;
		if(s2.empty())
		{
			while(!s1.empty())
			{
				x = s1.top();
				s1.pop();
				s2.push(x);
			}
		}

		x = s2.top();
		s2.pop();
		return x;
	}
};

int main(){
	int n,q,x;
	cin >> n;
	StackQueue *qs = new StackQueue();
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