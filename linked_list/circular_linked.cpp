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

void addToEmpty(int data)
{
	Node* temp = new Node(data);

	tail = temp;
	temp->next = tail;
}

void insertAtBeg(int data)
{
	if(tail == NULL)
	{
		addToEmpty(data);
		return;
	}

	Node* temp = new Node(data);
	temp->next = tail->next;
	tail->next = temp;
}

void insertAtEnd(int data)
{
	if(tail == NULL)
	{
		addToEmpty(data);
		return;
	}
	Node* temp = new Node(data);
	temp->next = tail->next;
	tail->next = temp;
	tail = temp;
}

void insertAtnth(int data, int pos)
{
	if(pos == 1)
	{
		insertAtBeg(data);
		return;
	}
	Node *ptr = tail->next;             //ptr points to first node;
	while(pos > 2 && ptr != tail)
	{
		ptr = ptr->next;
		pos--;
	}

	if(pos > 2)
	{
		cout << "!! invalid position !!\n";
		return;
	}

	if(ptr == tail)
	{
		insertAtEnd(data);
		return;
	}

	Node* temp = new Node(data);
	temp->next = ptr->next;
	ptr->next = temp;
}

void display()
{
	cout << "Updated list: ";
	Node* temp = tail->next;
	do
	{
		cout << temp->data << " ";
		temp = temp->next;
	}while(temp != tail->next);

	cout << endl;
}

int main()
{int n,x;
	do{
		cout << "1: insert at head  2: insert at Tail  3: insert at nth   4: Exit\n";
		cout << "choose: ";
		cin >> n;
		if(n == 4) break;
		cout << "Enter value to insert: ";
		switch(n)
		{
			case 1:
			{
				cin >> x;
				insertAtBeg(x);
				display();
				break;
			}
			case 2:
			{
				cin >> x;
				insertAtEnd(x);
				display();
				break;
			}
			case 3:
			{
				cin >> x;
				cout << "Insert position: ";
				int pos;
				cin >> pos;
				insertAtnth(x, pos);
				display();
				break;
			}
		}
	}while(1);
	return 0;
}