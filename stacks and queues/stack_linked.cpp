// implementing stack using linked list
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

class Stack
{
	node *top;

public:
	Stack(){ top = NULL; }
	// ~Stack()
	// {
	// 	node *temp;
	// 	while(top != NULL)
	// 	{
	// 		temp = top;
	// 		top = top->next;
	// 		delete temp;
	// 		temp = NULL;
	// 	}
	// }

	void push(int x)
	{
		node *temp = new node(x);
		if(top == NULL)
		{
			top = temp;
			return;
		}

		temp->next = top;
		top = temp;
	}

	int Top()
	{
		return top->data;
	}

	void pop()
	{
		if(top == NULL) return;
		node *temp = top;
		top = top->next;
		delete temp;
		temp = NULL;
	}

	bool empty()
	{
		return (top == NULL);
	}

	void display()
	{
		node *temp = top;
		while(temp != NULL)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}
};

int main()
{
	int n,x;
	cin >> n;
	Stack s;
	for(int i = 0; i < n; i++)
	{
		cin >> x;
		s.push(x);
	}
	cout << "stack: ";
	s.display();
	
	cout << "unstacking elements in stack: ";
	while(!s.empty())
	{
		cout << s.Top() << " ";
		s.pop();
	}
	cout << endl;
	if(s.empty())
	{
		cout << "empty stack\n";
	}
	else{
		cout << "stack is not empty\n";
	}
	return 0;
}