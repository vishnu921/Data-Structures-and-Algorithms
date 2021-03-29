//check if a linked list is palindrome or not
#include <bits/stdc++.h>
using namespace std;

class node{
public:
	int data;
	node *next;

	node(int x)
	{
		data = x;
		next = NULL;
	}
};
node *head = NULL;
node *tail = NULL;

void display(node *p)
{
	while(p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

void insert(int x)
{
	node *temp = new node(x);
	if(head == NULL)
	{
		head = temp;
		tail = temp;
		return;
	}

	tail->next = temp;
	tail = temp;
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
bool ispalindrome(node *head)
{
	if(head == NULL || head->next == NULL) return true;

	node *slow = head;
	node *fast = head;
	node *prev = NULL, *second = NULL, *first = NULL;

	while(fast != NULL && fast->next != NULL)
	{
		fast = fast->next->next;
		prev = slow;
		slow = slow->next;
	}

	if(fast != NULL)
	{
		slow = slow->next;
	}

	first = head;
	second = slow;
	prev->next = NULL;
	second = reverse(second);

	while(first != NULL && second != NULL)
	{
		if(first->data != second->data) 
			{
				return false;
			}
		first = first->next;
		second = second->next;
	}

	if(first == NULL && second == NULL) return true;
	return false;
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

	if(ispalindrome(head))
	{
		cout << "The list is palindrome\n";
	}
	else
	{
		cout << "The list is not palindrome\n";
	}
	return 0;
}