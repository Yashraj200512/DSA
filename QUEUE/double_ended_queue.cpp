#include <iostream>

class Queue // DOUBLE ENDED QUEUE-queue from both sides or you can say stack but hollow at bottom
{
public:         // implementation is same as circular queue, difference is you can add,del from both rear and end
    int front;  // addition of function enqueue_front--when front==0,make front==max-1.
    int rear;   // addition of function dequeue_rear--when rear==0,make rear==max-1;
    int arr[4]; //

public:
    void enqueue_front(int val)
    {

        if (isFull())
        {
            std::cout << "QUEUE OVERFLOW" << std::endl;
            return;
        }
        if (isEmpty())
        {
            front = 0;
            rear = 0;
        }
        else if (front == 0)
        {
            front = 3;
        }
        else
        {
            front--;
        }
        arr[front] = val;
    }

    int dequeue_rear()
    {
        
        if (isEmpty())
        {
            std::cout << "no ele to dequeue_rear";
            return -1;
        }
        int dequeue_rear_val = arr[rear];
        if (front == rear)
        {

            front = rear = -1;
        }
        else if (rear == 0)
        {
            rear = 3;
        }

        else
        {
            rear--;
        }
        return dequeue_rear_val;

    }
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

    void enqueue_rear(int val)
    {
        if (isFull())
        {
            std::cout << "QUEUE OVERFLOW" << std::endl;
            return;
        }
        if (isEmpty())
        {
            front = 0;
            rear = 0;
        }
        else if (rear == 3)
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
    dequeue_front()
    {
        if (isEmpty())
        {
            std::cout << "no ele to dequeue_front";
            return -1;
        }
        int dequeue_front_val = arr[front];
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
        return dequeue_front_val;
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

    q.enqueue_rear(2);
    q.enqueue_rear(3);
    q.enqueue_rear(4);
    q.enqueue_rear(5);
    q.display();

    q.dequeue_front();

    q.enqueue_front(3);

    q.display();

     q.dequeue_front();

     q.dequeue_rear();

     q.display();

    q.dequeue_front();

     q.enqueue_rear(99);
     q.enqueue_front(0);
     q.enqueue_front(77);
     q.display();

    // q.display();
    // q.dequeue_front();
    // q.display();

    // q.display();
    // q.enqueue_rear(4);
    // std::cout << q.isFull() << std::endl;

    return 0;
}