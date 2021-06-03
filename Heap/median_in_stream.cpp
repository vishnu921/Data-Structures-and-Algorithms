/*
Given an input stream of N integers. The task is to insert these numbers into a new stream and find the 
median of the stream formed by each insertion of X to the new stream.
*/
#include <bits/stdc++.h>
using namespace std;

//max heap to store left half of the sorted stream
//max.top() = largest element in left half
priority_queue<int> mx;
//min heap to store right half of the sorted stream
//min.top() = smallest element in the right half
priority_queue<int, vector<int>, greater<int>> mn;
double median = 0;


//we have to make sure that sizes of both heaps should not differ by more than 1
void insert(int x){
	//if both heaps are empty store first element in max heap
	if(mx.empty() && mn.empty()){
		mx.push(x);
		median = x;
		return;
	}

	if(mx.size() == mn.size()){
		//if x < median that means x should be in left half
		if(x <= median){
			mx.push(x);
			median = mx.top();
		}
		else{
			mn.push(x);
			median = mn.top();
		}
		return;
	}

	if(mx.size() > mn.size()){
		//if x < median push the top element of maxheap to minheap
		//and then push x to maxheap
		if(x < median){
			mn.push(mx.top());
			mx.pop();
			mx.push(x);
		}
		else mn.push(x);
	}
	else{
		//if x > median push the top element of minheap to maxheap
		//then push x to minheap
		if(x > median){
			mx.push(mn.top());
			mn.pop();
			mn.push(x);
		}
		else mx.push(x);
	}

	median = (mx.top()+mn.top())/2.0;
}

double findMedian(){
	return median;
}

int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		insert(x);
		cout << "Median: " << findMedian() << "\n";
	}
	return 0;
}