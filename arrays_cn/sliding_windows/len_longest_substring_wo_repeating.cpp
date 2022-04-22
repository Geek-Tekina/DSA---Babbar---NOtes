#include <bits/stdc++.h>
#include <string>
using namespace std;

// the logic here is store the indices in the map
// so that whenever we see a repeating element we can just start from the temp 
// index which is one right to the conflicting one
// and we are using for loop to remove the previous than conflicting ones
int lengthOfLongestSubstringWoRepeating(string s) {
    unordered_map<char, int> mp;
    int res=0;
    int i=0;
    for(int j=0 ; j<s.size(); ++j){
        if(mp.find(s[j]) == mp.end())   mp[s[j]] = j;
        res = res > mp.size() ? res : mp.size();
        // sec cond is added avoid picking the same current element again
        if(mp.find(s[j]) != mp.end() && mp[s[j]] != j){
            int temp = mp[s[j]];
            for(;i<=temp ; ++i){
                mp.erase(s[i]);
            }
            mp[s[j]] = j;
        }
    }
    return res;
}

int main(){
    cout << lengthOfLongestSubstringWoRepeating("pwwkew");
    return 0;
}