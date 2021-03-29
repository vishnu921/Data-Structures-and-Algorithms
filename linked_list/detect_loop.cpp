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

	//make_cycle(4);

	if(detect_loop())
	{
		cout << "loop present\n";
	}
	else cout << "loop is not present\n";
	return 0;
}