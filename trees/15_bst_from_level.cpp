#include <iostream>
#include <vector>
#include <queue>
#include "node.h"
using namespace std;

node* constructBst(vector<int>& levelOrders){
    queue<node*> q;
    node* root = new node(levelOrders[0]);
    int i=1;
    q.push(root);
    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        if( i<levelOrders.size() &&  levelOrders[i] < temp->data){
            temp->left = new node(levelOrders[i]);
            ++i;
            q.push(temp->left);
        }
        if(i<levelOrders.size() && levelOrders[i] > temp->data){
            temp->right = new node(levelOrders[i]);
            ++i;
            q.push(temp->right);
        }
    }
    return root;
}

int main(){
    vector<int> inp = {16, 14, 82, 21, 156};
    node* root = constructBst(inp);
    inorder(root);
    return 0;
}