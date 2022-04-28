#include <iostream>
#include <vector>
#include "node.h"
#include <climits>
using namespace std;

int preindex = 0;
vector<int> arr = {4,2};

node* createbst(int min, int max){
    if(preindex == arr.size()) return NULL;
    if(arr[preindex] < min || arr[preindex] > max)    return NULL;

    node* root = new node(arr[preindex++]);
    root->left = createbst(min, root->data - 1);
    root->right = createbst(root->data + 1, max);
    return root;
}

int main(){
    // need climits for this
    node* root = createbst(INT_MIN, INT_MAX);
    preorder(root);
    return 0;
}