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

void solve(TreeNode *root, string &str){
    if(root == NULL)    return;
    if(root->left == NULL && root->right == NULL){
        str += to_string(root->val);
        return;
    }       
    str += to_string(root->val);
    str += "(";
    solve(root->left, str);
    str += ")";
    if(root->right != NULL){
        str += "(";
        solve(root->right, str);
        str += ")";
    }
}

string tree2str(TreeNode *root){
    string str = "";
    solve(root, str);
    return str;
}

int main(){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4); // right 1(2()(4))(3)
    // root->left->left = new TreeNode(4);     // 1(2(4))(3)
    cout << tree2str(root) << endl;
    return 0;
}