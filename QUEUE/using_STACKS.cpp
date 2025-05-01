 #include<iostream>
 #include<stack>


 class queue{
    private:
    std::stack<int> s1;
    std::stack<int> s2;

    public:

    void enqueue(int val){
      

        s1.push(val);

    }


    void dequeue(){
        if(s1.empty() && s2.empty()){
            std::cout<<"empty";
            return;

        }


        if(s2.empty()){

            while(!s1.empty()){
                s2.push(s1.top());
                s2.pop();
            }

        }

        s2.pop();
    }

    void display(){//prints queue backward

        std::stack<int> p1=s1;
        std::stack<int> p2=s2;
    

        while(!p2.empty()){
            std::cout<<p2.top()<<" ";
             p2.pop();

        }
        while(!p1.empty()){
            std::cout<<p1.top()<<" ";
             p1.pop();
    }
    std::cout<<std::endl;
}


 };

 int main(){

    queue q;
    q.enqueue(1);
    q.display();
     q.enqueue(2);
     q.display();
    q.enqueue(3);
    q.enqueue(4);
    q.display();
    // q.dequeue();
    // q.display();


    return 0;
 }