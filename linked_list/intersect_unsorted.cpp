//find intersections of two unsorted linked lists

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

node *buildLinkedlist(int n)
{
	if(n == 0) return NULL;
	int x;
	cout << "Enter space separated digits: ";
	cin >> x;
	node *head = new node(x);
	node *tail = head;
	for(int i = 0; i < n-1; i++)
	{
		cin >> x;
		tail->next = new node(x);
		tail = tail->next;
	}

	return head;
}

int Get_length(node *head)
{
	int len = 0;
	while(head != NULL)
	{
		head = head->next;
		len++;
	}
	return len;
}


int findintersection(node *first, node *second, int n, int m)
{
	int d = n-m;

	node *p1 = first;
	//Now we traverse d times in the longer linked list
	// to reach the particular node of longer linked list from where 
	//the distance to common node is equal to the distance 
	//between first node of shorted list and the common node
	while(p1 != NULL && d > 0)
	{
		p1 = p1->next;
		d--;
	}

	if(p1 == NULL) return -1;

	node *p2 = second;
	while(p1 != NULL && p2 != NULL)
	{
		if(p1 == p2) return p1->data;

		p1 = p1->next;
		p2 = p2->next;
	}

	return -1;
}


void display(node *p)
{
	while(p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << "\n";
}

int main()
{
	int n, m, k;
	cout << "Enter no. of nodes in first: ";
	cin >> n;
	node *first = buildLinkedlist(n);
	
	cout << "Enter no. of nodes in second: ";
	cin >> m;
	node *second = buildLinkedlist(m);

	cout << "Enter no of nodes in common: ";
	cin >> k;
	node *common = buildLinkedlist(k);

	node *temp = first;
	while(temp != NULL && temp->next != NULL)
	{
		temp = temp->next;
	}
	if(temp != NULL) temp->next = common;

	temp = second;
	while(temp != NULL && temp->next != NULL)
	{
		temp = temp->next;
	}
	if(temp != NULL) temp->next = common;

	cout << "first list: ";
	display(first);
	cout << "second list: ";
	display(second);
	
	n = Get_length(first);
	m = Get_length(second);

	cout << "common linked list starts at : ";
	if(n >= m)
	{
		cout << findintersection(first, second, n, m) << endl;
	}
	else
	{
		cout << findintersection(second, first, m, n) << endl;
	}
	return 0;
}