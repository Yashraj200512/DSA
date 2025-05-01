#include <iostream>

class Node
{
public:
    int data;
    Node *right;
    Node *left;
    Node(int val)
    {
        right = nullptr;
        left = nullptr;
        data = val;
    }
};
class Tree
{
public:

    Node *createTree(){
    int input,val;
    std::cout<<"enter 1 if you want to add value otherwise 0\n";
    std::cin>>input;
    if(input==0) return nullptr;
    else{
        std::cout<<"enter val\n";
        std::cin>>val;
        Node *newNode=new Node(val);

        newNode->left=createTree();
        
    }
    }
    
    
};

int main()
{
    Tree t;

    return 0;
}