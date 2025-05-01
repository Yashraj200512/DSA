#include<stdio.h>
#include<stdlib.h>

struct node{   //a node consists of 1.data, 2.link....so we need to store 2 values in 1 node which we can do with the help of struct,
    //the link which we will store are of nodes so ofc link pointer type is struct node
  int data;
  struct node *ptr;

}; //we will first create a head pointer,and allocate memory to it

int main() {
    struct node *head=malloc(sizeof(struct node)); //first created memory to store int and a adress and head pointer is storing that adress
    head->data=4;                                  // alternate= (*head).data=4 ...dereferncing head pointer and storing value in the node
    head->ptr=NULL;

//now creating another node
struct node *current=malloc(sizeof(struct node));
current->data=5;                                  
    current->ptr=NULL;
head->ptr=current;   //stores adress of 2nd node in link box/ptr first node 

current=malloc(sizeof(struct node));
current->data=6;                                  
    current->ptr=NULL;
head->ptr->ptr=current; //head->ptr gives node2 from there we can access the link part of node 2 and put value of adress of node 3 there
printf("%d\n",head->ptr->ptr);
printf("%d\n",current);
printf("%d\n",head->data);
printf("%d",head->ptr->data);
    return 0;
}