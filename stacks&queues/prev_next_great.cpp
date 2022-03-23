#include <bits/stdc++.h>
#include <stack>
using namespace std;
// greater means bottom of the stack must be greater and hence
// ASC order, this means if top element is smaller then we know after popping
// we will get a bigger element which might be the candidate.

// and to check with left elments, we can iterate in ++i manner
// else for right elements, in --i manner

vector<int> prevGreat(vector<int> v){
    stack<int> s;
    vector<int> res(v.size(), -1);
    for(int i=0 ; i<v.size(); ++i){
        while(!s.empty() && s.top()<=v[i]){
            s.pop();
        }
        if(!s.empty())  res[i] = s.top();
        s.push(v[i]);
    }
    return res;
}

vector<int> nextGreat(vector<int> v){
    stack<int> s;
    vector<int> res(v.size(), -1);
    for(int i=v.size()-1; i>= 0 ; --i){
        while(!s.empty() && s.top()<=v[i]){
            s.pop();
        }
        if(!s.empty())  res[i] = s.top();
        s.push(v[i]);
    }
    return res;
}

int main(){
    vector<int> arr = {8,8,1,8,9, 8};
    arr = nextGreat(arr);
    for(int i=0 ; i<arr.size() ; ++i){
        cout << arr[i] << " ";
    }
    return 0;
}