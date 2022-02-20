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
    if(str[0]>= 0 && str[0]<=9){
        cout << "for "<< str[0];
        op.push_back(str[0]);
        str.erase(str.begin());
        solve(str, op);
        return;
    } else {
        s opL = op;
        cout << "for "<< str[0];
        opL.push_back(tolower(str[0]));
        op.push_back(toupper(str[0]));
        str.erase(str.begin());
        solve(str,opL);
        solve(str,op);
        return;
    }
}

int main(){
    s str = "a1";
    solve(str, "");
    return 0;
}