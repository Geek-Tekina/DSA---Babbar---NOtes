#include <iostream>
#include <vector>
using namespace std;

void heapifyTopDown(vector<int> &arr, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest]) largest = l;
    if (r < n && arr[r] > arr[largest]) largest = r;

    // if largest is not root, else leave
    if (largest != i) {
        swap(arr[i], arr[largest]);
        // Recursively heapify the affected sub-tree
        heapify(arr, largest);
    }
}

void buildHeap(vector<int> &arr){
    int last_non_leaf_index = (arr.size()-1)/2;
    while(last_non_leaf_index >= 0){
        heapifyTopDown(arr, last_non_leaf_index);
        last_non_leaf_index--;
    }
}

void deletion(vector<int> &arr){
    int n = arr.size();
    swap(arr[0], arr[n-1]);
    arr.pop_back();
    heapifyTopDown(arr, 0);
}

// ---------

void heapifyBottomUp(vector<int> &arr, int i){
    int parent = (i-1)/2;
    // max heap
    if(arr[i] > arr[parent]){
        swap(arr[i], arr[parent]);
        heapifyBottomUp(arr, parent);
    }
}

void insertion(vector<int> &arr, int value){
    arr.push_back(value);
    heapifyBottomUp(arr, arr.size()-1);
}

void printHeap(vector<int> &arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    vector<int> arr = {10, 9, 8, 15, 17};

    printHeap(arr);
    buildHeap(arr);
    printHeap(arr);
    insertion(arr, 12);
    printHeap(arr);
    deletion(arr);
    printHeap(arr);

    return 0;
}