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

void insert(int x, node *&head, node *&tail){
    node *temp = new node(x);
    if(head == NULL){
        head = temp;
        tail = temp;
        return;
    }
    tail->next = temp;
    tail = temp;
}

node* addTwoLists(node* first, node* second)
{
    first = reverse(first);
    second = reverse(second);
    
    node *head = NULL, *tail = NULL;
    int carry = 0;
    
    while(first != NULL || second != NULL){
        int f = (first==NULL) ? 0:first->data;
        int s = (second==NULL) ? 0:second->data;
        
        int sum = f + s + carry;
        
        carry = (sum>=10) ? 1:0;
        sum = sum%10;
        
        insert(sum, head, tail);
        if(first) first = first->next;
        if(second) second = second->next;
    }
    
    if(carry){
        insert(carry, head, tail);
    }
    
    return reverse(head);
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

	node *ans = addTwoLists(first, second);

	cout << "sum :";
	display(ans);
	return 0;
}