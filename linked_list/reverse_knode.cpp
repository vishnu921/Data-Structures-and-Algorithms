//Given a linked list of size N. The task is to reverse every k nodes 
//(where k is an input to the function) in the linked list.

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

void display(node *head)
{
	node* temp = head;
	while(temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}


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

node *reverse_knodes(node *head, int k)
{
	node* prev = NULL;
	node* current  = head;
	node* next = NULL;
	int count = 0;
	// cout << "Passed linked list: ";
	// display(head);
	while(current != NULL && count < k)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
		count++;
	}

	if(next != NULL)
	{
		head->next = reverse_knodes(next, k);
	}

	return prev;
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
	int k;
	cout << "Enter k: ";
	cin >> k;
	head =  reverse_knodes(head,k);
	cout << "After recursion: ";
	display(head);
	return 0;
}