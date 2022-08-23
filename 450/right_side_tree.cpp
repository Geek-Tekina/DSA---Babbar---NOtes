#include <iostream>
#include <vector>
#include "node.h"
using namespace std;
typedef node TreeNode;

int maxLevel = -1;
void rightView(TreeNode* root, vector<int> &list, int level){
    if(!root)   return;
    if(level > maxLevel) {
        list.push_back(root->data);
        maxLevel = level;
    }
    rightView(root->right, list, level + 1);
    rightView(root->left, list, level + 1);
}

int main(){
    TreeNode* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->right = new node(5);
    root->right->right = new node(4);
    inorder(root);
    cout << "\n";

    vector<int> list = {};
    rightView(root, list, 0);
    
    for(auto i : list)   cout << i << " ";
    return 0;
}