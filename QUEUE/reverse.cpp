#include <iostream>
#include <stack>
#include <queue>

void reverse(std::queue<int> &Queue)
{
    std::stack<int> s;
    while(!Queue.empty()){
        s.push(Queue.front());
        Queue.pop();
    }

    while(!s.empty()){
        Queue.push(s.top());
        s.pop();
    }



    
}

int main()
{
    std::queue<int> q;
    std::stack<int> s;

    q.push(5);
    q.push(10);
    q.push(15);
    reverse(q);
   q.push(1);
   reverse(q);
    
    while(!q.empty()){
        std::cout<<q.front()<<" ";
        q.pop();
    }

    return 0;
}
