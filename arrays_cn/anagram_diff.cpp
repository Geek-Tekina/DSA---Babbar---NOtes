#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
typedef string s;

int anagramDiff(s str1, s str2){
    int res=0;
    unordered_map<char, int> mp1, mp2;
    for(int i=0 ; i<str1.size() ; ++i)     ++mp1[str1[i]];
    for(int i=0 ; i<str2.size() ; ++i)     ++mp2[str2[i]];

    for(auto it:mp1){
        if(mp2.find(it.first)!=mp2.end()){
            res += abs(it.second - mp2[it.first]);
        } else {
            res += it.second;
        }
    }
    return res;
}

int main(){
    cout << anagramDiff("hear", "here");
    return 0;
}