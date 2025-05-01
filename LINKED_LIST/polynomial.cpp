#include <iostream>

class Node
{
public: // use friend class SinglyLinkedl if you want to store this in private
    int coeff;
    Node *next;
    int expo;

    Node()
    {
        next = nullptr;
    }
    Node(int coeff, int expo)
    {
        next = nullptr;
        this->coeff = coeff;
        this->expo = expo;
    }
};

class SinglyLinkedl
{
public:
    Node *head;

    SinglyLinkedl()
    {
        head = nullptr;
    }
    ~SinglyLinkedl()
    {

        Node *temp = head;

        while (head != nullptr)
        {
            temp = head;
            head = head->next;

            delete temp;
        }
    }
    // void reverse()
    // {
    //     Node *temp = nullptr;
    //     Node *temp2 = nullptr;
    //     while (head != nullptr)
    //     {
    //         temp2 = head->next;
    //         head->next = temp;
    //         temp = head;
    //         head = temp2;
    //     }
    //     head = temp;
    // }

    void insertAtEnd(int coeff, int expo)
    {
        Node *newNode = new Node(coeff, expo);
        if (head == nullptr)
        {
            head = newNode;
            return;
        }
        if (expo > head->expo)
        {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node *temp = head;
        while (temp->next != nullptr && expo < temp->next->expo)

        {
            temp = temp->next;
        }
        if (temp->next == nullptr)
        {
            temp->next = newNode;
        }
        else
        {
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
    // void addatFront(int coeff, int expo)
    // {
    //     Node *newNode = new Node(coeff, expo);
    //     if (head == nullptr)
    //     {
    //         head = newNode;
    //         return;
    //     }
    //     newNode->next = head;
    //     head = newNode;
    // }
    void display()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            std::cout << temp->coeff << 'x' << '^' << temp->expo;

            temp = temp->next;
            if (temp)
                std::cout << '+' << " ";
        }
        std::cout << std::endl;
    }
    // void InsertAtPosition(int val, int pos)
    // {
    //     Node *newNode = new Node(val);
    //     Node *temp = head;
    //     int i = 1;
    //     while (i < pos)
    //     {
    //         temp = temp->next;
    //         i++;
    //     }
    //     newNode->next = temp->next;
    //     temp->next = newNode;
    // }

    // void Delete(int position)
    // { // pos=index
    //     Node *temp = head;
    //     Node *temp2 = head;
    //     int i = 1;
    //     while (i < position)
    //     {

    //         temp = temp->next;
    //         i++;
    //     }
    //     temp2 = temp->next;
    //     temp->next = temp->next->next;
    //     delete temp2;
    // }
    SinglyLinkedl operator+(SinglyLinkedl l2)
    {
        SinglyLinkedl l3;
        while (head || l2.head)
        {
            if (head->expo == l2.head->expo)
            {
                l3.insertAtEnd(head->coeff + l2.head->coeff, head->expo);
                head = head->next;
                l2.head = l2.head->next;
            }
            else
            {
                if (head->expo > l2.head->expo)
                {
                    l3.insertAtEnd(head->coeff, head->expo);
                    head = head->next;
                }
                else
                {
                    l3.insertAtEnd(l2.head->coeff, l2.head->expo);
                    l2.head = l2.head->next;
                }
            }
        }
        return l3;
    }
    SinglyLinkedl operator*(SinglyLinkedl l2)
    {

        Node *temp = l2.head;
        SinglyLinkedl l4;

        while (head != nullptr)
        {

            temp = l2.head;
            while (temp != nullptr)

            {

                int c1 = head->coeff;
                int c2 = temp->coeff;
                int e1 = head->expo;
                int e2 = temp->expo;

                l4.insertAtEnd(c1 * c2, e1 + e2);

                temp = temp->next;
            }
            head = head->next;
        }

        return l4;
    }
    void likeTerms() // to add like terms
    {
        Node *temp = head;
        Node *temp2 = head;
       
        while (temp->next != nullptr)
        {
            
            if (temp->expo == temp->next->expo)
            {
                temp->coeff = temp->coeff + temp->next->coeff;
                 temp2=temp->next;
                temp->next = temp->next->next;
                delete temp2;
            }
            temp = temp->next;
        }
    }
};

int main()
{
    SinglyLinkedl l;
    l.insertAtEnd(-3, 2);
    l.insertAtEnd(4, 3);
    // l.insertAtEnd(5, 5);
    // l.insertAtEnd(6, 3);
    l.display();
    SinglyLinkedl l2;
    l2.insertAtEnd(2, 2);
    l2.insertAtEnd(7, 3);
    // l2.insertAtEnd(9, 4);
    // l2.insertAtEnd(1, 8);
    l2.display();
    // SinglyLinkedl l3 = l + l2;

    SinglyLinkedl l4 = l * l2;
    l4.display();
    l4.likeTerms();
l4.display();
    return 0;
}