#include <iostream>
#include <vector>
#include "node.h"
using namespace std;

class llnode{
    public:
        int data;
        llnode* next;
        llnode(int val){
            data = val;
        }
};

// first left subtree is recursived till we get to a leaf
// then we make the left child (which is NULL)
// then we make the leaf itself  node* root = new node((*h)->data);
// and then we move the head ptr one step further
// and now generate the right child (which is also NULL for first time)
// but now as this method is removed from call stak, this becomes left subtree
// and then we again create a node and create right subtree.

node* create(llnode** h, int n){
    if(n<=0)    return NULL;
    node* left = create(h, n/2);
    node* root = new node((*h)->data);
    root->left = left;
    (*h) = (*h)->next;
    root->right = create(h, n - n/2 - 1);
    return root;
}

int main(){
    llnode* head = new llnode(1);
    llnode* temp = head;
    for(int i=0 ; i<6 ; ++i){
        temp->next = new llnode(i+2);
        temp = temp->next;
    }
    int n=7;
    node* root = create(&head, n);
    preorder(root);
    return 0;
}