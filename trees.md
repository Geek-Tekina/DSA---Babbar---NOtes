- **for Reff** : https://dynalist.io/d/8JunO-H3ZxPg9wDul58ouDMS
## BInary Trees
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
- Misc Questions
    - [Mirrored Tree](trees/11_mirrored.cpp)
    - [Replace node with depth](trees/8_replacenode_with_depth.cpp)
    - [Binary tree from preorder and inorder](trees/12_preorder_inorder.cpp)
    - [Binary tree from parent array](trees/13_from_parent_array.cpp)
    - !! LCA of Binary Tree
    - !! Time To Burn Tree

<hr>

## BST
for Reff, https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118512/offering/1377942
- Construction of BST
    - [from preorder](https://www.techiedelight.com/build-binary-search-tree-from-preorder-sequence)
    - [from levelorder](trees/15_bst_from_level.cpp)