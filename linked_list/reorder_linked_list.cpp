/*
Given a singly linked list: A0→A1→…→An-1→An, reorder it to: A0→An→A1→An-1→A2→An-2→....
For example: Given 1->2->3->4->5 its reorder is 1->5->2->4->3.

Note: It is recommended do this in-place without altering the nodes' values.
*/

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

void insert(int x, node* &head, node* &tail){
	node *temp = new node(x);
	if(head == NULL)
	{
		head = temp;
		tail = temp;
	}

	tail->next = temp;
	tail = temp;
}

void display(node *head){
	node* temp = head;
	while(temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

//function to reverse a linked list
node *reverse(node *head){
    if(head == NULL || head->next == NULL) return head;
    node *cur = head;
    node *prev = NULL;
    node *next;
    
    while(cur != NULL){
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    
    return prev;
}

void reorderList(node* head) {
    node *slow = head;
    node *fast = head;
    
    //we first the n/2th element of the linked list
    while(fast->next != NULL && fast->next->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    
    //then we split the linked list into 2 halves
    //the 2nd half start from next element of n/2th element
    //the 2nd half is then reversed
    node *h2 = slow->next;
    slow->next = NULL;
    
    h2 = reverse(h2);
    node *cur1 = head, *n1;
    node *cur2 = h2, *n2;
    
    //now we merge both linked list into one alternatively
    while(cur1 != NULL && cur2 != NULL){
        n1 = cur1->next;
        n2 = cur2->next;
        cur1->next = cur2;
        cur2->next = n1;
        cur1 = n1;
        cur2 = n2;
    }
    
    //for odd no. of elements one element of 2nd half remains
    //unadded so we add it separately
    if(cur2 != NULL){
        cur1 = head;
        while(cur1->next != NULL){
            cur1 = cur1->next;
        }
        cur1->next = cur2;
    }
}

int main(){
	int n;
	cin >> n;
	node* head = NULL;
	node* tail = NULL;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		insert(x, head, tail);
	}

	reorderList(head);
	display(head);
	return 0;
}