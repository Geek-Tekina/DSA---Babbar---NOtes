#include <iostream>
#include <vector>
#include <map>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef map<int, vi> mapiv;

class TreeNode {
    public:
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void solve(TreeNode *root, int hd, mapiv &res){
    if(root == NULL)    return;
    res[hd].push_back(root->val);
    solve(root->left, hd-1, res);
    solve(root->right, hd+1, res);
}

vector<vector<int>> verticalTraversal(TreeNode* root) {
    mapiv mp;
    vvi res;
    solve(root, 0, mp);
    for(auto it = mp.begin(); it != mp.end(); it++){
        res.push_back(it->second);
    }
    return res;
}

int main(){
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    vvi output = verticalTraversal(root);
    for(auto it = output.begin(); it != output.end(); it++){
        for(auto it2 = it->begin(); it2 != it->end(); it2++){
            cout << *it2 << " ";
        }
        cout << endl;
    }
    return 0;
}