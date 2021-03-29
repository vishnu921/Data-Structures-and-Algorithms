//implementation of 2 stacks in an array
#include <bits/stdc++.h>
using namespace std;

class TwoStacks{
	int *arr;
	int top1, top2, size;
public:
	TwoStacks(int n=100){
		top1 = -1;
		size = n;
		top2 = size;
		arr = new int[n];
	}

	void push1(int x)
	{
		if(top1 == size/2) return;      //for a space efficiency we can also write if(top1 >= top2-1)
		top1++;
		arr[top1] = x;
	}

	void push2(int x)
	{
		if(top2 == size/2+1) return;     //same we can also write if(top1 >= top2-1)
		top2--;
		arr[top2] = x;
	}

	int pop1(){
		if(top1 == -1) return -1;
		int x = arr[top1];
		top1--;
		return x;
	}

	int pop2(){
		if(top2 == size) return -1;
		int x = arr[top2];
		top2++;
		return x;
	}

	void display1(){
		cout << "STACK1 : ";
		if(top1 == -1) cout << "Empty stack\n";
		for(int i = 0; i <= top1; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}

	void display2(){
		cout << "STACK2: ";
		if(top2 == size) cout << "Empty stack\n";
		for(int i = size-1; i >= top2; i--)
		{
			cout << arr[top2] << " ";
		}
		cout << endl;
	}
};

int main()
{
	int n,x;
	cin >> n;
	TwoStacks s(n); 
	do{
		cout << "1. Push1 2. Push2 3. Pop1 4. Pop2 5. show1 6. show2 7. Exit\n";
		cout << "Enter choice: ";
		cin >> n;
		switch(n){
			case 1:{
				cout << "Enter element: ";
				cin >> x;
				s.push1(x);
				s.display1();
				break;
			}
			case 2:{
				cout << "Enter element: ";
				cin >> x;
				s.push2(x);
				s.display2();
				break;
			}
			case 3:{
				cout << "Popped: " << s.pop1();
				s.display1();
				break;
			}
			case 4:{
				cout << "Popped: " << s.pop2();
				s.display2();
				break;
			}
			case 5:{
				s.display1();
				break;
			}
			case 6:{
				s.display2();
				break;
			}
		}
	}while(n != 7);
	return 0;
}