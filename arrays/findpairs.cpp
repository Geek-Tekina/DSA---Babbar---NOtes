#include <bits/stdc++.h>
using namespace std;

int main(){
    map<int, int> m;
    int a[]= {1,2,2,3,3,4,5,5,6};
    int n = sizeof(a)/sizeof(int);
    for(int i=0 ; i<n ; i++){
        int temp=0;
        auto it = m.find(a[i]);
        if(it!=m.end()){
            temp = it->second;
        }
        m[a[i]] = temp+1;
    }
    for(auto it:m){
        cout << it.first << " : " << it.second << endl;
    }
    // ... main algo code
    return 0;
}