#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include "node.h"
using namespace std;

int parent[] =  {-1, 0, 0, 1, 1, 3, 5};
int n = sizeof parent / sizeof parent[0];

/*
    here solve the pattern first you will know that 
    "index" of -1 lets say x, is always root
    now indices of this value x, are left and right children and further
    hence we are finding the indices, from array values, so create a map<int, vector<int>>
    now create root, and level order to create the binary tree
*/

node* createTree(){
    unordered_map<int, vector<int>> mp;
    for(int i=0 ; i<n ; ++i)
        mp[parent[i]].push_back(i);
    
    node* root = new node(mp[-1][0]);
    queue<node*> q;
    q.push(root);
    while (!q.empty()){
        node* temp = q.front();
        vector<int> subvec = mp[temp->data]; 
        q.pop(); 
        if(subvec.size() >= 1){
            node* left = new node(subvec[0]);
            temp->left = left; 
            q.push(left);
        }
        if(subvec.size() == 2){
            node* right = new node(subvec[1]);
            temp->right = right; 
            q.push(right);
        }
    }
    
    return root;
}

int main(){
    node* root = createTree();
    inorder(root);
    return 0;
}