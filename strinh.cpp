#include<iostream>
 #include<string>
int main()
{
    int n;
    std::string s;
    std::cin>>n;
    s.resize(n);
    for(int i=0;i<n;i++){
        std::cin>>s[i];//no no,s is empty
        std::cout<<"here";
    }
    std::cout<<s;
       
    return 0;
}