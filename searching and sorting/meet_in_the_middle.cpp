/*
Problem: https://www.spoj.com/problems/SUBSUMS/

Meet in the middle is a search technique which is used when the input is small but not as small that brute force 
can be used. Like divide and conquer it splits the problem into two, solves them individually and then merge them. 
But we can’t apply meet in the middle like divide and conquer because we don’t have the same structure as the original 
problem.

-> Split the set of integers into 2 subsets say A and B. A having first n/2 integers and B having rest.
-> Find all possible subset sums of integers in set A and store in an array X. Similarly calculate all possible subset 
   sums of integers in set B and store in array Y. Hence, Size of each of the array X and Y will be at most 2n/2.
-> Now merge these 2 subproblems. Find combinations from array X and Y such that their sum is less than or equal to S. 
-> One way to do that is simply iterate over all elements of array Y for each element of array X to check the existence 
   of such a combination. This will take O( (2n/2)2) which is equivalent to O(2n).
-> To make it less complex, first sort array Y and then iterate over each element of X and for each element x in X use 
   binary search to find maximum element y in Y such that x + y <= S.
-> Binary search here helps in reducing complexity from 2nto 2n/2log(2n/2)which is equivalent to 2n/2n.
Thus our final running time is O(2n/2n).
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void calcSub(ll a[], vector<ll> &v, int n, int c){

	for(int i = 0; i < pow(2,n); i++){
		ll sum = 0;
		for(int j=0; j < n; j++){
			if(i & (1<<j)){
				sum += a[j+c];
			}
		}
		v.push_back(sum);
	}
}

ll subSums(ll a[], int n, ll A, ll B){

	vector<ll> X, Y;

	calcSub(a, X, n/2, 0);
	calcSub(a, Y, (n&1)?n/2+1:n/2, n/2);

	int sizeX = X.size();
	int sizeY = Y.size();

	sort(Y.begin(), Y.end());

	ll res = 0, low, high;

	for(int i = 0; i < sizeX; i++){

		low = lower_bound(Y.begin(), Y.end(), A-X[i]) - Y.begin();
		high = upper_bound(Y.begin(), Y.end(), B-X[i]) - Y.begin();

		res += (high-low);
	}

	return res;
}

int main(){
	int n;
	ll A, B;
	cin >> n >> A >> B;
	ll a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	cout << subSums(a, n, A, B) << "\n";
	return 0;
}