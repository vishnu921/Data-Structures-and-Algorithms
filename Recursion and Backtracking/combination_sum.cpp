/*
Given an array of integers and a sum b, find all unique combinations in the array where the sum is 
equal to B. The same number may be chosen from the array any number of times to make b.

Note:
        1. All numbers will be positive integers.
        2. Elements in a combination (a1, a2, …, ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
        3. The combinations themselves must be sorted in ascending order.
 */

#include <bits/stdc++.h>
using namespace std;

/*
a = input array of elements
n = size of array a
sum = target sum
i = current index
cur = current combination of elements
res = array of valid combinations
*/
void solveCombination(vector<int> &a, int n, int sum, int i, vector<int> cur, vector<vector<int>> &res){
	if(sum == 0){
		res.push_back(cur);
		return;
	}

	if(i == n) return;

	while(i < n && sum >= a[i]){
		//push the current element into the combination
		cur.push_back(a[i]);

		//recur without increasing index because we can still choose a[i]
		solveCombination(a, n, sum-a[i], i, cur, res);
		//move to next element
		i++;

		//backtracking
		cur.pop_back();
	}
	// //if sum < a[i] that means it will be less than all the elements on the right since array is sorted
	// //if sum >= a[i] that means we can still choose a[i]
	// if(sum >= a[i]){
	// 	//push a[i] to current combination
	// 	cur.push_back(a[i]);
	// 	//recur without increasing i because we can still choose a[i]
	// 	solveCombination(a, n, sum-a[i], i, cur, res);
	// 	//backtracking
	// 	cur.pop_back();
	// 	//recur for other elements
	// 	solveCombination(a, n, sum, i+1, cur, res);
	// }
}

vector<vector<int>> combinationSum(vector<int> &a, int n, int sum){
	sort(a.begin(), a.end());

	//remove duplicates from the array
	a.erase(unique(a.begin(), a.end()), a.end());
	vector<int> cur;
	vector<vector<int>> res;
	solveCombination(a, n, sum, 0, cur, res);
	return res;
}

int main(){
	int n, b;
	cin >> n >> b;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	vector<vector<int>> res = combinationSum(a, n, b);
	for(auto v: res){
		for(auto i: v){
			cout << i << " ";
		}cout << endl;
	}
	return 0;
}