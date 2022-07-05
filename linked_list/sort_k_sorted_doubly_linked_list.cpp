#include <bits/stdc++.h>
using namespace std;

class Node{
public:
	int data;
	Node *prev, *next;

	Node(int x){
		data = x;
		prev = NULL;
		next = NULL;
	}
};

void insert(int x, Node *&head, Node *&tail){
	Node *temp = new Node(x);

	if(head == NULL){
		head = temp;
		tail = temp;

	} else{
		temp->prev = tail;
		tail->next = temp;
		tail = temp;
	}
}

void display(Node *head){

	while(head){
		cout << head->data << " ";
		head = head->next;
	}
	cout << "\n";
}

struct compare{
	bool operator()(Node *p1, Node *p2){
		return  p1->data > p2->data;
	}
};

Node *sortKSortedDLL(Node *head, int k){

	if(!head) return head;

	priority_queue<Node*, vector<Node*>, compare> pq;

	Node *newHead = NULL, *last;

	for(int i = 0; head!= NULL && i <= k; i++){
		pq.push(head);
		head = head->next;
	}

	while(!pq.empty()){

		if(newHead == NULL){

			newHead = pq.top();
			newHead->prev = NULL;

			last = newHead;

		} else{

			pq.top()->prev = last;
			last->next = pq.top();
			last = pq.top();
		}

		pq.pop();

		if(head != NULL){
			pq.push(head);

			head = head->next;
		}
	}

	last->next = NULL;

	return newHead;
}

int main(){
	int n,k;
	cin >> n >> k;

	Node *head = NULL, *tail;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		insert(x, head, tail);
	}

	head = sortKSortedDLL(head, k);

	display(head);
	return 0;
}