#include <iostream>
#include <vector>
#include <queue>
using namespace std;

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

/*
here nodes are pushed in the `q` and their front value is used as the root 
element whose left and right nodes are again added at the end of the queue.
and hence first a level is entered and then next level nodes.
note that the node* which is added in the queue is already attached with its parent.
*/

int i=-1;
vector<int> v = {1,2,3,-1,-1,4,-1,-1,-1};

node* input(){
    int temp;
    cin >> temp;
    if(temp == -1)  return NULL;
    node* root = new node(temp);
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* tempNode = q.front(); 
        q.pop();
        cout << tempNode->data << " left : "; 
        cin >> temp;
        if(temp != -1){
            tempNode->left = new node(temp);
            q.push(tempNode->left);
        }
        cout << tempNode->data << " right : "; 
        cin >> temp;
        if(temp != -1){
            tempNode->right = new node(temp);
            q.push(tempNode->right);
        }
    }
    return root;
}

void preorder(node* root){
    if(root == NULL)    return;
    cout << root->data;
    preorder(root->left);
    preorder(root->right);
}

int main(){
    node* headPtr = input();
    // headPtr =  new node(1);
    // headPtr->left =  new node(2);
    // headPtr->right =  new node(3);
    // headPtr->right->left =  new node(4);
    /*
           1
          / \
         2   3
            / \  
           4
    */
    preorder(headPtr);
    return 0;
}