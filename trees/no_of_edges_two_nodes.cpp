#include <iostream>
#include <vector>
#include "node.h"
using namespace std;

node* findlca(node* root, int n1, int n2){
    if(root == NULL)    return NULL;
    if(root->data == n1 or root->data == n2) 
        return root;

    node* l = findlca(root->left, n1, n2);
    node* r = findlca(root->right, n1, n2);
    if(l == NULL) return r;
    if(r == NULL) return l;
    return root;
}

int x1 = 0;
int x2 = 0;
int findParentToChildEdge(node* parent, int x, int count, int &var){
    if(parent == NULL)  return 0;
    if(parent->data == x) var = count;
    else {
        findParentToChildEdge(parent->left, x, count+1, var);
        findParentToChildEdge(parent->right, x, count+1, var);
    }
}

int main(){
    node* root = init();
    node* center = findlca(root, 5, 4);
    cout << center->data << endl;
    findParentToChildEdge(center, 5, 0, x1);
    findParentToChildEdge(center, 4, 0, x2);
    cout << x1 + x2 << endl;
    return 0;
}