#include<iostream>
using namespace std;

class node {
    public: 
        int data;
        node *left, *right;
        // only for vertical orderes, topview and bottomview
        int hd;

    node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

void preorder(node* root){
    if(!root)   return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(node* root){
    if(!root)   return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(node* root){
    if(!root)   return;
    preorder(root->left);
    preorder(root->right);
    cout << root->data << " ";
}

node* init(){
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    return root;
}