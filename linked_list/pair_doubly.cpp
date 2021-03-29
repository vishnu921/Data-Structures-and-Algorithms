//find pair with sum k in sorted array
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

void find_pair(node *first, node *last, int k)
{
	bool found = false;
	while(first != NULL && last != NULL && first != last && last->next != first)
	{
		if(first->data + last->data == k)
		{
			found = true;
			cout << "found: " << first->data << " " << last->data << endl;
			first = first->next;
			last = last->prev;
		}
		else if(first->data + last->data < k)
		{
			first = first->next;
		}
		else last = last->prev;
	}

	if(found == false) cout << "NOT FOUND\n";
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

	cout << "Enter sum: ";
	cin >> x;

	find_pair(head, tail, x);
	return 0;
}