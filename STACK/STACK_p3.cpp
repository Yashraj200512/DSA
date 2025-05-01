//decimal to binary conversion
#include<iostream>
#include<stack>


int main(){

    std::stack<int> s;
    int n;
    std::cin>>n;

    while(n>0){
        int k=n%2;
        s.push(k);
        n=n/2;





    }
    while(!s.empty()){
        std::cout<<s.top();
        s.pop();

    }
    return 0;
    }