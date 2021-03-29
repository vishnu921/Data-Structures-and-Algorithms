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


node *reverse(node *head)
{
	node *prev = NULL;
	node *current = head;
	node *next;

	while(current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	return prev;
}


void display(node *p)
{
	while(p != NULL)
	{
		cout << p->data;
		p = p->next;
	}
	cout << "\n";
}

node *addTwoNumber(node *first, node *second)
{
	first = reverse(first);
	second = reverse(second);

	node *res = NULL;
	node *prev = NULL;
	node *temp = NULL;

	int sum = 0, carry = 0;
	while(first != NULL || second != NULL)
	{
		sum = carry + (first ? first->data : 0) + (second ? second->data : 0);

		carry = ((sum >= 10) ? 1 : 0);

		sum = sum%10;

		temp = new node(sum);

		if(res == NULL)
		{
			res = temp;
		}
		else 
		{
			prev->next = temp;
		}

		prev = temp;
		if(first) first = first->next;
		if(second) second = second->next;
	}

	if(carry)
	{
		temp->next = new node(carry);
	}

	res = reverse(res);

	return res;
}

int main()
{
	int n, m;
	cout << "Enter no. of digits in first number: ";
	cin >> n;
	node *first = buildLinkedlist(n);
	cout << "Enter no. of digits in second number: ";
	cin >> m;
	node *second = buildLinkedlist(m);
	cout << "first number: ";
	display(first);
	cout << "second number: ";
	display(second);

	node *ans = addTwoNumber(first, second);

	cout << "sum :";
	display(ans);
	return 0;
}