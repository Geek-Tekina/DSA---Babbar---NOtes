#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;

bool solve(int start, vector<string> op, string s, vector<string> &wordDict){
    int n = s.size();
    if(start == n)
        return true;

    string temp = "";
    while(start < n){
        temp += s[start++];
        if(find(wordDict.begin(), wordDict.end(), temp) != wordDict.end()){
            op.push_back(temp);
            if(solve(start, op, s, wordDict))   return true;
            op.pop_back();
        }
    } 
    return false;
}

int main(){
    string s = "aaaaaaa";
    vector<string> wordDict = {"aaaa", "aaa"};
    cout << solve(0, {}, s, wordDict);
    return 0;
}