#include <iostream>
#include <vector>
using namespace std;

int main(){
    int arr[] = {3,3,9,2};
    int n = sizeof(arr)/sizeof(int);
    if(arr[0]==0)   return -1;
    int count=1,cr=0;

    while(cr<n){
        int tempSteps = cr + arr[cr];
        if(arr[cr] == 0)    return -1;
        if(tempSteps >= n-1) {
            count++;
            break;
        }
        int tempMax = arr[cr+1];
        for(int i=cr+1 ; i<=tempSteps && i<n ; i++){
            if(arr[tempMax] < arr[i]){
                tempMax = i;
            }    
        }
        cr = tempMax;
        count++;
    }
    cout << count;
    return 0;
}