#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<int> maxSubarray(vector<int> arr, int k){
    vector<int> res;
    deque<int> d;
    d.push_front(0);
    for(int i=1 ; i<k ; ++i){
        if(arr[i] > arr[d.front()])  d.push_front(i);
        else    d.push_back(i);
    }

    for(int i=k ; i<arr.size() ; ++i){
        res.push_back(arr[d.front()]);

        while(!d.empty() && d.front()<= i-k){
            d.pop_front();
        }
        if(arr[i] > arr[d.front()])  d.push_front(i);
        else    d.push_back(i);
    }
    
    res.push_back(arr[d.front()]);
    return res;
}

int main(){
    for(auto it:maxSubarray({1, 2, 3,4,5}, 1))
        cout << it << " ";
    return 0;
}