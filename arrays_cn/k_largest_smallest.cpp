#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

// 83% score
void kthSmallestLargest(int arr[], int n, int k) {
    unordered_set<int> st;
    int arr2[n];
    int j=0;
    for(int i=0 ; i <n ; ++i){
        if(st.find(arr[i])==st.end()){
            st.insert(arr[i]);
            arr2[j] = arr[i];
            ++j;
        }
    }
	sort(arr2, arr2+j);
    if(j>=k){
        cout << arr2[j-k] << " " << arr2[k-1];
    } else {
        cout << "-1 -1";
    }
}

int main() {
    int t;
    cin >> t;

    while (t > 0) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        kthSmallestLargest(arr, n, k);
        t--;
    }
    return 0;
}