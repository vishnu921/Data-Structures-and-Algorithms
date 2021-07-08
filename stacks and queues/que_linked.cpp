#include <bits/stdc++.h>
using namespace std;

class node{
public:
	int data;
	node *next;

	node(int x)
	{
		data = x;
		next = NULL;
	}
};


class Que{
	node *front, *rear;
public:
	Que(){
		front = NULL;
		rear = NULL;
	}

	void enque(int x){
		node *temp = new node(x);

		if(front == NULL)
		{
			front = temp;
			rear = temp;
			return;
		}

		rear->next = temp;
		rear = temp;
	}

	void dequeue(){
		if(front == NULL)
		{
			cout << "UNderflow\n";
			return;
		}
		node *temp = front;
		front = front->next;

		if(front == NULL){
			rear = NULL;
		}
		delete temp;
	}

	bool isempty(){
		return (front == NULL);
	}

	void display(){
		node *temp = front;
		cout << "Queue: ";

		if(front == NULL)
		{
			cout << "Empty Queue\n";
			return;
		}
		
		while(temp != NULL)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}
};

int main(){
	int n,x;
	Que q;
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