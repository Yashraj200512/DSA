#include <stdio.h>
#include <stdlib.h>

struct node
{ // a node consists of 1.data, 2.link....so we need to store 2 values in 1 node which we can do with the help of struct,
    struct node *prev;
    // the link which we will store are of nodes so ofc link pointer type is struct node
    int data;
    struct node *next;

}; // we will first create a head pointer,and allocate memory to it

int main()
{
    struct node *head = malloc(sizeof(struct node));
    struct node *head2 = malloc(sizeof(struct node));
    head2 = head;
    head->prev = NULL;
    // first created memory to store int and a adress and head pointer is storing that adress
    head->data = 4; // alternate= (*head).data=4 ...dereferncing head pointer and storing value in the node
    head->next = NULL;

    // now creating another node
    struct node *current = malloc(sizeof(struct node));
    current->prev = head;
    current->next = head;
    current->data = 5;
    current->next = NULL;
    head->next = current; // stores adress of 2nd node in link box/next first node

    current = malloc(sizeof(struct node));
    current->prev = head->next;
    current->data = 6;
    current->next = NULL;
    head->next->next = current; // head->next gives node2 from there we can access the link part of node 2 and put value of adress of node 3 there
    while (head2 != NULL)
    {
        printf("%d\n", head2->data);
        head2 = head2->next;
    }
    while (current != NULL)
    {
        printf("%d\n", current->data);

        current = current->prev;
    }

    return 0;
}