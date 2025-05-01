//WRITE A PROGRAM TO REVERSE THE ELEMENTS OF STACK USING STACK
//before 1 after 3 in original stack
//       2       2
//       3       1//do it by DS stack linked list later
#include<iostream>
#include<stack>


void transfer(std::stack<int> &a,std::stack<int> &b)
{
    while(!a.empty()){

        b.push(a.top());
        a.pop();
    }


}
int main(){
    std::stack<int> s;
std::stack<int> a;
std::stack<int> b;
s.push(1);
s.push(2);
s.push(3);
s.push(10);

transfer(s,a);

transfer(a,b);
transfer(b,s);

while(!s.empty()){
    std::cout<<s.top()<<" ";
    s.pop();
}






    return 0;
}