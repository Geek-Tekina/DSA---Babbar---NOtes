#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> firstNegative(vector<int> arr, int n, int k) {
	deque<int> di;
    vector<int> v;
    for(int i=0; i<k ; ++i)
        if(arr[i]<0)    di.push_back(i);
    
    for(int i=k ; i<n ; ++i){
        if(!di.empty()) v.push_back(arr[di.front()]);
        else    v.push_back(0);

        while(!di.empty() && di.front() < (i - k + 1))
            di.pop_front();
        
        if(arr[i] < 0)    di.push_back(i);
    }
    if (!di.empty())
           v.push_back(arr[di.front()]);
    else
        v.push_back(0);
    return v;
}

int main(){
    for(auto it: firstNegative({-2, 0},2, 1)){
        cout << it << " ";
    }
    return 0;
}