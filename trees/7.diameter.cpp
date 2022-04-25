#include <iostream>
#include "node.h"
using namespace std;
int ans=0;

int height(node* root){
    if(!root)   return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    ans = max(ans, 1+lh+rh);
    return 1 + max(lh, rh);
}

int main(){
    node* root = init();
    height(root);
    cout << "diamete is " << ans; 
    return 0;
}