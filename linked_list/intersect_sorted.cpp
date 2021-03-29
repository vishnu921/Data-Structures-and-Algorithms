//find intersections of two sorted linked lists

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


node *findintersection(node *first, node *second)
{
	node *res = NULL;
	node *temp, *prev = NULL;

	while(first != NULL && second != NULL)
	{
		//cout << "first->data = " << first->data << " compared to second->data = " << second->data << endl;
		if(first->data == second->data)
		{
			temp = new node(first->data);

			if(res == NULL) res = temp;
			else prev->next = temp;
			prev = temp;
			first = first->next;
			second = second->next;
		}
		else if(first->data < second->data)
		{
			first = first->next;
		}
		else
		{
			second = second->next;
		}
	}
	return res;
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
	int n, m;
	cout << "Enter no. of nodes in first: ";
	cin >> n;
	node *first = buildLinkedlist(n);
	
	cout << "Enter no. of nodes in second: ";
	cin >> m;
	node *second = buildLinkedlist(m);
	cout << "first list: ";
	display(first);
	cout << "second list: ";
	display(second);
	
	node *ans = findintersection(first, second);

	cout << "intersection :";
	display(ans);
	return 0;
}