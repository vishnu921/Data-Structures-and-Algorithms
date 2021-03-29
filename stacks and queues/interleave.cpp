/*
Given a queue of integers of even length, rearrange the elements by interleaving the first half of the queue with the second half of the queue.
*/
#include <bits/stdc++.h>
using namespace std;


void display(queue<int> q){
	if(q.empty()) return;
	while(!q.empty()){
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl;
}

void interleaveQueue(queue<int> &q){
	if(q.size()%2 != 0) return;
	stack<int> s;
	int n = q.size();

	for(int i = 0; i < n/2; i++)
	{
		s.push(q.front());
		q.pop();
	}
	
	while(!s.empty()){
		q.push(s.top());
		s.pop();
	}
	
	for(int i = 0; i < n/2; i++)
	{
		q.push(q.front());
		q.pop();
	}
	
	for(int i = 0; i < n/2; i++){
		s.push(q.front());
		q.pop();
	}
	
	while(!s.empty()){
		q.push(s.top());
		s.pop();
		q.push(q.front());
		q.pop();
	}
}

int main(){
	int n,x;
	cin >> n;
	queue<int> q;
	for(int i = 0; i < n; i++){
		cin >> x;
		q.push(x);
	}
	interleaveQueue(q);
	display(q);
}