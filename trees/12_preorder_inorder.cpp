#include <iostream>
#include <vector>
#include <unordered_map>
#include "node.h"
using namespace std;

char in[] = { 4, 2, 5, 1, 6, 3 };
char pre[] = { 1, 2, 4, 5, 3, 6 };
int len = 6;
int index = 0;
unordered_map<int, int> mp;

node* buildTree(int start,int end){
    // start and end is here to track the subtree part
    // in which we know preorder first element is root
    if(start>end)   return NULL;
    node* root = new node(pre[index++]);
    if(start == end)    return root;

    // now we find the same element position in inorder to find new subtrees.
    int inorder_checkpoint = mp[root->data];
    root->left = buildTree(start, inorder_checkpoint - 1);
    root->right = buildTree(inorder_checkpoint + 1, end);
    return root;
}

node* buildTreeWrap(){
    // so that we wont have to search the whole array to find the index of required node
    for(int i=0 ; i<len ; ++i)
        mp[in[i]] = i;
    return buildTree(0, len-1);
}

int main(){
    node* root = buildTreeWrap();
    preorder(root);
    return 0;
}