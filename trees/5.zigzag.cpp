#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
- use level order `queue` logic to get the nodes level wise,
- but use a toggler to see whether to store in revserse order or not
- use a nested while loop of current level's size to iterate over only till this level nodes
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

void zigzag(node* root){
    queue<node*> q;
    q.push(root);
    bool flag = true;
    while(!q.empty()){
        int this_level_size = q.size();
        vector<int> v;
        while(this_level_size--){
            node* temp = q.front();
            v.push_back(temp->data);
            q.pop();
            if(temp->left)  q.push(temp->left);
            if(temp->right)  q.push(temp->right);
        }
        if(flag){
            for(int i=0 ; i<v.size() ; ++i)
                cout << v[i] << " ";
        } else {
            for(int i=v.size()-1 ; i>=0 ; --i)
                cout << v[i] << " ";
        }
        flag = !flag;
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
    /*
                 1
              2    6
               3     7
             4   5
    */
    zigzag(root);
    return 0;
}