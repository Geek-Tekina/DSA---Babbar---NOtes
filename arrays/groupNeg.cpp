#include<bits/stdc++.h>
using namespace std;

int main(){
    int a[] = {-2,-5,5,-3,10,0,-7};
    int n = sizeof(a)/sizeof(int);
    int pivot;
    for(int i=0; i<n ; i++){
        if(a[i]>=0){
           pivot = i;
           break; 
        }
    }
    for(int i=pivot+1;i<n ; i++){
        if(a[i]<0){
            swap(a[i],a[pivot]);
            pivot = i;
        }
    }
    for(auto i:a)   cout << i << " "; 
    return 0;
}