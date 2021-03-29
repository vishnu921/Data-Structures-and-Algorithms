//delete duplicates from a sorted linked list
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


//this function removes duplicates from a sorted array
void delete_duplicates()
{
	node *temp = head;
	node *p = head;

	while(p != NULL && p->next != NULL)
	{
		if(p->data == p->next->data)
		{
			temp = p->next;
			p->next = p->next->next;
			delete temp;
			continue;
		}
		p = p->next;
	}
}


//this function removes duplicats from a unsorted array
void delete_duplicates_unsorted()
{
	if(head == NULL || head->next == NULL)
	{
		return;
	}

	node *current = head;
	node *prev = NULL;

	unordered_set<int> s;

	while(current != NULL)
	{
		int x = current->data;
		if(s.find(x) != s.end())
		{
			prev->next = current->next;
			delete current;
		}
		else
		{
			s.insert(x);
			prev = current;
		}

		current = prev->next;
	}
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
	int n,x;
	cout << "Enter n: ";
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> x;
		insert(x);
	}

	delete_duplicates();
	display(head);
	return 0;
}