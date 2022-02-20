#include <iostream>
#include <stack>
using namespace std;

void del(stack<int> &s, int k){
    if(k == 1){
        s.pop();
        return;
    }
    int val = s.top();
    s.pop();
    del(s,k-1);
    s.push(val);
    return;
}

int main(){
    stack<int> s;
    for(int i=1 ; i<=6 ; i++)
        s.push(i);
    int k = s.size()/2 + 1;
    del(s, k);
    while(s.size() != 0){
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}