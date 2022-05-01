#include <iostream>
#include <climits>
#include "node.h"
using namespace std;
node* first, *second, *prev;

void inorderFix(node* root){
    if(!root)   return;
    inorderFix(root->left);
    if(root->data < prev->data){
        if(!first){
            first = prev;
            second = root;
        }
        else second = root;
    }
    prev = root;  // v imp
    inorderFix(root->right);
}

void fix(node* root){
    first = second = NULL;
    prev = new node(INT_MIN);
    inorderFix(root);
    swap(first->data, second->data);
}


int main(){
    node* root = new node(3);
    // ...
    inorder(root);
    cout << "\n";
    fix(root);
    inorder(root);
    return 0;
}