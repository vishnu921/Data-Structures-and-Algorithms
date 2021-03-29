//design a special stack that supports push(), pop() and getmin() operations
//getmin() returns minimum element from the stack
//all the operation should be O(1) time complexity and O(1) space complexity
#include <bits/stdc++.h>
using namespace std;

/*
How previous minimum element, prevMinEle is, 2*minEle - y in pop() when y is the popped element?

 We pushed y as 2x - prevMinEle. Here prevMinEle is minEle before y was inserted
 y = 2*x - prevMinEle  

Value of minEle was made equal to x
 minEle = x
    
 new minEle = 2 * minEle - y 
            = 2*x - (2*x - prevMinEle)
            = prevMinEle // This is what we wanted
*/

class SpecialStack{
	stack<int> s;
	int minEle;
public:
	bool isempty(){ return s.empty(); }

	void push(int x){
		if(s.empty()){
			s.push(x);
			minEle = x;
			return;
		}

		if(x >= minEle)
		{
			s.push(x);
		}
		else{
			s.push(2*x-minEle);
			minEle = x;
		}
	}

	void pop(){
		if(s.empty()){
			cout << "Empty stack\n";
			return;
		}

		int x = s.top();
		s.pop();

		if(x < minEle){
			cout << "Popped: " << minEle << endl;
			minEle = 2*minEle - x;
		}
		else{
			cout << "Popped: " << x << endl;
		}
	}

	int Top(){
		int t = s.top();
		if(t < minEle){
			return minEle;
		}
		return t;
	}

	int getmin(){
		if(s.empty()){
			cout << "Empty stack\n";
			return -1;
		}
		return minEle;
	}
};

int main(){
	int n,x;
	SpecialStack s;
	do{
		cout << "1. Push  2. Pop  3. Getmin  4. Exit\n";
		cout << "Enter choice: ";
		cin >> n;
		switch(n){
			case 1:{
				cout << "Enter element: ";
				cin >> x;
				s.push(x);
				break;
			}
			case 2:{
				s.pop();
				break;
			}
			case 3:{
				cout << "Minimum element: " << s.getmin() << endl;
				break;
			}
		}
	}while(n != 4);
	return 0;
}