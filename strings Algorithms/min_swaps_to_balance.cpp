/*
You are given a string of 2N characters consisting of N ‘[‘ brackets and N ‘]’ brackets. A string is 
considered balanced if it can be represented in the for S2[S1] where S1 and S2 are balanced strings.
We can make an unbalanced string balanced by swapping adjacent characters. Calculate the minimum 
number of swaps necessary to make a string balanced.

Examples: 

Input  : []][][
Output : 2
First swap: Position 3 and 4
[][]][
Second swap: Position 5 and 6
[][][]
*/

#include <bits/stdc++.h>
using namespace std;

int minSwaps(string s){
	int n = s.length();
	int left = 0, right = 0;
	int ans = 0, imbalance = 0;        //imbalance variable stores imbalanced pairs upto current i
	for(int i = 0; i < n; i++){
		if(s[i] == '['){
			//increase the count of left brace
			left++;

			//if imbalance is greater than 0
			if(imbalance > 0){
				ans += imbalance;

				//imbalance is decreased by 1 becuase it solve
				//only one imbalance of brackets
				imbalance--;
			}
		}
		else{
			//increase the counter of right braces
			right++;

			//update the imbalance
			imbalance = right-left;
		}
	}

	return ans;
}

int main(){
	string s;
	cin >> s;

	cout << minSwaps(s) << "\n";
	return 0;
}