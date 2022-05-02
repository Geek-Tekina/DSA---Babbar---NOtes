#include <bits/stdc++.h>
#include <string>
using namespace std;

// since we were supposed to deal with unique characters so we thought of set and map
// since the freq count was necessary so we used map

// variable sized ws are broken into 3 patrs - extend, calculate and then shrink
// for extend we just put inside map
// for calculation we just find the max len
// for shrinking, i is the very very very important
int solve(string s, int k){
    int res=0;
    unordered_map<char, int> mp;
    int i=0;
    for(int j=0 ; j<s.size() ; ++j){
        if(mp.size() <= k)   ++mp[s[j]];
        if(mp.size() == k) {
            res = max(res, j-i+1);
        }
        else if(mp.size() > k){
            while(mp.size() > k){
                --mp[s[i]];
                if(mp[s[i]] == 0) mp.erase(s[i]);
                ++i;
            }
        }
    }
    return res;
}

int main(){
    cout << solve("aabacbebebe", 3);
    return 0;
}