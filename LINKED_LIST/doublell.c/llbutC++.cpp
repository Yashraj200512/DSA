#include <iostream>
using namespace std;
class linkedlist

{
private:
    struct node
    {
        struct node *next;
        int data;
        node(int value) : data(value), next(nullptr) {}
    };

    node *head;

public:
    linkedlist() : head(nullptr) {}
    void insertatEND(int value)

    {
        node *temp = new node(value);
        if (head == nullptr)
        {
            head = temp;
        }
        else
        {
            node *current = head;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = temp;
        }
    }
    void print()
    {
        node *current = head;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
    void reverse()
    {
        int i = 1;
        int n = 6; //can get n from countnodes();
        int p=n;
        node *current = head;
        node *cur = head;
        node *s;
        
        while (current->next != nullptr)
        {
            current = current->next;
            i++;
            if (i == n)
            {
                swap(cur->data, current->data);
                current = head;
                cur = cur->next;
                i = 1;
                n = n - 1;
                
            }
   if (n==p/2) break; 
  
   
        }
    }
};
int main()
{
    linkedlist list;
    list.insertatEND(1);
    list.insertatEND(2);
    list.insertatEND(3);
    list.insertatEND(4);
    list.insertatEND(5);
    list.insertatEND(6);
    list.print();
    list.reverse();
    list.print();
    return 0;
}