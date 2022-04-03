#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSumEqualToZero(vector<int>& arr) {
    vector<vector<int>> res;
    sort(arr.begin(), arr.end());
    int n = arr.size();
    for(int i=0 ; i<n-1 ; ++i){
        if( i!=0 && arr[i] == arr[i-1]) continue;
        int low = i+1;
        int high = n-1;
        int target =  0-arr[i];
        while(low<high){
            if(arr[low] + arr[high] == target){
                res.push_back({arr[i], arr[low], arr[high]});
                int tempH = arr[high];
                int tempL = arr[low];
                while(tempH == arr[--high] && low<high){}
                while(tempL == arr[++low] && low<high ){}
            } else if (arr[low] + arr[high] > target)	--high;
            else	++low;
        }
    }
    return res;
}

int main(){
    return 0;
}