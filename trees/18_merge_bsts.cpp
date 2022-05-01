#include <iostream>
#include <vector>
#include <queue>
#include "node.h"
using namespace std;

void toQ(node* root, queue<int> &in){
    if(!root) return;
    toQ(root->left, in);
    in.push(root->data);
    toQ(root->right, in);
}

node* create(queue<int> &mergedInorder, int n){
    if(n<=0)    return NULL;
    node* left = create(mergedInorder, n/2);
    node* root = new node(mergedInorder.front());
    mergedInorder.pop();
    root->left = left;
    root->right = create(mergedInorder, n - n/2 - 1);
    return root;
}

node* merge(node* root1, node* root2){
    queue<int> in1, in2;
    toQ(root1, in1);
    toQ(root2, in2);
    queue<int> mergedInorder;

    // if both false then only exit
    while(!in1.empty() || !in2.empty()){
        if(!in1.empty() && !in2.empty()){
            if(in1.front() < in2.front()){
                mergedInorder.push(in1.front());
                in1.pop();
            } else {
                mergedInorder.push(in2.front());
                in2.pop();
            }
        } else if (in2.empty()) {
            mergedInorder.push(in1.front());
            in1.pop();
        } else {
            mergedInorder.push(in2.front());
            in2.pop();    
        }
    }

    // from sorted list to bst
    return create(mergedInorder, mergedInorder.size());
}

int main(){
    node* root1 = new node(8);
    root1->left = new node(2);
    root1->left->left = new node(1);
    root1->right = new node(10);

    node* root2 = new node(5);
    root2->left = new node(3);
    root2->left->left = new node(0);

    node* merged = merge(root1, root2);
    inorder(merged);
    return 0;
}