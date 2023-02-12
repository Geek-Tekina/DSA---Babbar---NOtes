#include <iostream>
#include <vector>
using namespace std;

/*
Case 1(true): One-One Mapping [aab, xxy]
Case 2(false): When s has two different values in t [aab, xzy]
Case 3(false): When two s has same values in t [abc, xxy]
*/

bool solve(string& s, string& t){
    unordered_map<char, int> hash;
    for(int i=0 ; i<s.size(); ++i){
        if( hash[s[i]].find() != hash.end() ){
            if( hash[s[i]] != t[i] )    return false;
        } else hash[s[i]] = t[i];
    }

    return true;
}

bool isomorphic(string& s, string& t){
    return solve(s, t) and solve(t, s);
}

int main(){
    string s = "aab", t = "xxy";
    return 0;
}