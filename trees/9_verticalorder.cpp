#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include "node.h"
using namespace std;

void verticalorder(node* root){
    if(!root)   return;
    map<int, vector<int>> mp;
    queue<node*> q;
    root->hd = 0;
    q.push(root);
    while(!q.empty()){
        node* temp = q.front();
        mp[temp->hd].push_back(temp->data);
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
    for(auto it:mp){
        cout << "for " << it.first << " nodes are ";
        for(int i=0 ; i<it.second.size() ; ++i){
            cout << it.second[i] << " ";
        }
        cout << "\n";
    }
}

int main(){
    node* root = init();
    verticalorder(root);
    return 0;
}