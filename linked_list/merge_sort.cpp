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

node *sortedMerge(node *a, node *b)
{
	if(a == NULL) return b;
	if(b == NULL) return a;

	node *res = NULL;

	if(a->data <= b->data)
	{
		res = a;
		res->next = sortedMerge(a->next, b);
	}
	else 
	{
		res = b;
		res->next = sortedMerge(a, b->next);
	}
	return res;
}

void merge_sort(node **head_ref)
{
	node *head = *head_ref;
	if(head == NULL || head->next == NULL) return;
	node *slow = *head_ref;
	node *fast = (*head_ref)->next;

	while(fast != NULL)
	{
		fast = fast->next;
		if(fast != NULL)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}

	node *left = *head_ref;
	node *right = slow->next;
	slow->next = NULL;

	merge_sort(&left);
	merge_sort(&right);

	*head_ref = sortedMerge(left, right);
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

	merge_sort(&head);
	cout << "sorted linked list: ";
	display(head);
	return 0;
}