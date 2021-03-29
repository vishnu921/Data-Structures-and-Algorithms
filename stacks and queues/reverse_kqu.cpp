/*
Given an integer K and a queue of integers, we need to reverse the order of the first K elements of the queue, leaving the other elements in the same relative order.
*/
#include <bits/stdc++.h>
using namespace std;

void display(queue<int> q){
	if(q.empty()){
		cout << "Empty queue\n";
		return;
	}
	cout << "Updated queue: ";
	while(!q.empty()){
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl;
}


void reverse_firstk(queue<int> &q, int k){
	if(q.empty() || k > q.size()) return;
	stack<int> s;
	int n = q.size();
	for(int i = 0; i < k; i++)
	{
		s.push(q.front());
		q.pop();
	}

	while(!s.empty()){
		q.push(s.top());
		s.pop();
	}

	for(int i = 0; i < (n-k); i++){
		q.push(q.front());
		q.pop();
	}
}


int main(){
	int n,x;
	cin >> n;
	queue<int> q;
	for(int i = 0; i < n; i++)
	{
		cin >> x;
		q.push(x);
	}
	cout << "Enter k: ";
	cin >> x;
	reverse_firstk(q, x);
	display(q);
	return 0;
}