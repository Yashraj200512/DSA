// Data Structures: Stacks (Program 2)
//  Topics discussed:
//  1) C program to find and display the prime factors of a number in descending order.
//  2) Calculating the prime factors of a number using the prime factorization method.
#include <iostream>
#include <cstdlib>
class Stack
{
private:
    int arr[25];
    int top;

public:
    Stack()
    {
        top = -1;
        for (int i = 0; i < 5; i++)
        {
            arr[i] = 1;
        }
    }

    bool isEmpty()
    {
        if (top == -1)
            return true;

        return false;
    }
    bool isFull()
    {
        if (top == 4)
            return true;

        return false;
    }

    void push(int val) // adds element from top
    {
        if (isFull())
        {
            std::cout << "stack overflow" << std::endl;
        }
        else
        {
            top++;
            arr[top] = val;
        }
    }

    int pop()
    { // returns top element and removes it
        if (isEmpty())
        {
            std::cout << "stack overflow" << std::endl;
            return 0;
        }
        else
        {
            int popElement = arr[top];
            arr[top] = 1;
            top--;
            return popElement;
        }
    }
    int count()
    {
        return top + 1;
    }

    int peek(int index)
    {

        if (isEmpty())
        {
            std::cout << "stack overflow" << std::endl;
            return 0;
        }
        return arr[index];
    }

    void change(int position, int val)
    {
        arr[position] = val;
    }

    void display()
    {
        for (int i = top; i >= 0; i--)
        {
            std::cout << arr[i] << std::endl;
        }
        std::cout << std::endl;
    }
};
int main()
{
    Stack s;
    int k = 0;
    int n;
    std::cin >> n;
    // for (int i = 2; i <= n / 2; i++)
    // {

    //     if (n % i == 0)
    //    {
    //         for (int j = 2; j * j <= i; j++)
    //         {

    //             if (i % j == 0)
    //                 k++;
    //         }

    //     if (k == 0)
    //     {
    //         s.push(i);
    //         //std::cout<<i<<" "; k==0;

    //     }
    //     k = 0;

    // }}
    // wrong method........prime factors==prime numbers which multiply to give original number
    // 16=2*2*2*2
    // to do that we will start from lowest number
    //  s.display();

    int i = 2; // this means we will take prime factors and divide n by it's prime factors so when we et all of it and dividing n by that will give 1
    while (n != 1)
    {
        while (n%i==0)
        // {if()
        {

            s.push(i);
            n = n / i;
        }
        i++;
    }

s.display();

return 0;
}