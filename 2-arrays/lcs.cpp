#include <bits/stdc++.h>
#include <vector>
using namespace std;

int solve(){
    vector<int> arr = {9, 8, 7, 6, 5, 4, 9, 8, 7, 6, 5, 4, 4};
    unordered_map<int, int> m;
    for(auto i:arr){
        m[i]++;
    }
    
    int temp=0,si=0;
    for(int i=1 ; i<=m.size() ; i++){

        // if(m[i] == 0){
        //     temp =
        //     cout << i-1;
        //     return 0;
        // } else {
        //     if (i==m.size()){
        //         if(m[i] == 0)   cout << i-1;
        //         else cout << i;
        //     }
        // }
        if(m[i]==0){
            si = i;
            temp = 0;
            if(i==m.size()){
                return temp-i-si;
            }
        }
    }
    return 0;
}

int main(){
    cout << solve();
}