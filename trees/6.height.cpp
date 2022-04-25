#include <iostream>
#include <vector>
#include "node.h"
using namespace std;

int height(node* root){
    if(!root) return 0;
    return max(height(root->left), height(root->right)) + 1;
}

int main(){
    node* root = init();
    cout << "height is " << height(root); 
    return 0;
}