#include <iostream>
#include <vector>
using namespace std;

int maxSubarraySumCircular(vector<int>& nums){
    int frontMS = 0, backMS = 0;
    int fi, fj, bi, bj;
    fi = fj = bi = bj = 0;
    int sum = 0;

    for(int i=0; i<nums.size() ; ++i){
        if(sum + nums[i] < 0){
            fi = i;
            sum = 0;
        } else {
            sum += nums[i];
            if(sum > frontMS){
                frontMS = sum;
                fj = i;
            }
        }
    }
    sum = 0;
    bi = bj = nums.size()-1;
    for(int i = nums.size()-1; i>=0 ; --i){
        if(sum + nums[i] < 0){
            bi = i;
            sum = 0;
        } else {
            sum += nums[i];
            if(sum > backMS){
                backMS = sum;
                bj = i;
            }
        }
    }

    cout << "fi: " << fi << " fj: " << fj << " bi: " << bi << " bj: " << bj << endl;
    cout << "frontMS: " << frontMS << " backMS: " << backMS << endl;
    int res = 0;
    if(fi == 0){
        if(fj == nums.size()-1) return frontMS;
        else if(bj > fj) {
            return frontMS + backMS;
        } else {
            res = frontMS;
        }
    }

    return frontMS;
}

int main(){
    vector<int> nums = {5, -3, 5};
    cout << maxSubarraySumCircular(nums);
    return 0;
}