#include <iostream>
#include <vector>
using namespace std;

/*
the whole problem is divided into 4 parts - root, leftB, leafB, rightB
- root can be printed simply at the beginning
- left Boundary : can be printed by traversing left child and if not present then right child,
    but if both are not present then its a leaf node hence do not print it. print the node data
    only if either of the child is present because then only its not a leaf.
- leaf Boundary : leaf nodes are those that neither have left nor right nodes 
    and hence that is only checked along with recursion.
- right Boundary : first problem is to get the right boundary in reverse order which can be 
    easily solved by first recursing and then printing the data. second thing is to iterate use the `leftB`
    logic only, first check the right element if not present then left node.
*/

class node {
    public:
    int data;
    node *left, *right;
    node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

void leftb(node* root){
    if(root == NULL)    return;
    if(root->left != NULL){
        cout << root->data << " ";
        leftb(root->left);
    } else if (root->right != NULL){
        cout << root->data << " ";
        leftb(root->right);
    }
}

void leaf(node* root){
    if(root == NULL) return;
    leaf(root->left);
    if(root->left == NULL and root->right == NULL)   cout << root->data << " ";
    leaf(root->right);
}

void rightB(node* root){
    if(root == NULL) return;
    if(root->right != NULL) {
        rightB(root->right);
        cout << root->data << " ";
    } else if(root->left != NULL){
        rightB(root->left);
        cout << root->data << " ";
    }
}

int main(){
    node* root = new node(1);
    root->left = new node(2);
    root->left->right = new node(3);
    root->left->right->left = new node(4);
    root->left->right->right = new node(5);
    root->right = new node(6);
    root->right->right = new node(7);
    // root->right = new node(3);
    /*
                 1
              2    6
               3     7
             4   5
    */
    cout << root->data << " ";
    leftb(root->left);
    leaf(root);
    rightB(root->right);
    return 0;
}