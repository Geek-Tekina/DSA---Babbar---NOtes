#include <iostream>
#include <vector>
using namespace std;

void nextPermutation(vector<int> arr){
    // find decreasing seq
    // mark pivot that is i+1
    // find next greater element to the pivot 
    // replace this nge and pivot
    // reverse the array from pivot+1 to end
    
    int i = arr.size()-2;
    while(i>=0 && arr[i] >= arr[i+1]) --i;
    if(i < 0){
        reverse(arr.begin(), arr.end());
        return;
    }
    int j = arr.size()-1;
    while(j>=0 && arr[j] <= arr[i]) --j;
    swap(arr[i], arr[j]);
    reverse(arr.begin()+i+1, arr.end());
}

int main(){
    vector<int> arr = {1, 2, 3};
    nextPermutation(arr);
    for(int i=0 ; i<arr.size() ; ++i)
        cout << arr[i] << " ";
    return 0;
}
