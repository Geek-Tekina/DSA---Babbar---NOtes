#include <iostream>
#include "node.h"
using namespace std;

int d1 = 6,d2 = 3; 

node* lca(node* root){
    if(!root)   return NULL;
    if(d1 > root->data && d2 > root->data)  return lca(root->right);
    else if(d1 < root->data && d2 < root->data)  return lca(root->left);
    return root;
}

int main(){
    node* root = new node(10);
    root->left = new node(4);
    root->left->left = new node(3);
    root->left->right = new node(8);
    root->left->right->left = new node(6);
    root->left->right->right = new node(9);
    root->right = new node(13);
    
    cout << lca(root)->data;
    return 0;
}