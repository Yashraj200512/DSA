// #include <stdio.h>
// #include <stdlib.h> //OPTIMAL CODE

// struct node
// {
//     struct node *prev;
//     int data;
//     struct node *next;
// };
// void print(struct node *HEAD)
// {
    

//     while (HEAD != NULL)
//     {
//         printf("%d\n", HEAD->data);
//         HEAD = HEAD->next;
        
//     }
// }
// struct node *adding(struct node *HEAD, int data)
// {
//     struct node *temp = malloc(sizeof(struct node));
//     temp->prev =HEAD;
//     temp->data = data;
//     temp->next = NULL;
//     HEAD->next = temp;
//     return temp;
// }
// int main()
// {
//     struct node *head = malloc(sizeof(struct node));
//     head->prev = NULL;

//     head->data = 4;
//     head->next = NULL;

//     struct node *HEAD = NULL;
//     HEAD = head;

//     HEAD = adding(HEAD, 5);   //creating list from scratch by insert function
//     HEAD = adding(HEAD, 6);
//     // print(head);
    
//     HEAD= adding(HEAD,9);
//     print(head);

//     while (HEAD != NULL)
//     {
//         printf("%d\n", HEAD->data);
//         HEAD = HEAD->prev;
           
//     }
//     return 0;
// } //now INSERTION AT BEGINING
#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};
void print(struct node *HEAD)
{
    while(HEAD!=NULL){
        printf("%d",HEAD->data);
        HEAD=HEAD->next;
    }
}
struct node* insertingnode(struct node *HEAD, int data)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    temp->prev=NULL;
    temp->next=HEAD;
    
    
    return temp;
}
int main()
{
    struct node *head = malloc(sizeof(struct node));
    head->prev=NULL;
    head->data = 4;
    head->next = NULL;

    // now creating another node
    struct node *current = malloc(sizeof(struct node));
    current->prev=head;
    current->data = 5;
    current->next = NULL;
    head->next = current; // stores adress of 2nd node in link box/next first node

    current = malloc(sizeof(struct node));
    head->prev=head->next;
    current->data = 6;
    current->next = NULL;
    head->next->next = current;

    

    head=insertingnode(head, 7);
    head=insertingnode(head, 8);
    print(head);
    return 0;
}