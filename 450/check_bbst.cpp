#include <iostream>
#include <vector>
using namespace std;

bool balanced = true;
int findHeight(Node *root){
    if(root == NULL)
        return 0;
    int left = findHeight(root->left);
    int right = findHeight(root->right);
    if(abs(left - right) > 1)
        balanced = false;
    return max(left, right) + 1;
}

int main(){
    // Node *root = new Node(1); ...
    findHeight(root);
    cout << (balanced ? "Balanced" : "Not Balanced") << endl;
    return 0;
}