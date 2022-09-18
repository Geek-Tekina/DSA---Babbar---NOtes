#include <bits/stdc++.h>
using namespace std;
typedef vector<string> vs;
typedef vector<vs> vvs;

bool isPalindrome(int i, int j, string &s){
    while(i < j){
        if(s[i] != s[j]) return false;
        i++; j--;
    }
    return true;
}

void solve(int i, int j, string &s, vs &temp){
    if(i==j)    
        temp.push_back(s.substr(i, i));
    else if(isPalindrome(i, j, s))
        temp.push_back(s.substr(i, j));          
    else {
        for(int k=i ; k<j ; ++k){
            solve(i, k, s, temp);
            solve(k+1, j, s, temp);
        }
    }
}

vvs partition(string s){
    vvs res;
    int i=0, j=s.size()-1 ;
    vs temp;
    for(int k=0 ; k<j ; ++k){
        temp = {};
        solve(i, k, s, temp);
        solve(k+1, j, s, temp);
        res.push_back(temp);
    }
    return res;
}

int main(){
    vvs res = partition("aab");
    // print res
    for(auto list: res){
        cout << "[";
        for(auto s: list){
            cout << s << ",";
        }
        cout << "]" << endl;
    }
    return 0;
}