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

void insert(int data)
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

void deleteBeg()
{
	if(head == NULL) return;       //underflow

	Node* temp = head;
	head = temp->next;
	if(head != NULL) head->prev = NULL;       //if it contains more than one elements
	delete temp;
}

void deleteLast()
{
	if(head == NULL) return;     //underflow

	if(head->next == NULL)    // if list contains only one element
	{
		delete head;
		head = NULL;
		return;
	}

	Node* temp = head;
	while(temp->next->next != NULL)    //temp points to second last node
	{
		temp = temp->next;
	}

	Node* last = temp->next;
	temp->next = NULL;
	delete last;
}

void delete_nth(int pos)
{
	if(head == NULL) return;   //underflow

	if(pos == 1) 
	{
		deleteBeg();
		return;
	}

	Node *temp = head;

	while(pos > 1 && temp != NULL)               //after the loop temp points to nth node that is to be deleted
	{
		temp = temp->next;
		pos--;
	}

	if(temp == NULL) return;             //invalid position

	if(temp->next == NULL)               //if last element is to be deleted 
	{
		deleteLast();
		return;
	}

	temp->next->prev = temp->prev; 
	temp->prev->next = temp->next;

	delete temp;
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