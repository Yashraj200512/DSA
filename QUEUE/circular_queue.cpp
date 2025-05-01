#include <iostream>

class Queue     // CIRCULAR QUEUE
{               // when rear==max-1, make rear 0.
public:         // when front==max-1, front 0.
    int front;  // when queue has only one element, that's when front==rear make rear and front 0.
    int rear;   // empty- front==-1;
    int arr[4]; // full-  front==rear+1 or front==0 and rear=max-1;

public:
    Queue()
    {
        front = -1;
        rear = -1;
    }
    bool isEmpty()
    {

        if (front == -1)
        {

            return true;
        }
        return false;
    }

    bool isFull()
    {
        if ((rear == 3 && front == 0) || (front == rear + 1))
        {

            return true;
        }
        return false;
    }

    void enqueue(int val)
    {
        if (isFull())
        {
            std::cout << "QUEUE OVERFLOW" << std::endl;
            return;
        }
        if (isEmpty())
        {
            front = 0;
        }
        if (rear == 3)
        {
            rear = 0;
        }
        else
        {
            rear++;
        }
        arr[rear] = val;
    }

    int
    dequeue()
    {
        if (isEmpty())
        {
            std::cout << "no ele to dequeue";
            return -1;
        }
        int dequeue_val = arr[front];
        if (front == rear)
        {

            front = rear = -1;
        }
        else if (front == 3)
        {
            front = 0;
        }

        else
        {
            front++;
        }
        return dequeue_val;
    }
    int count()
    {
        return rear - front + 1;
    }

    void display()
    {
        if (isEmpty())
        {
            std::cout << "no elements to display" << std::endl;
            return;
        }

        if (rear < front)

        {
            for (int i = front; i <= 3; i++)
            {

                std::cout << arr[i] << " ";
            }
            // std::cout << std::endl;
            for (int i = 0; i <= rear; i++)
            {

                std::cout << arr[i] << " ";
            }
            std::cout << std::endl;
        }

        else
        {
            for (int i = front; i <= rear; i++)
            {

                std::cout << arr[i] << " ";
            }
            std::cout << std::endl;
        }
    }
};
int main()
{
    Queue q;
    q.display();

    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.display();

    q.dequeue();

    q.enqueue(3);

    q.display();

    q.dequeue();

    q.enqueue(9);

    q.display();

    q.dequeue();

    q.enqueue(99);

    q.display();
    q.dequeue();
    q.display();

    // q.display();
    // q.enqueue(4);
    // std::cout << q.isFull() << std::endl;

    return 0;
}