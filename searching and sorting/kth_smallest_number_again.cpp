#include <bits/stdc++.h>
using namespace std;
#define pi pair<int,int>

/* Needs to be updated */
int search(vector<int> &a, int n, int k){
    int l = 0, r = n-1;
    while(l <= r){
        int mid = l + (r-l)/2;
        if(a[mid] >= k && (mid == 0 || a[mid-1] <= k)){
            return mid;
        } else if(a[mid] > k){
            r = mid-1;
        } else{
            l = mid+1;
        }
    }

    return -1;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,q;
        cin >> n >> q;
        vector<pi> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i].first;
            cin >> a[i].second;
        }

        vector<int> temp(n);
        temp[0] = a[0].second-a[0].first+1;
        for(int i = 1; i < n; i++){
            temp[i] = temp[i-1] + a[i-1].second-a[i-1].first+1;
        }

        while(q--){
            int k;
            cin >> k;
            int pos = search(temp, n, k);
            if(pos == -1){
                cout << "-1\n";
            } else if(pos == 0) {
                cout << a[pos].first + k - 1 << "\n";
            } else {
                int val = k - temp[pos-1];
                cout << a[pos].first + val - 1 << "\n";
            }
        }
    }
    return 0;
}