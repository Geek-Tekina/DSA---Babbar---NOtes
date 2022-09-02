#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void inorder(TreeNode* node){
    if(node == nullptr) return;
    inorder(node->left);
    cout << node->val << " ";
    inorder(node->right);
}

int solve(TreeNode* node, int maxValue){
    if(node == NULL)    return 0;
    int count = 0;
    if(node->val >= maxValue)    count = 1;
    int left = solve(node->left, count ? node->val : maxValue);
    int right = solve(node->right, count ? node->val : maxValue);
    return count + left + right;
}

int goodNodes(TreeNode* root){
    return solve(root, root->val);
}

int main(){
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->left->left = new TreeNode(3);
    root->right = new TreeNode(4);
    root->right->right = new TreeNode(1);
    root->right->right = new TreeNode(5);
    inorder(root);
    cout << endl << goodNodes(root) << endl;
    return 0;
}