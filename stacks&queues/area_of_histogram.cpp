#include <iostream>
#include <vector>
#include <stack>
using namespace std;
typedef vector<int> vi;

// ;-;
/*
the pattern that can be observed is that we can use prevSmall and nextSmall to find the reach of the current element
and then multiply it with the elements value to get the area that it can cover.
see the reason we are using prev"Small" and next"Small" is that bec in that case we know all the reached items are bigger 
and hence the area can be taken out as common.
- prevSmall and nextSmall is implemented but with index storage and not value
- index is stored in order to calculate the reach of the element
*/

int largestRectangleArea(vector<int>& heights) {
    vi l(heights.size(), 0);
    vi r(heights.size(), heights.size()-1);
    stack<int> sl, sr;
    int res=0;
    for(int i=0 ; i<heights.size() ; ++i){
        while(!sl.empty() && heights[sl.top()]>=heights[i]){
            sl.pop();
        }
        if(!sl.empty())  l[i] = sl.top() + 1;
        sl.push(i);
    }

    for(int i=heights.size()-1 ; i>=0 ; --i){
        while(!sr.empty() && heights[sr.top()]>=heights[i]){
            sr.pop();
        }
        if(!sr.empty())  r[i] = sr.top()-1;
        sr.push(i);
        if(res < heights[i]*(r[i]-l[i]+1))  res = heights[i]*(r[i]-l[i]+1); 
    }
    return res;
}

int main(){
    vi h = {2,1,5,6,2,3};
    cout << largestRectangleArea(h);
    return 0;
}