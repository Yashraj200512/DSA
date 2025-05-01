#include <iostream>
#define Globalspace 5
class Node
{
public:
    int data;
    Node *right;
    Node *left;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
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

    void insert_iteration(int val)
    {
        Node *newNode = new Node(val); // new just allocates memory on heap for whatever present ahead, node just calls constructor and initializes values
        if (root == nullptr)
        {
            root = newNode;
            return; // put return or else bruh in null cases.
        }

        Node *temp = root;
        while (true)
        {
            if (temp->data == val)
                return;

            if (val > temp->data)
            {
                if (temp->right == nullptr)
                {
                    temp->right = newNode;
                    return;
                }
                temp = temp->right;
            }
            else
            {
                if (temp->left == nullptr)
                {
                    temp->left = newNode;
                    return;
                }
                temp = temp->left;
            }
        }
    }

    Node *insert_recursive(Node *node, int val)
    {

        if (node == nullptr)
        {
            // Node *newNode = new Node(val);
            // return newNode; or
            return new Node(val);
        }

        if (val > node->data)
            node->right = insert_recursive(node->right, val);
        else
            node->left = insert_recursive(node->left, val);

        return node;
    }

    Node *AVL_insert(Node *node, int val)
    {
        if (node == nullptr)
            return new Node(val);

        if (val > node->data)
            node->right = AVL_insert(node->right, val);
        else
            node->left = AVL_insert(node->left, val);

        int bf = balancefactor(node);
        if (bf > 1)
        {

            if (node->left->data > val)
            {
                return Rightrotate(node);
            }
            else
            {
                node->left = leftrotate(node->left);
                return Rightrotate(node);
            }
        }
        if (bf < -1)
        {

            if (node->right->data < val)
            {
                return leftrotate(node);
            }
            else
            {
                node->right = Rightrotate(node->right);
                return leftrotate(node);
            }
        }
        return node;
    }

    Node *Rightrotate(Node *node)
    {
        Node *temp = node->left;
        node->left = temp->right;
        temp->right = node;
        return temp;
    }

    Node *leftrotate(Node *node)
    {
        Node *temp = node->right;
        node->right = temp->left;
        temp->left = node;
        return temp;
    }
    int balancefactor(Node *node)
    {
        return (height(node->left) - height(node->right));
    }

    int height(Node *node)
    {
        if (node == nullptr)
            return -1;

        int left_height = height(node->left);
        int right_height = height(node->right);

        if (left_height >= right_height)
            return left_height + 1;
        else
            return right_height + 1;
    }
    void preorder(Node *node)
    {
        if (node == nullptr)
            return;

        std::cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }
    void print2d(Node *node, int space)
    {
        if (node == nullptr)
            return;

        space += Globalspace;
        print2d(node->right, space);
        for (int i = Globalspace; i <= space; i++)
        {
            std::cout << " ";
        }
        std::cout << node->data << "\n";
        print2d(node->left, space);
    }

    Node *Delete(Node *node, int val)
    {
        if (node == nullptr)
            return node;

        if (val > node->data)
        {
            node->right = Delete(node->right, val);
        }
        else if (val < node->data)
        {
            node->left = Delete(node->left, val);
        }

        else
        {

            if (node->left == nullptr)
            {
                Node *temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr)
            {
                Node *temp = node->left;
                delete node;
                return temp;
            }
            else
            {
                Node *temp = minNode(node->right);
                node->data = temp->data;
                node->right = Delete(temp, temp->data);
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

    Node *Avl_delete(Node *node, int val)
    {

        if (node == nullptr)
            return node;

        if (val > node->data)
        {
            node->right = Avl_delete(node->right, val);
        }
        else if (val < node->data)
        {
            node->left = Avl_delete(node->left, val);
        }

        else
        {

            if (node->left == nullptr)
            {
                Node *temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr)
            {
                Node *temp = node->left;
                delete node;
                return temp;
            }
            else
            {
                Node *temp = minNode(node->right);
                node->data = temp->data;
            node->right = Avl_delete(temp, temp->data);
            }
        }

        int bf = balancefactor(node);

        if (bf > 1)
        {

            if (balancefactor(node->left)  >=0)
                return Rightrotate(node);
            else
            {
                node->left = leftrotate(node->left);
                return Rightrotate(node);
            }
        }
        else if (bf < -1)
        {
            if (balancefactor(node->right) <=0)
                return leftrotate(node);
            else
            {
                node->right = Rightrotate(node->right);
                return leftrotate(node);
            }
        }

        return node;
    }
};
int main()
{
     Tree t;
    // t.insert_iteration(5);
    // t.insert_iteration(2);
    // t.insert_iteration(6);
    // t.insert_iteration(3);
    // t.insert_iteration(1);
    // t.insert_iteration(8);
    // t.insert_iteration(4);
    // t.insert_iteration(0);
    // Tree t2;
    // t2.root = t2.insert_recursive(t2.root, 5);
    // t2.insert_recursive(t2.root, 2);
    // t2.insert_recursive(t2.root, 6);
    // t2.insert_recursive(t2.root, 3);
    // t2.insert_recursive(t2.root, 1);
    // t2.insert_recursive(t2.root, 8);
    // t2.insert_recursive(t2.root, 4);
    // t2.insert_recursive(t2.root, 0);
    // t2.preorder(t.root);
    // std::cout << "\n";
    // t2.preorder(t2.root);
    // std::cout << "\n";
    // std::cout << t.height(t.root);

    // Tree t3;

    // t3.root = t3.AVL_insert(t3.root, 1);
    // t3.root = t3.AVL_insert(t3.root, 2);
    // t3.root = t3.AVL_insert(t3.root, 3);
    // t3.root = t3.AVL_insert(t3.root, 4);
    // t3.root = t3.AVL_insert(t3.root, 5);
    // t3.root = t3.AVL_insert(t3.root, 6);
    // // t3.root = t3.AVL_insert(t3.root, 7);
    // t3.print2d(t3.root, 0);
    // t3.root=t3.Avl_delete(t3.root,5);
    // std::cout << "\n";
    // t3.print2d(t3.root, 0);
    // t3.root=t3.Avl_delete(t3.root,6);
    // std::cout << "\n";
    // t3.print2d(t3.root, 0);
    while (true)
    {
        int i;

        std::cin >> i;
        t.root = t.AVL_insert(t.root, i);
        t.print2d(t.root, 0);
        std::cout<<"\n\n";
        if(i==72) break;
    }
    while (true)
    {
        int i;

        std::cin >> i;
        t.root = t.Avl_delete(t.root, i);
        t.print2d(t.root, 0);
    }
}