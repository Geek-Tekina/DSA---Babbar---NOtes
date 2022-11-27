#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int> &arr, int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    // if largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
    // but if largest is actually already the root, 
    // then we don't need to do anything 
}

void buildHeap(vector<int> &arr, int n){
    int last_non_leaf_index = (n-1)/2;
    while(last_non_leaf_index >= 0){
        heapify(arr, n, last_non_leaf_index);
        last_non_leaf_index--;
    }
}

void insertion(vector<int> &arr, int n, int value){
    ++n;
    arr.push_back(value);
    int parent_of_this_new_node_index = (n-1)/2;
    heapify(arr, n, parent_of_this_new_node_index);
}

void deletion(vector<int> &arr, int n){
    swap(arr[0], arr[n-1]);
    arr.pop_back();
    n--;
    heapify(arr, n, 0);
}

void printHeap(vector<int> &arr, int n){
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    vector<int> arr = {10, 9, 8, 15, 17};

    printHeap(arr, arr.size());
    buildHeap(arr, arr.size());
    printHeap(arr, arr.size());
    insertion(arr, arr.size(), 12);
    printHeap(arr, arr.size());
    deletion(arr, arr.size());
    printHeap(arr, arr.size());

    return 0;
}