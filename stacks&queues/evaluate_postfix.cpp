#include <bits/stdc++.h>
#include <string>
using namespace std;

int main(){
    string exp = "4 6 + 2 / 5 * 7 + ";
    stack<int> s;
    int op2, op1;
    int i=0;
    while(i<exp.size()){
        if( isdigit(exp[i]) ){
            int temp = exp[i] - '0';
            s.push(temp);
            i+=2;
        } else {
            op2 = s.top(); s.pop();
            op1 = s.top(); s.pop();
            int res;
            if(exp[i] == '+')   res = op1+op2;
            else if (exp[i]== '-')  res = op1-op2;
            else if (exp[i]== '*')  res = op1*op2;
            else if (exp[i]== '/')  res = op1/op2;
            else {}
            i+=2;
            s.push(res);
        }
    } 
    cout << s.top();
    return 0;
}