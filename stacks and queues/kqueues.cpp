//implement k queues in a single array
#include <bits/stdc++.h>
using namespace std;


/*to create this data structure we use 4 arrays 
arr[] to store the actual elements of the k queues
front[] to store the front of every queue
rear[] to store the rear of every queue
next[] to store the next index of all the items in the arr[] 
the free variable stores the beginning of the empty list(where new items can be inserted)
*/
class kqueues{
	int *arr;
	int *front;
	int *rear;
	int *next;
	int n, k, free;
public:
	kqueues(int n1, int k1){
		n = n1; k = k1;
		arr = new int[n];
		next = new int[n];
		rear = new int[k];
		front = new int[k];
		free = 0;

		for(int i = 0; i < k; i++)
		{
			front[i] = -1;
		}

		for(int i = 0; i < n-1; i++)
			next[i] = i+1;
		next[n-1] = -1;
	}

	bool isfull(){ return (free == -1); }

	bool isempty(int qn){ return (front[qn] == -1); }

	void enqueue(int x, int qn){
		if(isfull()){
			cout << "Queue is full\n";
			return;
		}
		int i = free;                // i is the index where the new item is to be enqueued
		free = next[i];              //update the free variable to next free slot in the empty list
		if(isempty(qn))
			front[qn] = i;          
		else
			next[rear[qn]] = i;       //next[] entry of the last element of queue numbered qn will be ith index

		next[i] = -1;               //next[] entry of the last element of the queue is always -1
		rear[qn] = i;                 //update the rear of the queue to i
		arr[i] = x;                     //store the value at ith index
	}

	int dequeue(int qn){
		if(isempty(qn)){
			cout << "Queue is empty\n";
			return -1;
		}
		int i = front[qn];                  //i is the index that is to dequeued
		front[qn] = next[i];                 //update the front[qn] to the next[] entry of the dequeued item(ith)
		next[i] = free;                     //now that i is to be dequeued hence its next entry will be free
		free = i;				            // and the new free slot is the ith index
		return arr[i];
	}

	void display(int qn){
		if(isempty(qn)){
			cout << "Empty queue\n";
			return;
		}
		int i = front[qn];
		while(i != -1){
			cout << arr[i] << " ";
			i = next[i];
		}
		cout << endl;
	}
};

int main()
{
	int n,k,x;
	cin >> n >> k;
	kqueues q(n, k);
	do{
		cout << "1.Enqueue 2.Dequeue 3.Exit\n";
		cout << "Enter choice: ";
		cin >> n;
		switch(n){
			case 1:{
				cout << "Enter item: ";
				cin >> x;
				cout << "Enter queue no.: ";
				cin >> k;
				q.enqueue(x, k);
				q.display(k);
				break;
			}
			case 2:{
				cout << "Enter queue no.: ";
				cin >> k;
				cout << "Popped: " << q.dequeue(k) << endl;
				q.display(k);
				break;
			}
		}
	}while(n != 3);
	return 0;
}