#include <iostream>
#include <vector>
#include "node.h"
using namespace std;

void mirror(node* root){
    if(!root)   return;
    node* temp = root->left;
    root->left = root->right;
    root->right = temp;
    mirror(root->left);
    mirror(root->right);
}

int main(){
    node* root = init();
    preorder(root);
    cout << "\n";
    mirror(root);
    preorder(root);
    return 0;
}