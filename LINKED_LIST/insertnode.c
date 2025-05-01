#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *ptr;
};
void print(struct node *ptrs)
{
    int i = 0;

    while (ptrs != NULL)
    {
        printf("%d\n", ptrs->data);
        ptrs = ptrs->ptr;
        i++;
    }
}
void insertingnode(struct node *ptrs, int data)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->ptr = NULL;
    
    struct node *head = NULL;
    head = ptrs;
    while (ptrs->ptr != NULL)
    {

        ptrs = ptrs->ptr;
        
    }
    ptrs->ptr = temp;
}
int main()
{
    struct node *head = malloc(sizeof(struct node));
    head->data = 4;
    head->ptr = NULL;

    // now creating another node
    struct node *current = malloc(sizeof(struct node));
    current->data = 5;
    current->ptr = NULL;
    head->ptr = current; // stores adress of 2nd node in link box/ptr first node

    current = malloc(sizeof(struct node));
    current->data = 6;
    current->ptr = NULL;
    head->ptr->ptr = current;

    

    insertingnode(head, 7);
    insertingnode(head, 8);
    print(head);
    return 0;
}