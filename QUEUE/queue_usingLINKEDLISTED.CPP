#include <iostream>

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
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
      return front==nullptr;
    }
    void enqueue(int val)
    {
        Node *newNode = new Node(val);

        if (isEmpty())
        {
            front = newNode;
            rear =newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
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
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.display();
    std::cout << q.dequeue() << std::endl;
    q.display();

    return 0;
}