#include <iostream>
#include "node.h"
using namespace std;

void replace(node* root,int d){
    if(!root)   return;
    root->data = d;
    replace(root->left, d+1);
    replace(root->right, d+1);
}

int main(){
    node* root = init();
    preorder(root);
    cout << "\n";
    replace(root, 0);
    preorder(root);
    return 0;
}