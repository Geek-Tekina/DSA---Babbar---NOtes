#include <iostream>
#include <vector>
using namespace std;
typedef vector<char> v;

// void solve(vector<char> str,int i, vector<char> op){
//     if(i == str.size()-1){
//         for(int i=0 ; i<op.size(); i++){
//             cout << op[i];
//         }
//         cout << "\n";
//         return;
//     }
//     solve(str, i+1, op);
//     op.push_back(str[i]);
//     solve(str, i+1, op);
// }

void solve(v str, v op){
    if(str.size()==0){
        for(int i=0 ; i<op.size(); i++){
            cout << op[i];
        }
        cout << "\n";
        return;
    }
    char temp = str[0];
    str.erase(str.begin());
    solve(str, op);
    op.push_back(temp);
    solve(str, op);
}

int main(){
    v str = {'a','b'};
    // solve(str, 0, {});
    solve(str,{});
    return 0;
}