// QUEUE......open at both ends...like stack but open at rear too
//  you can only add ele from rear and remove from front like real life queue
#include <iostream>

class Queue
{
private:
    int front;
    int rear;
    int arr[4];

public:
    Queue()
    {
        front = -1;
        rear = -1;
    }
    bool isEmpty()
    {

        if (front == -1 || front > rear)
        {
            
            return true;
        }
        return false;
        
    }

    bool isFull()
    {
        if (rear == sizeof(arr) / sizeof(int) - 1)
        {
           
            return true;
        }
        return false;
       
    }

    void enqueue(int val)
    {
        if (isFull())
        {
            std::cout << "QUEUE OVERFLOW"<<std::endl;
            return;
        }
        if (isEmpty())
        {
            front=0;
        }
        rear++;
        arr[rear] = val;
    }

    int dequeue()
    {
        if (isEmpty())
        {
            std::cout << "no ele to dequeue";
            return -1;
        }
        int dequeue_val=arr[front];
        front++;
        return dequeue_val;

    }
    int count(){
        return rear-front+1;
    }

    void display(){
        if (isEmpty())
        {
            std::cout << "no elements to display"<<std::endl;
            return;
        }
      
        for(int i=front;i<=rear;i++){
            std::cout<<arr[i]<<" ";
        }
        std::cout<<std::endl;


    }
};
int main()
{
Queue q;
q.display();
std::cout<<q.isEmpty()<<std::endl;
q.enqueue(2);
q.enqueue(3);
q.enqueue(4);
q.enqueue(5);
std::cout<<q.count()<<std::endl;
q.dequeue();
q.enqueue(3);
q.display();
q.enqueue(4);
std::cout<<q.isFull()<<std::endl;

    return 0;
}