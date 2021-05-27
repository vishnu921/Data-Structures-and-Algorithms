/*
Given three stacks of the positive numbers, the task is to find the possible equal maximum sum of the stacks with 
the removal of top elements allowed. Stacks are represented as an array, and the first index of the array represent 
the top element of the stack.
*/
#include <bits/stdc++.h>
using namespace std;

int maximumEqualSum(int s1[], int s2[], int s3[],int n1, int n2, int n3){
	int sum1 = 0, sum2 = 0, sum3 = 0;
	for(int i = 0; i < n1; i++){
		sum1 += s1[i];
	}
	for(int i = 0; i < n2; i++){
		sum2 += s2[i];
	}
	for(int i = 0; i < n3; i++){
		sum3 += s3[i];
	}

	if(sum1 == sum2 && sum2 == sum3) return sum1;

	int i = 0, j = 0, k = 0;
	while((i < n1) && (j < n2) && (k < n3)){
		if(sum1 == sum2 && sum2 == sum3) return sum1;

		if(sum1 >= sum2 && sum1 >= sum3){
			sum1 -= s1[i++];
		}

		if(sum2 >= sum1 && sum2 >= sum3){
			sum2 -= s2[j++];
		}

		if(sum3 >= sum1 && sum3 >= sum2){
			sum3 -= s3[k++];
		}
	}
	return 0;
}

int main(){
	int s1[] = {3,2,1,1,1};
	int s2[] = {4,3,2};
	int s3[] = {1,1,4,1};

	int n1 = sizeof(s1)/sizeof(s1[0]);
	int n2 = sizeof(s2)/sizeof(s2[0]);
	int n3 = sizeof(s3)/sizeof(s3[0]);

	cout << maximumEqualSum(s1,s2,s3,n1,n2,n3) << endl;
	return 0;
}