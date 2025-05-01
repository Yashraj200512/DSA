//CHECK WHETHER A STRING IS PALINDROME OR NOT WITH STACK
//QUESTION: we are given char a,b with X in middle
//palinddrome==reads same as from left to X and right to X
#include<iostream>
#include<stack>
#include<string>

int main(){

    std::stack<char> a,b;
    std::string s="bbaababaXababaaba";
int i=0;
    while(i<s.size())
    {
        a.push(s[i]);
        i++;
    }
    while(a.top()!='X')
    {
        b.push(a.top());
        a.pop();
    }
    a.pop();
    if(a==b) std::cout<<"palindrome";
    else std::cout<<" not palindrome";

    




    return 0;
    }