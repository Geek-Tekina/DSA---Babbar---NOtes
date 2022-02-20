#include <iostream>
#include <vector>
using namespace std;

int main(){
    int a[] = {1,2,3,4};
    int n = sizeof(a)/sizeof(int);
    int mid = n/2;
    int temp;
    for(int i=0 ; i<mid ; i++){
        temp = a[i];
        a[i] = a[n-1-i];
        a[n-1-i] = temp;
    }
    for(int i:a)   cout << i << " ";
    return 0;
}