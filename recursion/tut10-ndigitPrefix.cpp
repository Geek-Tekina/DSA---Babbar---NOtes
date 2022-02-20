#include <iostream>
#include <string>
using namespace std;
typedef string v;

// Print N binary digit numbers
// whose prefixes have #1 >= #0
// e.g. for N=3, {111,110,101}

void solve(int o, int z, int N, v op){
    if(o+z == N){
        cout << op << endl;
        return;
    }
    if(o==z){
        op.push_back('1');
        solve(o+1, z, N, op);    
        return;
    }
    if(o>z){
        v op1 = op;
        op1.push_back('1');
        op.push_back('0');
        solve(o+1, z, N, op1);
        solve(o, z+1, N, op);
    }
}

int main(){
    solve(1,0,4,"1");
    return 0;
}