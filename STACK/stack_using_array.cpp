#include <iostream>
#include <cstdlib>
class Stack
{
private:
    int arr[5];
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
        //     if (isEmpty())
        //     {
        //         return 0;
        //     }
        //     if (isFull())
        //     {
        //         return 5;
        //     }

        //     int i = 0;
        //     while (i < top + 1)
        //     {
        //         i++;
        //     }
        return top + 1; // what a dumbass i am
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

    void options()
    {

        std::cout << "what operations do you want to perform, press any number, press 0 to exit" << std::endl;
        std::cout << "1. push  " << std::endl;
        std::cout << "2. isEmpty     " << std::endl;
        std::cout << "3. isFull     " << std::endl;
        std::cout << "4. Change    " << std::endl;
        std::cout << "5. pop   " << std::endl;
        std::cout << "6. peek   " << std::endl;
        std::cout << "7. count   " << std::endl;
        std::cout << "8. display    " << std::endl;
        std::cout << "9. clear screen    " << std::endl;
        std::cout << "10.see options again    " << std::endl;
    }
};
int main()
{
    Stack s;
    int option, pos, val;

    do
    {
        s.options();
        std::cin >> option;

        switch (option) // break statements cumpulsory in switch,for e.g if you dont use break and type opt 3 then all 3-9 will be executed
        {
        case 1:
        {
            std::cout << "enter value to push into stack" << std::endl;
            int i;
            std::cin >> i;
            s.push(i);
            break;
        }
        case 2:
        {
            if (s.isEmpty())
                std::cout << "Stack is empty" << std::endl;
            else
                std::cout << "stack is not empty" << std::endl;
            break;
        }
        case 3:
        {
            if (s.isFull())
                std::cout << "Stack is Full" << std::endl;
            else
                std::cout << "stack is not Full" << std::endl;
            break;
        }
        case 4:
        {
            std::cout << "enter position and value" << std::endl;
            std::cin >> pos >> val;
            s.change(pos, val);

            break;
        }
        case 5:
        {

            std::cout << "popValue is: " << s.pop() << std::endl;
            break;
        }
        case 6:
        {
            std::cout << "enter index value" << std::endl;
            int index;
            std::cin >> index;
            int value;
            value = s.peek(index);
            std::cout << "element value at index " << index << " is " << value << std::endl;
            break;
        }
        case 7:
        {
            std::cout << "total elements in stacks are : " << s.count() << std::endl;
            break;
        }
        case 8:
        {

            std::cout << "STACK :" << std::endl;
            s.display();
            break;
        }
        case 9:
        {
            system("cls");
            break;
        }
        }
    } while (option != 0);

    return 0;
}