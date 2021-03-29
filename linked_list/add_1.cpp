//add 1 to a number represented by linked list
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

node *add_1_to(node *head)
{
	head = reverse(head);

	int carry = 1, sum = 0;
	node *res = head;
	node *temp, *prev = NULL;

	while(head != NULL)
	{
		sum = carry + head->data;

		carry = (sum >= 10) ? 1:0;

		sum = sum%10;

		head->data = sum;

		temp = head;
		head = head->next;
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
	cout << "Enter no. of digits: ";
	cin >> n;
	node *num = buildLinkedlist(n);
	cout << "Number is: ";
	display(num);

	node *ans = add_1_to(num);

	cout << "Answer :";
	display(ans);
	return 0;
}