/*
Given an integer array a[ ] of N elements and an integer K, the task is to check if the array a[ ] could be divided into K non-empty subsets with equal sum of elements.
Note: All elements of this array should be part of exactly one partition.
*/
#include <bits/stdc++.h>
using namespace std;

/*
a[] = input array
n = input array size
k = no. of subsets required
index = current index
cur = current subset sum
sum = sum of every subset required
visited[] = boolean array marked true if element already visited/taken into a subset
*/
bool solvekpartition(int a[], int n, int k, int index, int cur, int sum, bool visited[]){
	//if k == 1 base case return true
	if(k == 1) return true;
	//if cur == sum then recur for remaining array and required subset is k-1 now
	if(cur == sum){
		return solvekpartition(a, n, k-1, 0, 0, sum, visited);
	}

	for(int i = index; i < n; i++){
		if(!visited[i] && cur+a[i] <= sum){
			//if a[i] was not visited and can be selected with current subset
			//mark it as visited
			visited[i] = true;
			//recur for remaining array 
			if(solvekpartition(a, n, k, i+1, cur+a[i], sum, visited))
				return true;
			//backtracking if selecting a[i] doesn't lead to solution
			visited[i] = false;
		}
	}

	return false;
}

bool isKpartitionPossible(int a[], int n, int k){
	int sum = 0;
	for(int i = 0; i < n; i++){
		sum += a[i];
	}
	//if k does not divides sum or n is less than k it is impossible 
	//to divide array into k subsets of equal sums
	if(sum%k != 0 || n < k) return false;

	sum = sum/k;
	bool visited[n];
	memset(visited, false, sizeof(visited));

	return solvekpartition(a, n, k, 0, 0, sum ,visited);

}

int main(){
	int n, k;
	cin >> n >> k;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	if(isKpartitionPossible(a, n, k)){
		cout << "YES\n";
	}
	else cout << "NO\n";
	return 0;
}