#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll merge(ll arr[], ll low, ll mid, ll high){
    ll temp[high-low+1];
    ll i = low, j = mid+1, k = 0, inv_count = 0;
    
    while(i <= mid && j <= high){
        if(arr[i] <= arr[j]){
            temp[k++] = arr[i++];
        } else{
            inv_count += (mid-i+1);
            temp[k++] = arr[j++];
        }
    }
    
    while(i <= mid){
        temp[k++] = arr[i++];
    }
    while(j <= high){
        temp[k++] = arr[j++];
    }
    
    k = 0;
    for(i = low; i <= high; i++){
        arr[i] = temp[k++];
    }
    
    return  inv_count;
}

ll mergeSort(ll arr[], ll low, ll high){
    
    ll inv_count = 0;
    
    if(low < high){
        
        ll mid = low + (high-low)/2;
        
        inv_count += mergeSort(arr, low, mid);
        inv_count += mergeSort(arr, mid+1, high);
        
        inv_count += merge(arr, low, mid, high);
    }
    
    return inv_count;
}

ll inversionCount(ll arr[], ll N)
{
    ll inv_count = mergeSort(arr, 0, N-1);
    return inv_count;
}


int main(){
	ll n;
	cin >> n;
	ll arr[n];
	for(ll i = 0; i < n; i++){
		cin >> arr[i];
	}

	cout << inversionCount(arr, n) << "\n";
	return 0;
}