//Given a doubly linked list containing n nodes. The problem is to reverse every group of k nodes in the list
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

node *getnode(int x)
{
	node *temp = new node(x);
	return temp;
}

void insert(node **headref, node *nnode)
{
	nnode->prev = NULL;
	nnode->next = (*headref);
	if((*headref) != NULL)
		(*headref)->prev = nnode;
	(*headref) = nnode;
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


node *reverse_kgroup(node *head, int k)
{
	node *current = head;
	node *next;
	node *newhead = NULL;
	int count = 0;

	while(current != NULL && count < k)
	{
		next = current->next;
		insert(&newhead, current);
		current = next;
		count++;
	}

	if(next != NULL)
	{
		head->next = reverse_kgroup(next, k);
		head->next->prev = head;
	}
	return newhead;

}


int main()
{
	node *head = NULL;
	int n,x;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> x;
		insert(&head, getnode(x));
	}
	cout << "Enter k: ";
	cin >> x;
	cout << "original list: ";
	display(head);

	head = reverse_kgroup(head, x);

	cout <<"Updated list: ";
	display(head);
	return 0;
}

