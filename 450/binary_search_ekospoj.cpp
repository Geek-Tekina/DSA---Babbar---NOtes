#include <iostream>
#include <vector>
using namespace std;

int solve(auto &v, int target){
    int max_val = 0;
    for(auto it: v) max_val = max(max_val, it);
    cout << "max val : " << max_val << endl;

    int l=0, r=max_val;
    while(l<r){
        int blade_height = (l+r)/2;
        int wood=0;
        for(auto tree_height: v)
            if(tree_height > blade_height) wood += tree_height - blade_height;
        if(wood == target) return blade_height;
        else if(wood > target) l = blade_height;
        else r = blade_height;
    }
    return -1;
}

int main(){
    vector<int> v = {1,2,3, 4, 5, 6, 7};
    cout << solve(v, 8) << endl;
    return 0;
}