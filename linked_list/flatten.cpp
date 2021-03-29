/*
Given a Linked List of size N, where every node represents a sub-linked-list and contains two pointers:
(i) a next pointer to the next node,
(ii) a bottom pointer to a linked list where this node is head.
Each of the sub-linked-list is in sorted order.
Flatten the Link List such that all the nodes appear in a single level while maintaining the sorted order.
*/

#include <bits/stdc++.h>
using namespace std;

class node{
public:
	int data;
	node *next;
	node *bottom;

	node(int x)
	{
		data = x;
		next = NULL;
		bottom = NULL;
	}
};


void display(node *head)
{
	while(head != NULL)
	{
		cout << head->data << " ";
		head = head->bottom;
	}
	cout << endl;
}

node *merge(node *a, node *b)
{
	if(a == NULL) return b;
	if(b == NULL) return a;

	node *res = NULL;
	if(a->data < b->data)
	{
		res = a;
		res->bottom = merge(a->bottom, b);
	}
	else{
		res = b;
		res->bottom = merge(a, b->bottom);
	}
	return res;
}

node *flatten(node *root)
{
	if(root == NULL || root->next == NULL) return root;

	root->next = flatten(root->next);

	root = merge(root, root->next);

	return root;
}

int main()
{
	int n,m,flag = 1, flag1 = 1;
	node *temp = NULL;
	node *head = NULL;
	node *pre = NULL;
	node *tempb = NULL;
	node *preb = NULL;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	for(int i = 0; i < n; i++)
	{
		m = a[i];
		m--;
		int x;
		cin >> x;
		temp = new node(x);
		if(flag)
		{
			head = temp;
			pre = temp;
			flag = 0;
			flag1 = 1;
		}
		else
		{
			pre->next = temp;
			pre = temp;
			flag1 = 1;
		}
		for(int j = 0; j < m; j++)
		{
			cin >> x;
			tempb = new node(x);
			if(flag1)
			{
				temp->bottom = tempb;
				preb = tempb;
				flag1 = 0;
			}
			else
			{
				preb->bottom = tempb;
				preb = tempb;
			}
		}
	}
	
	node *res = flatten(head);

	display(res);
	return 0;
}