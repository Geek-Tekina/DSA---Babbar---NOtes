## Trees
- **for Reff** : https://dynalist.io/d/8JunO-H3ZxPg9wDul58ouDMS
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
- **vector to Binary Tree or Input** : Its better to return a `node*` while creating the Binary Tree and finally get the root element like this `node* headPtr = input()`. checkout full code [@input_recursion.cpp](trees/1.input_rec.cpp) or [@input_level.cpp](trees/2.input_level.cpp)
- **Ordered Traversal of Binary Tree**
    ```md
    in traversal L-R is fixed always, only the position of Middle is detrmined.
    - preorder -> middle will be pre-written and then LR
    - postorder -> middle will be post written after LR
    - inorder-> Middle will be in between LR ie LMR.  
    - level-order -> a queue is maintained such that front stores current level nodes 
        and rear nodes are next level nodes if present and since queue is popped from front current level nodes are printed and then their children are pushed at the end of the queue making it traversing level wise. A `while loop` is iterated until queue becomes empty.  
    ```
- [Boundary Traversal](trees/4.boundary_traversal.cpp)
    ```markdown
    the whole problem is divided into 4 parts - root, leftB, leafB, rightB
        - root can be printed simply at the beginning
        - left Boundary : can be printed by traversing left child and if not present then right child, but if both are not present then its a leaf node hence do not print it. print the node data only if either of the child is present because then only its not a leaf.
        - leaf Boundary : leaf nodes are those that neither have left nor right nodes and hence that is only checked along with recursion.
        - right Boundary : first problem is to get the right boundary in reverse order which can be easily solved by first recursing and then printing the data. second thing is to iterate use the `leftB` logic only, first check the right element if not  present then left node.
    ```
- [Zigzag Traversal](trees/5.zigzag.cpp)
    ```markdown
    - use level order `queue` logic to get the nodes level wise,
    - but use a toggler to see whether to store in revserse order or not
    - use a nested while loop of current level's size to iterate over only till this level nodes
    ```