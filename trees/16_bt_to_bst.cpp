#include <iostream>
#include <vector>
#include <algorithm>
#include "node.h"
using namespace std;

int index=0;
vector<int> vec;

void inorderVector(node* root){
    if(!root)   return;
    inorderVector(root->left);
    vec.push_back(root->data);
    inorderVector(root->right);
}

void inorderVectorCopy(node* root){
    if(!root)   return;
    inorderVectorCopy(root->left);
    root->data = vec[index++];
    inorderVectorCopy(root->right);
}

void convert(node* root){
    inorderVector(root);
    sort(vec.begin(), vec.end());
    inorderVectorCopy(root);
}

int main(){
    node* root = new node(5);
    root->left = new node(6);
    root->right = new node(10);
    root->left->left = new node(2);
    root->left->right = new node(3);
    root->right->right = new node(9);

    inorder(root);
    cout << "\n";
    convert(root);
    inorder(root);
    return 0;
}