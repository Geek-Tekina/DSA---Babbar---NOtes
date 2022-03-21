#include <iostream>
#include <stack>
using namespace std;

void deleteMiddle(stack<int> &s, int N){
    stack<int> s2;
    int ti;
    if(N+1 % 2 == 0) ti = (N+1)/2 - 1;
    else     ti = (N+1)/2;
   
    while(s.size() > ti){
       int temp = s.top();
       s.pop();
       s2.push(temp);
    }
    s2.pop();
    while(!s2.empty()){
       int temp = s2.top();
       s2.pop();
       s.push(temp);
    }
}

int main(){
    stack<int> s;
    s.push(5);
    s.push(4);
    s.push(3);
    s.push(2);
    // s.push(1);
    deleteMiddle(s, s.size()-1);
        while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}