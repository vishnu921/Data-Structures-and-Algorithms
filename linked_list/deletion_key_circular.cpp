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
node *head = NULL;
node *tail = NULL;

void insert(int x)
{
	node *temp = new node(x);

	if(head == NULL)
	{
		head = temp;
		tail = temp;
		temp->next = head;
		return;
	}

	tail->next = temp;
	tail = temp;
	temp->next = head;
}

void delete_circular(int key)
{
	if(head == NULL) return;
	if(head->data == key && head->next == head)
	{
		delete head;
		head = NULL;
		return;
	}

	node *last = head;

	if(head->data == key)
	{
		while(last->next != head)
		{
			last = last->next;
		}

		last->next = head->next;
		delete head;
		head = last->next;
		return;
	}

	while(last->next != head && last->next->data != key)
	{
		last = last->next;
	}

	if(last->next->data == key)
	{
		node *temp = last->next;
		last->next = temp->next;
		delete temp;
	}
	else 
	{
		cout << "NO SUCH Node exists\n";
	}


}

void display(node *head)
{
	if(head == NULL) return;
	node *temp = head;
	do{
		cout << temp->data << " ";
		temp = temp->next;
	}while(temp != head);
	cout << "\n";
}


int main()
{
	int n,x;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> x;
		insert(x);
	}

	cout << "Enter node to be deleted: ";
	cin >> x;
	delete_circular(x);

	cout << "Updated list: ";
	display(head);
	return 0;
}