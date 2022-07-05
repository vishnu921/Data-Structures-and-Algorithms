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
		return;
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

node *removeDuplicates(node *head)
{
    node *cur = head;

    while(cur != NULL){
        int val = cur->data;
        node *ptr = cur->next;
        
        while(ptr != NULL && ptr->data == val){
            node *temp = ptr->next;
            delete ptr;
            ptr = temp;
        }
        
        cur->next = ptr;
        cur = cur->next;
    }
    
    return head;
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

	head = removeDuplicates(head);
	display(head);
	return 0;
}