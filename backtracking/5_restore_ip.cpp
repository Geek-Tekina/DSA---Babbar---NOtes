#include <bits/stdc++.h>
#include <vector>
#include <string>
using namespace std;
typedef vector<string> vs;

bool isValidIP(string str) {
    if(str.length() == 1)   return true;
    if(str[0] == '0')       return false;
    int num = stoi(str);
    if(num >= 0 && num <= 255)  return true;
    return false;
}

void solve(string &str, int i, string ip, int count, vs &res) {
    if(i == str.length()) {
        if(count == 4)  res.push_back(ip);
        return;
    }
    string temp = "";
    for(int j = i; j < str.length(); j++) {
        temp += str[j];
        if(temp.length() <= 3 && isValidIP(temp)) {
            string newIP = ip;
            if(ip.length() != 0)    newIP += ".";
            newIP += temp;
            solve(str, j + 1, newIP, count+1, res);
        }
    }
}

int main(){
    vs res;
    string str = "25525511135";
    solve(str, 0, "", 0, res);
    for(auto x: res)    cout << x << endl;
    return 0;
}