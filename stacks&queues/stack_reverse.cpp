#include <bits/stdc++.h>
using namespace std;

int main(){
    stack<int> s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    // 30 20 10
    stack<int> s2;
    while(!s1.empty()){
        s2.push(s1.top());
        s1.pop();
    }    
    cout << s2.top();
    return 0;
}