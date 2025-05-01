// infix(normal maths expression)==a+b*c/d+e/(f+g),-
// postfix==  abc*d/+efg+/+...only need to scan one time...whenever come around opt..use it on prev two operand

#include <iostream>
#include <string>
#include <stack>

int precedence(char k)
{
    switch (k)
    { //                         DO THIS AGAIN ON YOUR OWN!!!!!!!!!!!!!!!!!!!!!!
      // DO THIS AGAIN ON YOUR OWN!!!!!!!!!!!!!!!!!!!!!!
    case '+': // DO THIS AGAIN ON YOUR OWN!!!!!!!!!!!!!!!!!!!!!!
    case '-':
        return 1;
    case '/':
    case '*':
        return 2;
    case '^':
        return 3;

    default:
        return 0;
    }
}
int main()
{
    std::stack<char> s;
    // int a, b, c, d, e, f, g;
    int j = 0;
    // std::cin >> a >> b >> c >> d >> e >> f >> g;
    std::string infix = "a+b*c/d+e/(f+g)";
    std::string postfix;

    for (int i = 0; i < infix.size(); i++)
    { // n C++, you can check if s[i] is a digit (0-9) using the isdigit() function from <cctype>.

        // if(infix[i]>='0' && infix[i]<='9') continue;
        switch (infix[i])
        {
        case '(':
            s.push('(');
            break;
        case ')':
        {
            while (s.top() != '(')
            {
                postfix.push_back(s.top());
                s.pop();
            }
            s.pop();
            break;
        }
        case '+':
        case '-':
        case '/':
        case '*':
        case '^':
        {

            while (!s.empty() && precedence(s.top()) >= precedence(infix[i]))
            {
                postfix.push_back(s.top());
                s.pop();
            }
            s.push(infix[i]);
            break;
        }
        default:
            postfix.push_back(infix[i]);
        }
    }
    while (!s.empty())
    {
        postfix.push_back(s.top());
        s.pop();
    }
    std::cout << postfix;
    // int symbol;
    // for (int i = 0; i < postfix.size(); i++)
    // {
    //     switch (postfix[i])
    //     {
    //     }
    //     // if(postfix[i]=='+') postfix[i-1]+postfix[i-2]

    //     if (postfix[i] = '-')
    //         if (postfix[i] = '/')
    //             if (postfix[i] = '*')
    //                 if (postfix[i] = '^')
    // }

    return 0;
}