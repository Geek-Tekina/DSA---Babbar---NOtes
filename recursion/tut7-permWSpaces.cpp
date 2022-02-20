#include <iostream>
#include <string>
using namespace std;
typedef string s;

void solve(s str, s op){
    if(str.size()==0){
        for(int i=0 ; i<op.size(); i++){
            cout << op[i];
        }
        cout << "\n";
        return;
    }
    s ops = op;
    ops.push_back('-');
    ops.push_back(str[0]);
    op.push_back(str[0]);
    str.erase(str.begin());
    solve(str, op);
    solve(str,ops);
}

int main(){
    s str = "abc";
    s op;
    op.push_back(str[0]);
    str.erase(str.begin());
    solve(str, op);
    return 0;
}