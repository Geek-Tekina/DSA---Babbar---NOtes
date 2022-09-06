#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;
typedef vector<int> vi;
typedef long long unsigned int lli;


bool findSubarrays(vi &nums){ 
    unordered_set<lli> s;
    for(int i=0 ; i<nums.size()-1 ; ++i){
        lli sum = nums[i] + nums[i+1];
        if(s.find(sum) != s.end()) return true;
        else    s.insert(sum);
    }
    return false;
}

char reVal(int num){
    if (num >= 0 && num <= 9)   return (char)(num + '0');
    else    return (char)(num - 10 + 'A');
}
 
string fromDeci(string& res, int base, int inputNum){
    int index = 0; 
    while (inputNum > 0) {
        res.push_back(reVal(inputNum % base));
        index++;
        inputNum /= base;
    }
    reverse(res.begin(), res.end());
    return res;
}

bool isStrictlyPalindromic(int n) {
    int num = n;
    for(int base=2; base<= n-2 ; ++base){
        string res;
        fromDeci(res, base, num);
        for(int i = 0; i < res.size()/2; i++){  
            if(res[i] != res[res.size()-i-1])
                return false;
        }  
    }
    return true;
}

int main(){
    // vector<int> nums = {4,2,4};
    // cout << findSubarrays(nums) << endl;
    // cout << isStrictlyPalindromic(9) << endl;
    
    return 0;
}