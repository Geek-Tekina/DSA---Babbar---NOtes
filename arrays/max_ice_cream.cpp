#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<int> vi;

int maxIceCreams(vi &costs, int coins){
    sort(costs.begin(), costs.end());
    int ans = 0;
    for(int i = 0; i < costs.size(); i++){
        if(coins >= costs[i]){
            coins -= costs[i];
            ans++;
        }
    }
    return ans;
}

int main(){
    vi costs = {1,1,2,3,5,6};
    cout << maxIceCreams(costs, 10) << endl;
    return 0;
}