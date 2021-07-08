#include <bits/stdc++.h>
using namespace std;

class Que{
	int front, rear;
	int size;
	int *arr;

public:
	Que(int n){
		front = -1;
		rear = -1;
		size = n;
		arr = new int[size];
	}

	void enque(int x)
	{
		if(rear == -1)
		{
			front = 0;
			rear = 0;
			arr[rear] = x;
		}
		else if(rear == size-1)
		{
			cout << "overflow!!\n";
		}
		else{
			rear++;
			arr[rear] = x;
		}
	}

	void dequeue(){
		if(front == -1)
		{
			cout << "UNDERFLOW!!\n";
			return;
		}

		if(front == rear)
		{
			front = -1;
			rear = -1;
			return;
		}

		front++;
	}

	int Front(){
		if(front != -1) return arr[front];
		return -1;
	}

	int Rear(){
		if(rear != -1 && rear < size) return arr[rear];
		return -1;
	}

	bool isempty()
	{
		return front == -1;
	}

	void display()
	{
		cout << "Queue: ";
		if(front == -1 || front > rear)
		{
			cout << "Empty queue\n";
			return;
		}

		for(int i = front; i <= rear; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}
};

int main()
{
	int n,x;
	cin >> n;
	Que q(n);
	do{
		cout << "1. Enqueue 2. Dequeue 3. IsEmpty 4. Show  5.Exit\n";
		cout << "Enter choice: ";
		cin >> n;
		switch(n)
		{
			case 1:{
				cout << "Enter : ";
				cin >> x;
				q.enque(x);
				q.display();
				break;
			}
			case 2:{
				q.dequeue();
				q.display();
				break;
			}
			case 3:{
				if(q.isempty())
				{
					cout << "Queue is empty\n";
				}
				else{
					cout << "Not empty\n";
				}
				break;
			}
			case 4:{
				q.display();
				break;
			}
		}
	}while(n != 5);
	return 0;
}