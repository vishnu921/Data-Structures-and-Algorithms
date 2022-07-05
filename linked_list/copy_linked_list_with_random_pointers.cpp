//https://leetcode.com/problems/copy-list-with-random-pointer/

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node* copyRandomList(Node* head) {

	if(!head) return NULL;

	Node *cur = head;

	//Adding copy of nodes adjacent to te originals
	while(cur != NULL){
	    Node *t = new Node(cur->val);
	    t->next = cur->next;
	    cur->next = t;
	    cur = t->next;
	}

	cur = head;
	Node *copy = head->next;

	// Setting the random pointers of the duplicate list 
	//with the help of the fact that original_node->next is the copy of it
	while(cur != NULL){
	    if(cur->random != NULL){
	        cur->next->random = cur->random->next;
	    }
	    
	    cur = cur->next->next;
	}

	cur = head;
	// recover the original list and extract duplicate
	while(cur != NULL){
	    head = cur->next->next;
	    
	    if(head != NULL){
	        cur->next->next = head->next;
	    } 
	    
	    cur->next = head;
	    cur = head;
	}
    
    return copy;
}

void display(Node *head){
	while(head){
		cout << head->val << " ";
		head = head->next;
	}

	cout << "\n";
}

int main(){
	int n;
	cin >> n;
	vector<Node*> v(n, new Node(INT_MAX));
	for(int i = 0; i < n; i++){
		int x, y;
		cin >> x >> y;

		v[i]->val = x;
		v[i]->next = v[i+1];
		if(y != -1) v[i]->random = v[y];
	}

	Node *head = v[0];
	display(head);
	Node *copy = copyRandomList(head);
	cout << "Original: ";
	display(head);
	cout << "Copy List: ";
	display(copy);
	return 0;
}