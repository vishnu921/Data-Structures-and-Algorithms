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
	if(!head) return true;
        
    node *slow = head, *fast = head->next;
    while(fast!=NULL && fast->next!=NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    
    slow->next = reverse(slow->next);
    
    node *p1 = head,*p2 = slow->next;
    
    while(p1 && p2){
        if(p1->data != p2->data){
            slow->next = reverse(slow->next);
            return false;
        }
        p1 = p1->next;
        p2 = p2->next;
    }
    
    slow->next = reverse(slow->next);
    return true;
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