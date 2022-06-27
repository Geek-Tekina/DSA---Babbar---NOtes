#include <iostream>
#include <vector>
#include <string>
using namespace std;
typedef string str;

void solve(str inp, str op){
    if(inp.size() == 1){
        cout << op << inp[0] << endl;
    }
    for(int i=0 ; i<inp.size() ; ++i){
        char ch = inp[i];
        inp.erase(inp.begin() + i);
        solve(inp, op + ch);
        inp.insert(inp.begin() + i, ch);
    }
}

int main(){
    str inp = "abc";
    solve(inp, "");
    return 0;
}