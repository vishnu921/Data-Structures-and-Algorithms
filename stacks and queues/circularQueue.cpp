#include <bits/stdc++.h>
using namespace std;

class CircularQueue{
	int *arr;
	int front, rear, size;
public:
	CircularQueue(int n){
		front = -1;
		rear = -1;
		arr = new int[n];
		size = n;
	}

	bool isfull(){
		if((rear+1)%size == front) return true;
		return false;
	}

	bool isempty(){
		if(front == -1 && rear == -1) return true;
		return false;
	}

	void enqueue(int x){
		if(isfull()){
			cout << "Full queue\n";
			return;
		}

		if(isempty()){
			rear = 0;
			front = 0;
			arr[rear] = x;
		}
		else{
			rear = (rear+1)%size;
			arr[rear] = x;
		}
	}

	int dequeue(){
		if(isempty()){
			cout << "Empty queue\n";
			return -1;
		}
		int x = arr[front];
		if(front == rear){
			front = -1;
			rear = -1;
		}
		else{
			front = (front+1)%size;
		}
		return x;
	}

	void display(){
		if(isempty()){
			cout << "Empty queue\n";
			return;
		}

		for(int i = front; i != rear; i = (i+1)%size)
			cout << arr[i] << " ";
		cout << arr[rear] << endl;
	}
};

int main(){
	int n,x;
	cin >> n;
	CircularQueue que(n);
	do{
		cout << "1.Enqueue  2.Dequeue  3.Exit\n";
		cout << "Enter choice: ";
		cin >> n;
		switch(n){
			case 1:{
				cout << "Enter element: ";
				cin >> x;
				que.enqueue(x);
				que.display();
				break;
			}
			case 2:{
				que.dequeue();
				que.display();
				break;
			}
		}
	}while(n != 3);
	return 0;
}