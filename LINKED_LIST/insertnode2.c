#include <stdio.h>
#include <stdlib.h> //OPTIMAL CODE

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
struct node *insertingnode(struct node *ptrs, int data)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->ptr = NULL;
    ptrs->ptr = temp;
    return temp;
}
int main()
{
    struct node *head = malloc(sizeof(struct node));
    head->data = 4;
    head->ptr = NULL;

    struct node *ptrs = NULL;
    ptrs = head;

    ptrs = insertingnode(ptrs, 5);   //creating list from scratch by insert function
    ptrs = insertingnode(ptrs, 6);
    print(head);
    
    insertingnode(ptrs,9);
    print(head);
    return 0;
}