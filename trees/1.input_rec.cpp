#include <iostream>
#include <vector>
#include "node.h"
using namespace std;

int i = -1;
vector<int> v = {1,2,-1,-1,3,4,-1,-1,-1};

node* input(){
    int temp = v[++i];      // cin >> temp;
    if(temp == -1)  return NULL;
    else {
        node* root = new node(temp);
        root->left = input();
        root->right = input();
        return root;
    }
}

void preorder(node* root){
    if(root == NULL)    return;
    cout << root->data;
    preorder(root->left);
    preorder(root->right);
}

int main(){
    node* headPtr = input();
    // headPtr =  new node(1);
    // headPtr->left =  new node(2);
    // headPtr->left->left =  new node(4);
    // headPtr->right =  new node(3);
    /*
           1
          / \
         2   3
        / \  
       4
    */
    preorder(headPtr);
    return 0;
}