# trees(binary)//view->ctrl+shift+v

- starts from level 0,no of nodes on any level is 2^l
- height starts from 1,so max nodes in height h is 2^0+...2^(h-1). or 2^h - 1 and min is h
- if n nodes, max height=n, min height = log2(n+1). where if fraction give bigger int
- strict/proper tree= each nodes as 2 or 0 children.
- **complete**= all level except last are filled or if not then nodes at last lvl as left as possible

# complete binary tree
- **Starting at index 0**

>- If a particular node is at index k, then its left child is at index 2k + 1

>- If a particular node is at index k, then its right child is at index 2k + 2

>- If a particular node is at index k, then its parent is at index ceil(k-1/2).gives max int

- **Starting at index 1**

>- If a particular node is at index k, then its left child is at index 2k.

>- If a particular node is at index k, then its right child is at index 2k+1.

>- If a particular node is at index k, then its parent node is at index floor(k/2) gives min int

# BST Class -
>- class BST

Data Members -
1.TreeNode *root

Member Functions
- 1.bool **isTreeEmpty()**                // check if empty
- 2.void **insertNode**(TreeNode *new_node)  //insertion
// depth first traversal approach
- 3a. void **printPreorder**(TreeNode* r)     //print & traverse
- 3b.void **printInorder**(TreeNode* r)       //print & traverse
- 3c.void **printPostorder**(TreeNode* r)     //print & traverse
- 3d. void print2D(TreeNode *r,int space)     //print & traver
// breadth first traversal approach
- 3e. void printLevelOrder(TreeNode *r)       //print & traverse
4. TreeNode* search(TreeNode* r, int v)       // search

- 5a. TreeNode* minValueNode(TreeNode* node)    //delete
- 5b. TreeNode* deleteNode(TreeNode* r, int v)  //delete


# TRAVERSAL

>- 1. **inorder**
- left-> root-> right
- code-- 
- 1. if(null) return
- 2. keep going left until null
- 3. when left hit nulls print that ele(2)
- 4. now go right null again go back to 3 which again prints(3) and now right--null,print,null-go back to 3 which goes back to 5 and so on

-       5
-      / \
-     3   7
-    / \   \
-   2   4   8
>- 2,3,4,5,7,8

Go left all the way (2)

Visit parent (3)

Go right (4)

Visit root (5)

Go right (7), then right again (8)

