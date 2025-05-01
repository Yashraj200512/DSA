// program-1: make a stack but for this program arr[0] will act as top elements, so elements will be added through there and deleted from there too
// you don't have track top,cuz it's arr[0];
#include <iostream>
#include <cstdlib>
class Stack // ATTEMPT AGAIN
{
private:
    int arr[5];
    int total_ele; // can also mean last ele index

public:
    Stack()
    {
        total_ele = -1;
    }

    //

    bool isEmpty()
    {
        return total_ele == -1;
    }

    bool isFull()
    {
        return total_ele == 4;
    }
    void push(int val) // adds element from top
    {
        if (isFull())
        {
            std::cout << "stack overflow" << std::endl;
            return;
        }

        for (int i = total_ele; i >= 0; i--)
        {
            arr[i + 1] = arr[i];
        }

        arr[0] = val;
        total_ele = total_ele + 1;
    }
    int peek()
    {
        if (isEmpty())
        {
            std::cout << "insert ele first" << std::endl;
            return -1;
        }
        return arr[0];
    }
    int pop()

    {
        if (isEmpty())
        {
            std::cout << "insert ele first" << std::endl;
            return -1;
        }
        int data = arr[0];
        total_ele = total_ele - 1;
        for (int i = 0; i <= total_ele; i++)
        {
            arr[i] = arr[i + 1];
        }

        return data;
    }

    void display()
    {
        for (int i = 0; i <= total_ele; i++)
        {
            std::cout << arr[i] << std::endl;
        }
        std::cout << std::endl;
    }
};

    int main()
    {
        Stack s;
        int choice, value;

        while (true)
        {
            std::cout << "\nStack Operations:\n";
            std::cout << "1. Push\n";
            std::cout << "2. Pop\n";
            std::cout << "3. Peek\n";
            std::cout << "4. Display\n";
            std::cout << "5. Exit\n";
            std::cout << "Enter your choice: ";
            std::cin >> choice;

            switch (choice)
            {
            case 1:
                std::cout << "Enter value to push: ";
                std::cin >> value;
                s.push(value);
                break;

            case 2:
                std::cout << "Popped value: " << s.pop() << std::endl;
                break;

            case 3:
                std::cout << "Top element: " << s.peek() << std::endl;
                break;

            case 4:
                s.display();
                break;

            case 5:
                std::cout << "Exiting...\n";
                exit(0);

            default:
                std::cout << "Invalid choice! Try again.\n";
            }
        }

        return 0;
    }
