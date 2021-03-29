//implement k stacks in a single array
#include <bits/stdc++.h>
using namespace std;

/*
In this problem we will use 2 extra arrays top[k] and next[n]
top[i] stores the index of the top element of the ith stack
next[i] stores the next entry in all the stacks 
variable free stores the beginning index of the free list(where elements can be inserted)
*/
class Kstacks{
	int *arr;
	int *top;
	int *next;
	int n, k;
	int free;
public:
	Kstacks(int n1, int k1)
	{
		k = k1; n = n1;
		arr = new int[n];           //stores actuall elements of the k stacks
		top = new int[k];           //stores top element of all the stacks
		next = new int [n];           //stores next element of every stack
		free = 0;
		for(int i = 0; i < k; i++)
			top[i] = -1;

		for(int i = 0; i < n-1; i++)
			next[i] = i+1;
		next[n-1] = -1;

		for(int i = 0; i < n; i++)
			arr[i] = 0;
	}

	bool isfull(){ return (free == -1); }

	bool isempty(int sn){ return (top[sn] == -1); }

	void push(int x, int sn)
	{
		if(isfull()){
			cout << "stack oveflow!!\n";
			return;
		}

		int i = free;
		free = next[i];
		next[i] = top[sn];
		top[sn] = i;
		arr[i] = x;
	}

	int pop(int sn){
		if(isempty(sn)){
			cout << "Empty stack\n";
			return -1;
		}

		int i = top[sn];
		top[sn] = next[i];
		next[i] = free;
		free = i;
		return arr[i];
	}

	void display(int sn){
		if(isempty(sn)){
			cout << "Empty stack\n";
			return;
		}
		cout << "Stack no " << sn << ": ";
		int i = top[sn];
		while(i != -1){
			cout << arr[i] << " ";
			i = next[i];
		}
		cout << endl;
	}
};

int main(){
	int n,k,x;
	cin >> n >> k;
	Kstacks stk(n, k);
	do{
		cout << "1.Push 2.Pop 3.Exit\n";
		cout << "Enter choice: ";
		cin >> n;
		switch(n){
			case 1:{
				cout << "Enter item: ";
				cin >> x;
				cout << "Enter stack no.: ";
				cin >> k;
				stk.push(x, k);
				stk.display(k);
				break;
			}
			case 2:{
				cout << "Enter stack no.: ";
				cin >> k;
				cout << "Popped: " << stk.pop(k) << endl;
				stk.display(k);
				break;
			}
		}
	}while(n != 3);
	return 0;
}