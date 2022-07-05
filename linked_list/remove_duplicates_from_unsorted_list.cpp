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

node * removeDuplicates(node *head) 
{
    unordered_set<int> ss;
    
    node *cur = head, *prev = NULL;
    
    while(cur != NULL){
        if(ss.find(cur->data) != ss.end()){
            prev->next = cur->next;
            delete cur;
            
        } else{
            ss.insert(cur->data);
            prev = cur;
            
        }
        
        cur = prev->next;
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