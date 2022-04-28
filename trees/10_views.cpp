#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include "node.h"
using namespace std;

int maxlevel_L = 0;
int maxlevel_R = 0;
void left(node* root, int level){
    if(!root)   return;
    if(maxlevel_L < level){
        maxlevel_L = level;
        cout << root->data << " ";
    }
    left(root->left, level+1);
    left(root->right, level+1);
}

void right(node* root, int level){
    if(!root)   return;
    if(maxlevel_R < level){
        maxlevel_R = level;
        cout << root->data << " ";
    }
    right(root->right, level+1);
    right(root->left, level+1);
}

void top(node* root){
    map<int, int> mp;           // to store in sorted way and if sorted or not
    queue<node*> q;
    root->hd = 0;
    q.push(root);
    while(!q.empty()){
        node* temp = q.front();
        // if a node is already seen on top then dont override
        if(mp.count(temp->hd) == 0 )
            mp[temp->hd] = temp->data;

        q.pop();
        if(temp->left != NULL){
            temp->left->hd = temp->hd - 1;
            q.push(temp->left);
        }
        if(temp->right != NULL){
            temp->right->hd = temp->hd + 1;
            q.push(temp->right);
        }
    }
    for(auto it:mp)
        cout << it.second << " ";
}

void bottom(node* root){
    map<int, int> mp;         
    queue<node*> q;
    root->hd = 0;
    q.push(root);
    while(!q.empty()){
        node* temp = q.front();
        // unlike top view, override the map value to get bottom view
        mp[temp->hd] = temp->data;
        q.pop();
        if(temp->left != NULL){
            temp->left->hd = temp->hd - 1;
            q.push(temp->left);
        }
        if(temp->right != NULL){
            temp->right->hd = temp->hd + 1;
            q.push(temp->right);
        }
    }
    for(auto it:mp)
        cout << it.second << " ";
}

int main(){
    node* root = init();
    left(root, 1);
    cout << "\n";
    right(root, 1);
    cout << "\n";
    top(root);
    cout << "\n";
    bottom(root);
    return 0;
}