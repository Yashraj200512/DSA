#include <iostream>

class Node
{
public: // use friend class SinglyLinkedList if you want to store this in private
    int data;
    Node *next;

    Node()
    {
        next = nullptr;
    }
    Node(int val)
    {
        next = nullptr;
        data = val;
    }
};

class SinglyLinkedList
{
public:
    Node *head;

    SinglyLinkedList()
    {
        head = nullptr;
    }
    ~SinglyLinkedList()
{

    Node *temp=head;

    while(head!=nullptr){
        temp=head;
        head=head->next;
        
        delete temp;
}
    }
    void reverse(){
            Node *temp=nullptr;
            Node *temp2=nullptr;
            while(head!=nullptr){
               temp2=head->next;
               head->next=temp;
              temp=head;
              head=temp2;
             



            }
            head=temp;
            
          


    }
    
    void insertAtEnd(int value)
    {
        Node *newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    void addatFront(int value)
    {
        Node *newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
    }
    void display()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
    void InsertAtPosition(int val, int pos)
    {
        Node *newNode = new Node(val);
        Node *temp = head;
        int i = 1;
        while (i < pos)
        {
            temp = temp->next;
            i++;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }


    void Delete(int position){ //pos=index
        Node *temp = head;
        Node *temp2 = head;
        int i = 1;
        while (i < position)
        {
            
            temp = temp->next;
            i++;
        }
        temp2=temp->next;
        temp->next=temp->next->next;
        delete temp2;


    }
};

int main()
{
    SinglyLinkedList list;
    
list.insertAtEnd(1);
    list.insertAtEnd(2);
list.insertAtEnd(3);

    list.insertAtEnd(4);
    list.display();
    list.reverse();
    list.display();
    return 0;
}