- **for Reff** : https://dynalist.io/d/8JunO-H3ZxPg9wDul58ouDMS
## Binary Trees
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
- **BST to sorted list? do inroder** [examnple : BT to BST](trees/16_bt_to_bst.cpp)
- **sorted list to BST (if BT given)? any traversal and copy** [examnple : BT to BST](trees/16_bt_to_bst.cpp)
- **sorted list to BST (if BT not given)? construct the BST recursively from left-right and bottom-top aka Pre-Order** [example : Sorted LL to Balanced BST](trees/17_ll_to_bst.cpp)
- Construction of BST
    - Hard, [from preorder](https://www.techiedelight.com/build-binary-search-tree-from-preorder-sequence)
    - [from levelorder](trees/15_bst_from_level.cpp)
    - Count unique BST for n
        ```md
            - lets assume x is root, with l as #leftChild and r as #right.
            - then total# combinations will be Combinations c(l) * c(r)
            - now e.g. 4 is given (1,2,3,4) there will be 4 root nodes cases (root-> left, rght)
                - 1 -> null,234 ; c(0)*c(3)
                - 2 -> 1,34 ; c(1)*c(2)
                - 3 -> 12,4 ; c(2)*c(1)
                - .... and summing up this is basically CATALAN Number.
            - approach : https://www.youtube.com/watch?v=OIc0mHgHUww
            - catalan code : https://www.youtube.com/watch?v=CMaZ69P1bAc&t=0s
        ```
- Conversion Based Problems
    - [BT to BST](trees/16_bt_to_bst.cpp) : Here the inorder is generated from Binary Tree and then it is sorted because now if we will treat this sorted array as inorder, it will help us to copy the values to the given binary search tree. The complexity will be o(nlogn) bec of sorting algorithm. Remember, inorder sorted list is not giving us the Binary Tree here, we are just using the values to modify given Binary Tree and since the list is sorted and we are using inorder (left-mid-right), it will convert the tree to bst.
    - Sorted LL to Balanced BST ; [do check out the code](trees/17_ll_to_bst.cpp) ; [code for merge two bst](trees/18_merge_bsts.cpp)
        ```
        There are three approaches for this
        1. create vector from LL and then recursively find mid and node->left = createBst(start, mid-1) and for right too
        2. Second approach is to find mid from the LL itself, using fast and slow method.
        3. https://www.geeksforgeeks.org/sorted-linked-list-to-balanced-bst/ ; here we are recursively building the BST from l-r and b-t.
        ```
        ```
        1. BST to Balanced BST  - as we know inorder of a BST is nothing but a sorted list. and we can easily convert a sorted list to BBST. so, just find the inorder of BST, and create the tree recursively in in-order manner.
        2. Merge two BST - here, find the two sorted vectors, merge them using single pass merge sort. and now create BBST from sorted list. WHY I CHOSE QUEUE?? because its allows easily popping from front.
        3. BST to Min-Heap - get inorder-sorted-vector from BST and copy to BST in pre-order manner to create Min-Heap. 
        ```
- Standard Problems
    - [Fix BST/ Recover BST](trees/19_fix_bst.cpp)
        ```
        in this question, two values are swapped and rest everything is fine.
        approach - there can be two cases, that either the anamoly nodes are adjacent and either they are far away. 
        what we can do is maintain prev node and while traversing inorder, if prev->data is smaller than root->data, then we know its an anamoly and if this is first anamoly ie if(first == NULL).. then point first to prev and second to root.
        but if !first, then just second = root
        and at last just swap their data
        ```
    - [LCA of BST](trees/20_lca_bst.cpp)
        ```
        In BST, the we can easily track LCA by just checking with the root data, if both the elements are greater then go to right child else if both smaller go to left child else this is the LCA node.
        ```
    - [Pair Sum in BST](https://www.techiedelight.com/find-pair-with-given-sum-bst/)
        ```
        We can easily solve this problem by using hashing. The idea is to traverse the tree in an inorder fashion and insert every node’s value into a set. Also check if, for any node, the difference between the given sum and node’s value is found in the set, then the pair with the given sum exists in the tree.
        ```
    - [k-th largest element](https://www.geeksforgeeks.org/kth-largest-element-in-bst-when-modification-to-bst-is-not-allowed/)
        ```
        keep in order traversal and maintan a ++counter, such that if counter becomes k, return the value. 
        ```