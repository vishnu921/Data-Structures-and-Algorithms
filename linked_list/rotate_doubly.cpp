//rotate a doubly linked list in anti-clockwise n times;
#include <bits/stdc++.h>
using namespace std;

class node{
public:
	int data;
	node *prev;
	node *next;

	node(int x)
	{
		data = x;
		prev = NULL;
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
		return;
	}

	temp->prev = tail;
	tail->next = temp;
	tail = temp;
}

void rotate_nodes(int p)
{
	if(p == 0) return;

	node *last = head;
	node *ptr = head;

	while(last->next != NULL)
	{
		last = last->next;
	}

	while(p > 0 && ptr != NULL)
	{
		ptr = ptr->next;
		p--;
	}

	if(ptr == NULL) return;

	head->prev = last;
	last->next = head;

	ptr->prev->next = NULL;
	ptr->prev = NULL;

	head = ptr;
}

void display(node *head)
{
	while(head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
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
	cout << "Enter number of nodes to be rotated: ";
	cin >> x;

	rotate_nodes(x);
	cout << "Updated list: ";
	display(head);
	return 0;
}