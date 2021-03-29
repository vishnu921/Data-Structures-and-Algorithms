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

void make_cycle(int pos)
{
	node *temp = head;
	node *start = head;

	int count = 1;
	while(temp->next != NULL)
	{
		if(count == pos)
		{
			start = temp;
		}
		temp = temp->next;
		count++;
	}

	temp->next = start;
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

bool detect_loop()
{
	node* slow = head;
	node* fast = head;

	while(fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;

		if(slow == fast) return true;
	}
	return false;
}


void delete_loop()           //this function is called when we know that there is a loop present
{
	node *slow = head;
	node *fast = head;

	do{
		slow = slow->next;
		fast = fast->next->next;
	}while(slow != fast);

	slow = head;

	if(slow == fast)                      //if cycle is at head node slow and fast will always meet at head node
	{
		while(fast->next != slow)           //traverse till last element
		{
			fast = fast->next;
		}
	}
	else
	{
		while(slow->next != fast->next)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}

	fast->next = NULL;        //break the cycle
	
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

	make_cycle(4);

	if(detect_loop())
	{
		delete_loop();
	}
	else cout << "NO cycle present to delete\n";

	display(head);
	return 0;
}