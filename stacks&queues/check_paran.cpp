#include <iostream>
#include<stack>
using namespace std;

bool isValidParenthesis(string e) {
    stack<char> s;
    for(int i=0;i<e.size();i++){\
        if(e[i]=='(' || e[i]=='[' || e[i]=='{'){
            cout << "pushing to stack " << e[i] << endl;
            s.push(e[i]);
        } else {
            if(s.empty())   return false;
            if(e[i] == ')' && s.top() != '(')   return false;
            else if(e[i] == ']' && s.top() != '[')   return false;
            else if(e[i] == '}' && s.top() != '{')   return false;
            else s.pop();
        }
    }
    if(s.size() != 0) return false;
    else return true;
}

int main(){
    cout << isValidParenthesis("[((){})]");
    return 0;
}