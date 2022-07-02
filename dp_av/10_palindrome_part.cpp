#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<vector<string>> res;
bool isPal(string s, int start, int end){
    while(start < end){
        if(s[start] != s[end])    return false;
        start++;
        end--;
    }
    return true;
}

void solve(string s, vector<string> path, int start){
    if(start == s.size())   res.push_back(path);
    else {
        for(int i=start ; i<s.size() ; ++i){
            if(isPal(s, start, i)){
                path.push_back(s.substr(start, i-start+1));
                solve(s, path, i+1);
                path.pop_back();
            }
        }
    }
}

int main(){
    vector<string> path;
    solve("aab", path, 0);
    // print 2d vector of strings
    for(auto v : res){
        for(auto s : v){
            cout << s << " ";
        }
        cout << endl;
    }
    
    return 0;
}