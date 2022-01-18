#include <iostream>
#include <string>
using namespace std;
typedef string s; 

void solve(int o,int c, s op){
    if(o==0 && c==0){
        cout << op << endl;
        return;
    }
    if(o==c){
        op.push_back('(');
        solve(o-1,c,op);
        return;
    }
    if(o == 0 && c!=0){
        op.push_back(')');
        solve(o,c-1,op);
        return;
    }
    s op1,op2;
    op1 = op;
    op2 = op;
    op1.push_back('(');
    solve(o-1,c,op1);
    op2.push_back(')');
    solve(o,c-1,op2);
}

int main(){
    solve(3,3,"");
    return 0;
}