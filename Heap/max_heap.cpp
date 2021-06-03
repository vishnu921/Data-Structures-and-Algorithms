/*
Properties of max-heap:
-> Tree based data structure in which tree is a complete binary tree
-> The value of root node is greater than all of its children and this property must be true
	for all subtree in that binary tree

Operation in Max-heap:
-> insert
-> getmax()
-> extractmax()
-> heapify()
*/

#include <bits/stdc++.h>
using namespace std;

class MaxHeap{
	int *harr;
	int heap_size;
	int capacity;
public:
	MaxHeap(int cap){
		heap_size = 0;
		capacity = cap;
		harr = new int[cap];
	}

	int parent(int i){ return (i-1)/2; }

	int left(int i){ return (2*i + 1); }

	int right(int i){ return (2*i + 2); }

	//getmax
	int getmax(){ return harr[0]; }

	int size(){ return heap_size; }

	//insert an element in the heap O(logn)
	void insert(int val){
		if(heap_size == capacity){
			cout << "overflow\n";
			return;
		}

		heap_size++;
		int i = heap_size - 1;
		harr[i] = val;

		//compare ith element with parent until heap property is satisfied
		while(i != 0 && harr[parent(i)] < harr[i]){
			swap(harr[i], harr[parent(i)]);
			i = parent(i);
		}
	}

	//heapify O(logn)
	void heapify(int i){
		int l = left(i);
		int r = right(i);

		int max = i;

		if(l < heap_size && harr[l] > harr[max]){
			max = l;
		}
		if(r < heap_size && harr[r] > harr[max]){
			max = r;
		}

		//if ith node is less than any of its child
		if(max != i){
			swap(harr[i], harr[max]);
			heapify(max);
		}
	}

	//extract max O(logn)
	int extractmax(){
		if(heap_size <= 0){
			cout << "Underflow\n";
			return -1;
		}
		if(heap_size == 1){
			heap_size--;
			return harr[0];
		}

		int root = harr[0];
		harr[0] = harr[heap_size-1];
		heap_size--;
		heapify(0);

		return root;
	}


	//Building heap from an array
	//inserting elements one-by-one into heap will build heap in O(nlogn) time
	//To build the heap efficiently we first copy all element of given array into the heap
	//and then we heapify every internal(non-leaf) node from bottom
	void buildheap(int a[], int n){
		//copy all elements of the array into harr
		for(int i = 0; i < n; i++){
			harr[i] = a[i];
		}

		heap_size = n;

		//(n/2-1) is the first non-leaf node from bottom
		for(int i = (n/2-1); i >= 0; i--){
			heapify(i);
		}
	}

};


int main(){
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	cout << "Building max-heap\n";
	MaxHeap mheap(n);
	mheap.buildheap(a, n);

	while(mheap.size() != 0){
		cout << mheap.extractmax() << " ";
	}
	return 0;
}