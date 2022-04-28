#include <iostream>
#include <vector>
#include <queue>
#include "node.h"
using namespace std;

/*
in traversal L-R is fixed is always, only the position of Middle is detrmined.
preorder -> middle will be pre-written and then LR
postorder -> middle will be post written after LR
inorder-> Middle will be in between LR ie LMR.  
level-order -> a queue is maintained such that front stores current level nodes 
    and rear nodes are next level nodes if present and since queue is popped from front
    current level nodes are printed and then their children are pushed at the end 
    of the queue making it traversing level wise.
    A while loop is iterated until queue becomes empty.  
*/

void preorder(node* root){
    if(root == NULL)    return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node* root){
    if(root == NULL)    return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void inorder(node* root){
    if(root == NULL)    return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void levelorder(node* root){
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        root = q.front();
        q.pop();
        cout << root->data << " ";
        if(root->left != NULL) q.push(root->left);
        if(root->right != NULL) q.push(root->right);
    }
}

int main(){
    node* root = new node(1);
    root->left = new node(2);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right = new node(3);
    
    preorder(root);
    cout << endl;
    postorder(root);
    cout << endl;
    inorder(root);
    cout << endl;
    levelorder(root);
    return 0;
}