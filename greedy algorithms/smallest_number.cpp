/*
The task is to find the smallest number with given sum of digits as S and number of digits as D.
*/
#include <bits/stdc++.h>
using namespace std;

string smallest_number(int s, int d){
	if(s > d*9) return "NOT POSSIBLE";
	if(s == 0){
		return ((d == 1)?"0":"NOT POSSIBLE");
	}

	string res = "";

	//deduct sum by 1 for the case when s may become 0
	s = s-1;

	//fill d-1 digits from right to left;
	for(int i = 1; i < d; i++){
		if(s > 9){
			res += "9";
			s = s-9;
		}
		else{
			res += to_string(s);
			s = 0;
		}
	}

	//whatever is left is put at most significant digit
	res += to_string(s+1); 		//the 1 deducted previously is used here
	//reverse the string
	reverse(res.begin(), res.end());
	return res;

}

int main(){
	int s, d;
	cin >> s >> d;
	cout << smallest_number(s, d) << endl;
	return 0;
}