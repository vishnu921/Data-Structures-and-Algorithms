#include <bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node *next;
};
node *head = NULL;


// Function to get new node
node* GetnewNode(int x)
{
	node *nnode = new node();
	nnode->data = x;
	nnode->next = NULL;
	return nnode;
}

//Function to insert node 
void insert(int x)
{
	node *temp = GetnewNode(x);
	if(head == NULL)
	{
		head = temp;
		return;
	}
	node *ptr = head;
	while(ptr->next != NULL)
	{
		ptr = ptr->next;
	}
	ptr->next = temp;
}

//Function to delete first node
void delete_first()
{
	if(head == NULL) return;
	node *temp = head;
	head = head->next;
	delete temp;
}

//Function to delete last node
void delete_last()
{
	if(head == NULL)
	{
		return;
	}
	node *temp = head;
	if(head->next == NULL)
	{
		head = NULL;
		delete temp;
		return;
	}
	while(temp->next->next != NULL)
	{
		temp = temp->next;
	}
	delete temp->next;
	temp->next = NULL;
}

void delete_nth(int pos)
{
	node *temp = head;
	if(pos == 1)
	{
		delete_first();
		return;
	}
	for(int i = 0; i < pos-2 && temp != NULL; i++)
	{
		temp = temp->next;
	}

	if(temp == NULL || temp->next == NULL)
	{
		cout << " !!! INVALID POSITION !!! \n";
		return;
	}

	node *temp1 = temp->next;
	temp->next = temp1->next;
	delete temp1;
}

void display()
{
	cout << "Updated list: ";
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
				delete_first();
				display();
				break;
			}
			case 3:
			{
				delete_last();
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