#include <iostream>
// PRIORITY QUEUE
// addition to having data and node adress, each node will have a certain priority no too,
// and ele must be inserted based on priority queue
// low number==higher priority
class Node
{
public:
    int priority;
    int data;
    Node *next;

    Node(int priority, int val)
    {
        this->priority = priority;
        data = val;
        next = nullptr;
    }
};

class Queue
{
public:
    Node *front;
    Node *rear;

    Queue()
    {
        front = nullptr;
        rear = nullptr;
    }

    bool isEmpty()
    {
        // if (front == nullptr)
        //     return true;
        // return false; just usee
        return front == nullptr;
    }
    void enqueue(int pr, int val)
    {
        Node *newNode = new Node(pr, val);
        Node *temp = front;
        if (isEmpty())
        {
            front = newNode;
            rear = newNode;
            return;
        } 
        if (pr < temp->priority)
        {
            newNode->next = front;
            front = newNode;
        }

        else
        {
            while (temp->next->priority < pr)
            {

                temp = temp->next;
                if(temp->next==nullptr){
                    break;
                }
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    int dequeue()
    {
        if (isEmpty())
        {
            std::cout << "no elements to dequeue" << std::endl;
            return -1;
        }

        int data = front->data;
        Node *temp = front;
        front = front->next;
        delete temp;
        temp = nullptr;

        if (front == nullptr)
        {
            rear = nullptr; // ✅ This condition RUNS and resets rear
        }

        return data;
    }

    void display()
    {

        Node *temp = front;
        while (temp != nullptr)
        {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

int main()
{
    Queue q;
    std::cout << q.isEmpty() << std::endl;
    q.enqueue(4,10);
     q.enqueue(1,20);
     q.enqueue(99,30);
    q.enqueue(9,40);
    q.display();
    //std::cout << q.dequeue() << std::endl;
    //q.display();

    return 0;
}