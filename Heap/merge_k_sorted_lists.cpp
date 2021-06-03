/* Given K sorted linked lists of different sizes. The task is to merge them in 
such a way that after merging they will be a single sorted linked list. 
*/

#include <bits/stdc++.h>
using namespace std;

class Node{
public:
	int data;
	Node *next;

	Node(int x){
		data = x;
		next = NULL;
	}
};

void printlist(Node *head){
	while(head != NULL){
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

Node* insert(){
	Node *head = NULL;
	Node *tail = NULL;

	while(1){
		int x;
		cin >> x;
		if(x == -1) break;

		Node *cur = new Node(x);

		if(head == NULL){
			head = cur;
			tail = cur;
		}
		else{
			tail->next = cur;
			tail = cur;
		}
	}

	return head;
}


//comparator
struct compare{
	bool operator()(Node *a, Node *b){
		return (a->data > b->data);
	}
};
//merge k sorted list using min heap
Node* mergeKsorted(Node* a[], int k){
	priority_queue<Node*, vector<Node*>, compare> pq;

	for(int i = 0; i < k; i++){
		if(a[i]) pq.push(a[i]);
	}

	Node *head = NULL;
	Node *tail = NULL;
	while(!pq.empty()){
		Node *cur = pq.top();
		pq.pop();

		if(cur->next) pq.push(cur->next);

		if(head == NULL){
			head = cur;
			tail = cur;
		}
		else{
			tail->next = cur;
			tail = cur;
		}
	}

	return head;
}

int main(){
	int k;
	cin >> k;
	Node* a[k];

	for(int i = 0; i < k; i++){
		a[i] = insert();
	}

	Node *head = mergeKsorted(a, k);
	printlist(head);
	return 0;
}