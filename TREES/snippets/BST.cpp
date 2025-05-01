#include <iostream>
#include <algorithm>
// binary search tree
#define GlobalSpace 5
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
    Node() : data(0), left(nullptr), right(nullptr) {}
};

class Tree
{
public:
    Node *root;
    Tree() : root(nullptr) {}

    bool isEmpty()
    {
        return root == nullptr;
    }

    void insert(int val)
    {
        Node *newNode = new Node(val);
        if (!root)
        {
            root = newNode;
            return;
        }
        Node *temp = root;
        while (temp != nullptr)
        {
            if (newNode->data == temp->data) // duplicate not allowed
                return;

            else if (newNode->data < temp->data)
            {
                if (temp->left == nullptr)
                {
                    temp->left = newNode;
                    return;
                }

                temp = temp->left;
            }
            else
            {
                if (temp->right == nullptr)
                {
                    temp->right = newNode;
                    return;
                }

                temp = temp->right;
            }
        }
    }
    Node *Insert(Node *node, int val)
    {

        if (node == nullptr)
        {
            Node *newNode = new Node(val);
            return newNode;
        }

        if (val > node->data)
            node->right = Insert(node->right, val);
        else
            node->left = Insert(node->left, val);

        return node;
    }

    Node *Avl_Insertion(Node *node, int val)
    {

        if (node == nullptr)
        {
            Node *newNode = new Node(val);
            return newNode;
        }

        if (val > node->data)
            node->right = Avl_Insertion(node->right, val);

        else if (val < node->data)
            node->left = Avl_Insertion(node->left, val);

        else
        {
            return node;
        }
        int Bf = balanceFactor(node);

        if (Bf > 1 && val < node->left->data)

            return rightRotate(node);

        if (Bf < -1 && val > node->right->data)

            return leftRotate(node);

        if (Bf > 1 && val > node->left->data)
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (Bf < -1 && val < node->right->data)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }
    Node *rightRotate(Node *node)
    {
        Node *temp = node->left;

        node->left = temp->right;
        temp->right = node;

        return temp;
    }
    Node *leftRotate(Node *node)
    {
        Node *temp = node->right;

        node->right = temp->left;
        temp->left = node;

        return temp;
    }

    int balanceFactor(Node *node)
    {

        if (node == nullptr)
        {
            return -1;
        }
        return (Height(node->left) - Height(node->right));
    }

    void printInorder(Node *node) // left subtree-> root-> right subtree
    {
        if (node == nullptr)
        {
            return;
        }

        printInorder(node->left);

        std::cout << node->data << " ";

        printInorder(node->right);
    }

    void preorder(Node *node) // root->left->right
    {
        if (node == nullptr)
        {
            return;
        }
        std::cout << node->data << " ";
        preorder(node->left);

        preorder(node->right);
    }
    void postorder(Node *node) // left->right->root
    {
        if (node == nullptr)
        {
            return;
        }

        postorder(node->left);

        postorder(node->right);
        std::cout << node->data << " ";
    }

    void print2d(Node *node, int space)
    {
        if (node == nullptr)
            return;

        space += GlobalSpace;
        print2d(node->right, space);
        for (int i = GlobalSpace; i <= space; i++)
        {
            std::cout << " ";
        }
        std::cout << node->data << "\n\n";
        print2d(node->left, space);
    }

    Node *Search(int val)
    { // iterative approach,checking left and right everytime,kinda same like binary search in arr
        if (root == nullptr)
            return root;
        Node *temp = root;
        while (temp != nullptr)
        {
            if (val == temp->data)
                return temp;
            if (val > temp->data)
                temp = temp->right;
            else
                temp = temp->left;
        }
        return nullptr;
    }

    Node *search(Node *temp, int val) // recursive approach
    {
        if (temp == nullptr || val == temp->data)
            return temp;

        if (val > temp->data)
            return search(temp->right, val);
        else
            return search(temp->left, val);
    }
    int Height(Node *node)
    {
        if (node == nullptr)
            return -1;
        int Lheight;
        int Rheight;

        Lheight = Height(node->left);

        Rheight = Height(node->right);

        return std::max(Lheight + 1, Rheight + 1);
    }

    void BFS(Node *node)
    {
        for (int i = 0; i <= Height(node); i++)
        {
            printlevel(node, i);
        }

    } // breadth first search,level by level traversal

    void printlevel(Node *node, int lvl)
    { // reach that particular level and print it
        if (node == nullptr)
            return;
        if (lvl == 0)
            std::cout << node->data << " ";
        else
        {
            printlevel(node->left, lvl - 1);
            printlevel(node->right, lvl - 1);
        }
    }

    Node *Delete(Node *node, int val)
    { // scenarios--> leaf node,single vhild,2 child, previous node of del node kept in check thru recursion.
        Node *temp;
        if (node == nullptr)
            return node;

        if (val > node->data)
            node->right = Delete(node->right, val);

        else if (val < node->data)
            node->left = Delete(node->left, val);

        else // when val=node->data;
        {
            if (node->left == nullptr)
            {
                temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr)
            {
                temp = node->left;
                delete node;
                return temp;
            }

            else
            {
                temp = minNode(node->right);
                node->data = temp->data;
                node->right = Delete(node->right, node->data);
            }
        }
        return node;
    }
    Node *minNode(Node *node)
    {

        while (node->left != nullptr)
        {
            node = node->left;
        }
        return node;
    }

    Node *AVL_delete(Node *node, int val)
    {

        if (node == nullptr)
            return node;
        Node *temp = node;

        if (val > node->data)
            node->right = AVL_delete(node->right, val);
        else if (val < node->data)
            node->left = AVL_delete(node->left, val);

        else
        {
            if (node->left != nullptr)
            {

                temp = node->right;
                delete node;
                return temp;
            }
            if (node->right != nullptr)
            {

                temp = node->left;
                delete node;
                return temp;
            }

            else
            {
                temp = minNode(node->right);
                node->data = temp->data;
                node->right = AVL_delete(node->right, temp->data);
            }
        }
       
        int bf=balanceFactor(node);

        if(bf>1 && balanceFactor(node->left)>=0){ 
            return rightRotate(node);
        }
        if(bf>1 && balanceFactor(node->left)==-1){ 
            node->left= leftRotate(node->left);
            return rightRotate(node);
        }
        if(bf<-1 && balanceFactor(node->right)==1){ 
            
            node->right= rightRotate(node->right);
            return leftRotate(node);

        }
        if(bf<-1 && balanceFactor(node->right)<=0){ 
           
            return leftRotate(node);
        }

return node;







    }
};
int main()
{
    Tree t;

    // t.insert(55);
    // t.insert(66);
    // t.insert(77);
    // t.insert(5);
    // t.insert(11);
    // t.insert(3);
    // t.insert(22);
    // t.insert(35);
    // t.insert(25);
     t.root = t.Insert(t.root, 4);

    t.Insert(t.root, 3);
    t.Insert(t.root, 7);
    t.Insert(t.root, 11);
    t.Insert(t.root, 6);
    t.printInorder(t.root);
    std::cout << "\n";
    t.preorder(t.root);
    std::cout << "\n";
    t.postorder(t.root);
    // while (true)
    // {
    //     int i;

    //     std::cin >> i;
    //     t.root = t.Avl_Insertion(t.root, i);
    //     t.print2d(t.root, 0);
    // }
    // t.root = t.Avl_Insertion(t.root, 3);
    // t.root = t.Avl_Insertion(t.root, 4);
    // t.root = t.Avl_Insertion(t.root, 5);

    // t.print2d(t.root, 0);
    // if (t.Search(0) != nullptr)
    //     std::cout << "found";
    // else
    //     std::cout << "not found";
    // std::cout << "\n"
    //           << t.Height(t.root) << "\n";
    //     // t.BFS(t.root);
    //     t.Delete(t.root, 5);
    //     std::cout << "\n";
    //     t.print2d(t.root, 0);
}