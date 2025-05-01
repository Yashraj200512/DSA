#include <iostream>
#include <string>
#include <stack>

std::stack<char> s;
std::stack<int> s2;

int precedence(char opt)
{
    switch (opt)
    {
    case '+':
    case '-':
        return 1;
    case '/':
    case '*':
        return 2;
    default:
        return 0;
    }
}
std::string conversion(std::string infix)
{

    std::string postfix;
    for (int i = 0; i < infix.length(); i++)
    {
        switch (infix[i])
        {
        case '(':
            s.push(infix[i]);
            break;
        case ')':
        {
            while (s.top() != '(')
            {
                postfix = postfix + s.top();
                s.pop();
            }
            s.pop();
            break;
        }

        case '+':
        case '*':
        case '/':
        case '-':
        {
            while (!s.empty() && precedence(infix[i]) <= precedence(s.top()))
            {
                postfix += s.top();
                s.pop();
            }
            s.push(infix[i]);
            break;
        }
        default:
            postfix += infix[i];
        }
    }
    while (!s.empty())
    {
        postfix += s.top();
        s.pop();
    }
    return postfix;
}

int evaluate(std::string expression)
{
    for (int i = 0; i < expression.length(); i++)
    {

        char k = expression[i];
        if (k >= '0' && k <= '9')
        {
            s2.push(k - '0');
        }
        else
        {

            int a = s2.top();

            s2.pop();
            int b = s2.top();
            s2.pop();

            switch (k)
            {
            case '+':
                s2.push(a + b);
                break;
            case '*':
                s2.push(a * b);
                break;
            case '/':
                s2.push(b / a);
                break;
            case '-':
                s2.push(b - a);
                break;
            }
        }
    }

    return s2.top();
}

int main()
{
    // std::string s="a+b*c/d-e/(f+g)";
    // std::stack<char> st;
    std::string infix = "1+2*2/4+5/(2+3)";

    // infix = "a+b*c/d-e/(f+g)";
    //  std::stack<char> st;

    std::string postfix;
    postfix = conversion(infix);
    std::cout << postfix << "\n";
    int d = evaluate(postfix);
    std::cout << d;
    return 0;
}

