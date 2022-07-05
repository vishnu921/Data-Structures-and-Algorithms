//split circular linked list into 2 halves
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

void insert(int x)
{
	node *temp = new node(x);

	if(head == NULL)
	{
		head = temp;
		tail = temp;
		temp->next = head;
		return;
	}

	tail->next = temp;
	tail = temp;
	temp->next = head;
}

void display(node *head)
{
	if(head == NULL) return;
	node *temp = head;
	do{
		cout << temp->data << " ";
		temp = temp->next;
	}while(temp != head);
	cout << "\n";
}

void splithalves(node **head1_ref, node **head2_ref) {
	if(head == NULL) return;
	
	node *slow = head, *fast = head;
    
    while(fast->next!=head && fast->next->next!=head){
        slow = slow->next;
        fast = fast->next->next;
    }
    
    if(fast->next->next == head){
        fast = fast->next;
    }
    
    *head1_ref = head;
    *head2_ref = slow->next;
    slow->next = head;
    fast->next = *head2_ref;
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

	node *first = NULL;
	node *second = NULL;

	splithalves(&first, &second);

	cout << "first: ";
	display(first);
	cout << "second: ";
	display(second);
	return 0;
}