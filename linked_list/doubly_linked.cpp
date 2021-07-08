#include <bits/stdc++.h>
using namespace std;

class Node{
public:
	int data;
	Node* prev;
	Node* next;

	Node(int x)
	{
		data = x;
		prev = NULL;
		next = NULL;
	}
};
Node *head = NULL;

void insertAtBeg(int data)
{
	Node* temp = new Node(data);
	if(head == NULL)
	{
		head = temp;
		return;
	}
	temp->next = head;
	head->prev = temp;
	head = temp;
}

void insertAtEnd(int data)
{
	Node* temp = new Node(data);
	if(head == NULL)
	{
		head = temp;
		return;
	}
	Node* ptr = head;
	while(ptr->next != NULL)
	{
		ptr = ptr->next;
	}
	temp->prev = ptr;
	ptr->next = temp;
}

void insertAtnth(int data, int pos)
{
	if(pos == 1)
	{
		insertAtBeg(data);
		return;
	}

	Node *ptr = head;
	while(pos > 2 && ptr != NULL)
	{
		ptr = ptr->next;
		pos--;
	}

	if(ptr == NULL) return;

	Node* temp = new Node(data);

	if(ptr->next == NULL)
	{
		ptr->next = temp;
		temp->prev = ptr;
		return;
	}

	temp->prev = ptr;
	temp->next = ptr->next;

	ptr->next->prev = temp;
	ptr->next = temp;
}

void display()
{
	cout << "Updated list: ";
	Node* temp = head;
	while(temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

int main()
{
	int n,x;
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