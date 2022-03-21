#include <iostream>
#include <stack>
using namespace std;
stack<int> s;

void place(int key){
    if(s.size() == 0)   s.push(key);
    else if(s.top() > key) {
        int temp = s.top();
        s.pop();
        place(key);
        s.push(temp);
    } else  s.push(key);
}

void solve(int n){
    if(n > 0){
     int temp = s.top();
        s.pop();
        solve(n-1);
        place(temp);
    }
}

int main(){
    s.push(5);
    s.push(10); 
    s.push(2);
    s.push(0);
    s.push(1);
    solve(s.size());
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}