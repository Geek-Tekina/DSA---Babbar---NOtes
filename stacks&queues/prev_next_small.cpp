#include <bits/stdc++.h>
#include <stack>
using namespace std;

// smaller means bottom of the stack must be smaller and hence
// DESC order, this means if top element is bigger then we know after popping
// we will get a smaller element which might be the candidate.

// and to check with left elments, we can iterate in ++i manner
// else for right elements, in --i manner

vector<int> prevSmall(vector<int> v){
    stack<int> s;
    vector<int> res(v.size(), -1);
    for(int i=0 ; i<v.size() ; ++i){
        while(!s.empty() && s.top()>=v[i]){
            s.pop();
        }
        if(!s.empty())  res[i] = s.top();
        s.push(v[i]);
    }
    return res;
}

vector<int> nextSmall(vector<int> v){
    stack<int> s;
    vector<int> res(v.size(), -1);
    for(int i=v.size()-1 ; i>=0 ; --i){
        while(!s.empty() && s.top()>=v[i]){
            s.pop();
        }
        if(!s.empty())  res[i] = s.top();
        s.push(v[i]);
    }
    return res;
}

int main(){
    vector<int> arr = {4,8,5,2,25};
    // arr = prevSmall(arr);
    arr = nextSmall(arr);
    for(int i=0 ; i<arr.size() ; ++i){
        cout << arr[i] << " ";
    }
    return 0;
}