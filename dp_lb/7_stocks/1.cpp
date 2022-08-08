#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int> &prices){
    int m=1e6, ans=0;
    for(auto &p: prices)
        ans=max(ans, p-m), m=min(m, p);
    return ans;
}

int main(){
    vector<int> p = {2,4,0};
    cout<<solve(p)<<endl;
    return 0;
}