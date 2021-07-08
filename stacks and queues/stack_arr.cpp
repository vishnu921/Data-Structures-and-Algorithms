//implementation of stack using arrays
#include <bits/stdc++.h>
using namespace std;

class Stack{
	int *arr;
	int top;
	int capacity;

public:
	// ~Stack()
	// {
	// 	cout << "destructor called\n";
	// 	delete[] arr;
	// }
	Stack(int n)
	{
		top = -1;
		arr = new int[n];
		capacity = n;
	}

	void push(int x)
	{
		if(top == capacity-1)
		{
			cout << "stack overflow!!\n";
			return;
		}
		top++;
		arr[top] = x;
	}

	int Top()
	{
		if(top != -1) return arr[top];
		return -1;
	}

	int size()
	{
		return top+1;
	}
	void pop()
	{
		if(top == -1)
		{
			cout << "underflow!!\n";
			return;
		}
		top--;
	}

	bool empty()
	{
		if(top == -1) return true;
		return false;
	}

	void display()
	{
		for(int i = top; i >= 0; i--)
		{
			cout << arr[i] << " ";
		}
		cout << "\n";
	}
};

int main()
{
	int n,x;
	cin >> n;
	Stack s(n);
	for(int i = 0; i < n; i++)
	{
		cin >> x;
		s.push(x);
	}
	
	cout << "stack: ";
	s.display();

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