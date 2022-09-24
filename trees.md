### Introduction of Trees
- creating constructor is important in order to assign NULL values and memory block to child pointers and the pointer itself.
    ```cpp
    class node {
        public: 
            int data;
            node* left;
            node* right;
    
        node(int val){
            data = val;
            left = NULL;
            right = NULL;
        }
    };
    ```
- **vector to Binary Tree or Input** : Its better to return a `node*` while creating the Binary Tree and finally get the root element like this `node* headPtr = input()`. checkout full code [@input_recursion.cpp](trees/1_input_rec.cpp) or [@input_level.cpp](trees/2_input_level.cpp)


### Standard Problems of Binary Tree 
- **Ordered Traversal of Binary Tree**
    ```md
    in traversal L-R is fixed always, only the position of Middle is detrmined.
    - preorder -> middle will be pre-written and then LR
    - postorder -> middle will be post written after LR
    - inorder-> Middle will be in between LR ie LMR.  
    - level-order -> a queue is maintained such that front stores current level nodes 
        and rear nodes are next level nodes if present and since queue is popped from front current level nodes are printed and then their children are pushed at the end of the queue making it traversing level wise. A `while loop` is iterated until queue becomes empty.  
    ```
- [Boundary Traversal](trees/4_boundary_traversal.cpp)
    ```markdown
    the whole problem is divided into 4 parts - root, leftB, leafB, rightB
        - root can be printed simply at the beginning
        - left Boundary : can be printed by traversing left child and if not present then right child, but if both are not present then its a leaf node hence do not print it. print the node data only if either of the child is present because then only its not a leaf.
        - leaf Boundary : leaf nodes are those that neither have left nor right nodes and hence that is only checked along with recursion.
        - right Boundary : first problem is to get the right boundary in reverse order which can be easily solved by first recursing and then printing the data. second thing is to iterate use the `leftB` logic only, first check the right element if not  present then left node.
    ```
- [Zigzag Traversal](trees/5_zigzag.cpp)
    ```markdown
    - use level order `queue` logic to get the nodes level wise,
    - but use a toggler to see whether to store in revserse order or not
    - use a nested while loop of current level's size to iterate over only till this level nodes
    ```
- [Vertical order of binary tree](trees/9_verticalorder.cpp) : 
    - for vertical order, firstly horizontal distance `hd` is maintained in class node {..}
    - whole array is traversed `level-wise using queue`
    - nodes with similar hd are pushed back together with the help of `map<int, vector<int>>`
- [Views of a Binary Tree](trees/10_views.cpp)
- [Height of the tree](trees/6_height.cpp) : recursively add +1 to height of left and right subtree and compare which is bigger. 
- Diameter of the tree : 
    - lets say a root node is a center node if the diameter pass through it and we know that any node can be a center node, hence we will apply recursion on every left and right subtree to see if its a center node, and for any root node to be a center node, just find the height of left subtree and right tree and add 1 to it (counting current node too). but this method takes o(n2) and we are finding height of the same node n times. (full explanation @gfg)
    - optimised solution will be to have a different variable answer, and everytime we find the height of a subtree just check if ans is bigger or `1+lh+rh`, and then just return its height ie `max(lh,rh)` answer here at [trees/diameter](trees/7_diameter.cpp)
    - [youtube explanation](https://www.youtube.com/watch?v=Toe0UQMWhjM)
    - [geeksforgeeks.com](https://www.geeksforgeeks.org/diameter-of-a-binary-tree/)


## Standard Problems for BST 
- **Preorder to BST** - using range of values
- **LevelOrder to BST** - use queue and push nodes [read here](trees/15_bst_from_level.cpp)
- **[Preorder and Inorder to BST](trees/12_preorder_inorder.cpp)** - use map to find the index
- **Binary Tree to BST** - inorder traversal, sort list and copy
- **sorted list to BST** - use createTree(ptr, idx/2) for left and createTree(ptr, n-idx/2-1) for right [read here](trees/17_ll_to_bst.cpp)
- **Count unique BST for n nodes** - catalan number 
- **Merge two BST** - find the two sorted vectors, merge them using single pass merge sort. Then, __sorted list to BST__


### Misc Problems BT
- [Mirrored Tree](trees/11_mirrored.cpp)
- [Replace node with depth](trees/8_replacenode_with_depth.cpp)
- [Pair Sum](https://www.techiedelight.com/find-pair-with-given-sum-bst/) : use hashmap for o(n) time complexity
- [Binary tree from parent array](trees/13_from_parent_array.cpp)
- LCA of Binary Tree - there are four cases just remember them
    - if (root is null) return null
    - if (root is p or root is q) return root
    - for left and right (recursively called answer), if left null then right, if right null then left
    - hence automatically, if both left and right are not null then return root (this means we found one-one element in both the subtrees and hence this nodee is LCA, now further lca node will be either in just right or left, thus it will be the answer only)
- **Time To Burn Tree**
- **Subtree of another Tree** - for each node, check if the subtree is same or not
- **Max Element in the Path** 
    - find LCA, then find max in left and right subtree ( from lca node to the p/q) [read here](https://www.geeksforgeeks.org/maximum-element-two-nodes-bst/)
    - preorder and then find indices of p and q, then find max in the range of indices MIGHT work but extra space is required
- **Distance between two nodes**
- **Leaves on level apart** - find maxLevel and minLevel and then check if there difference is 1 or not


### Misc Questions BST
- **Partial BST** - inorder and then `return is_sorted(inorder.begin(), inorder.end())`
- **[BST to Greater Sum Tree](https://leetcode.com/problems/convert-bst-to-greater-tree/)** - the logic is to go to the right-most child first and then add "sum" (initialside with 0) to its node->val and also update sum with the same
    ```cpp
    // - for any node, go to right child
    // - then sum += node->val and node->val = sum
    // - now just go to left child 
    int sum=0;
    TreeNode* convertBST(TreeNode* node) {
        if(node == NULL)    return 0;
        convertBST(node->right);
        sum += node->val;
        node->val = sum;
        convertBST(node->left);
        return node;
    }
    ```
- [Fix BST/ Recover BST](trees/19_fix_bst.cpp)
    ```
    in this question, two values are swapped and rest everything is fine.
    approach - there can be two cases, that either the anamoly nodes are adjacent and either they are far away. 
    what we can do is maintain prev node and while traversing inorder, if prev->data is smaller than root->data, then we know its an anamoly and if this is first anamoly ie if(first == NULL).. then point first to prev and second to root.
    but if !first, then just second = root
    and at last just swap their data
    ```
- [k-th largest element](https://www.geeksforgeeks.org/kth-largest-element-in-bst-when-modification-to-bst-is-not-allowed/) - keep in order traversal and maintan a ++counter, when counter == k, then return the node->data