#include <bits/stdc++.h>
using namespace std;

class Node{
public:
	int data;
	Node* next;

	Node(int x)
	{
		data = x;
		next = NULL;
	}
};
Node* tail = NULL;

void insert(int data)
{
	Node *temp = new Node(data);

	if(tail == NULL)
	{
		tail = temp;
		temp->next = tail;
		return;
	}

	temp->next = tail->next;
	tail->next = temp;
	tail = temp;
}

void deleteBeg()
{
	if(tail == NULL)
	{
		cout << "UNDERFLOW\n";
		return;
	}

	Node* temp = tail->next;

	if(temp == tail)        //if only one node is present
	{
		tail = NULL;
		delete temp;
		return;
	}

	tail->next = temp->next;             //make last node point to second node to maintain cycle
	delete temp;
	temp = NULL;
}

void deleteLast()
{
	if(tail == NULL)
	{
		cout << "UNDERFLOW\n";
		return;
	}

	Node* ptr = tail->next;

	if(ptr == tail)                   //if only one node is present
	{
		tail == NULL;
		delete ptr;
		return;
	}

	while(ptr->next != tail)           //after the loop ptr points to second last node
	{
		ptr = ptr->next;
	}

	ptr->next = tail->next;           //make second last node's next point to first node
	delete tail;				
	tail = ptr;						//update tail to point the new last node
}

void delete_nth(int pos)
{
	if(pos == 1)
	{
		deleteBeg();
		return;
	}

	Node* ptr = tail->next;
	while(pos > 2 && ptr != tail)
	{
		ptr = ptr->next;
		pos--;
	}

	if(ptr == tail)
	{
		cout << "!! Invalid position !!";
		return;
	}

	Node *temp = ptr->next;                //temp points to the node to be deleted 
	ptr->next = temp->next;                //link of (n-1)th node now points to (n+1)th node
	if(temp == tail) tail = ptr;			//if the node to be deleted is last node then update the tail pointer
	delete temp;
}

void display()
{
	cout << "Updated list: ";
	Node *temp = tail->next;
	do{
		cout << temp->data << " ";
		temp = temp->next;
	}while(temp != tail->next);
	cout << endl;
}

int main()
{
	int n,x;
	do{
		cout << "1: Insert  2: Delete at head  3: Delete at Tail  4: Delete at nth   5: Exit\n";
		cout << "choose: ";
		cin >> n;
		if(n == 5) break;
		switch(n)
		{
			case 1:
			{
				cout << "Enter value to insert: ";
				cin >> x;
				insert(x);
				display();
				break;
			}
			case 2:
			{
				deleteBeg();
				display();
				break;
			}
			case 3:
			{
				deleteLast();
				display();
				break;
			}
			case 4:
			{
				cout << "Enter position: ";
				cin >> x;
				delete_nth(x);
				display();
				break;
			}
		}
	}while(1);
	return 0;
}