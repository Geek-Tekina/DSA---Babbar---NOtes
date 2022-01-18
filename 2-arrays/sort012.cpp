#include <iostream>
#include<vector>
using namespace std;

int main()
{
    // vector<int> v {1,4,4,5,3};
    int arr[] = {0,1,0,2};
    int n = 4;
    vector<int> v0,v1,v2;
    for(int i=0;i<n ; i++){
        if(arr[i]==0)  v0.push_back(0);
        else if (arr[i]==1) v1.push_back(1);
        else v2.push_back(2);
    }
    for(auto i:v0) cout<< i << " ";
    for(auto i:v1) cout<< i << " ";
    for(auto i:v2) cout<< i << " ";
    return 0;
}
