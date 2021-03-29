#include <bits/stdc++.h>
using namespace std;

class node{
public:
	int data;
	node* next;

	node(int x)
	{
		data = x;
		next = NULL;
	}
};
node* head = NULL;
node* tail = NULL;

void insert(int x){
	node *temp = new node(x);
	if(head == NULL)
	{
		head = temp;
		tail = temp;
	}

	tail->next = temp;
	tail = temp;
}

void reverse_iterative()
{
	node *prev = NULL;
	node *current = head;
	node *next = NULL;

	while(current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}

	head = prev;
}

void reverse_recursively(node *p)
{
	if(p == NULL || p->next == NULL)
	{
		head = p;
		return;
	}

	reverse_recursively(p->next);
	p->next->next = p;
	p->next = NULL;
}

void display()
{
	node* temp = head;
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
	cout << "Enter n: ";
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> x;
		insert(x);
	}

	reverse_recursively(head);
	cout << "After recursion: ";
	display();
	return 0;
}