#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;
typedef vector<long long> vi;

long long solve(vi &a, long long m){
    sort(a.begin(), a.end());
    long long l = 0, r = m - 1;
    long long res = INT_MAX;
    while(r < a.size()){
        res = min(res, a[r] - a[l]);
        l++; r++;
    }
    return res;
}

int main(){
    vi v = {3, 4, 1, 9, 56, 7, 9, 12};
    cout << solve(v, 5) << endl;
    return 0;
}