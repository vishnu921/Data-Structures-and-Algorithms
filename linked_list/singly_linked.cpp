#include <bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node *next;
};
node *head = NULL;

node* GetnewNode(int x)
{
	node *nnode = new node();
	nnode->data = x;
	nnode->next = NULL;
	return nnode;
}

void insertAtHead(int x)
{
	node *temp = GetnewNode(x);
	temp->next = head;
	head = temp;
	return;
}

void insertAtTail(int x)
{
	node *temp = GetnewNode(x);
	if(head == NULL)
	{
		insertAtHead(x);
		return;
	}
	node *ptr = head;
	while(ptr->next != NULL)
	{
		ptr = ptr->next;
	}
	ptr->next = temp;
}

void insertAtNth(int x, int n)
{
	node *temp = GetnewNode(x);
	if(n == 1)
	{
		insertAtHead(x);
		return;
	}
	node *ptr = head;
	for(int i = 0; i < n-2 && ptr != NULL; i++)
	{
		ptr = ptr->next;
	}
	if(ptr == NULL)
	{
		cout << "!!! INVALID position !!!\n";
		return;
	}
	temp->next = ptr->next;
	ptr->next = temp;
}

void display()
{
	cout << "Updated list : ";
	node *temp = head;
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
				insertAtHead(x);
				display();
				break;
			}
			case 2:
			{
				cin >> x;
				insertAtTail(x);
				display();
				break;
			}
			case 3:
			{
				cin >> x;
				cout << "Insert position: ";
				int pos;
				cin >> pos;
				insertAtNth(x, pos);
				display();
				break;
			}
		}
	}while(1);
	return 0;
}