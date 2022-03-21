#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// logic here is to keep a -1 at the bottom
// and in 's' we are storing values 
//  - always pushing the current but also popping if on next iteration it becomes big
//  - in descending order

vector<int> prevSmall2(vector<int> arr, int n) {
   stack<int>s;
   vector<int>ans(n);
   for(int i=0;i<n;i++){
       int curr= arr[i];
       while(!s.empty()&&s.top()>=curr){
           s.pop();
       }
       if(s.empty())s.push(-1);
       ans[i]=s.top();
       s.push(curr);
   }
   return ans;
}

int main(){
    vector<int> arr = {9,8,1,3,10,5,5};
    arr = prevSmall2(arr, arr.size());
    for(int i=0 ; i<arr.size() ; ++i){
        cout << arr[i] << " ";
    }
    return 0;
}