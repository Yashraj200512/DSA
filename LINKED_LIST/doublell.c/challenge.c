// WRITING ALL FUNCTIONS POSSIBLE IN DOUBLE LINKED LIST
#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};
void reverse(struct node *head)
{

    struct node *temp = malloc(sizeof(struct node));
    struct node *end = malloc(sizeof(struct node));
    end = head;
    temp = head;
    int j = 1;
    while (end->next != NULL)
    {
        j++;
        end = end->next;
    }
    int i = 1;

    while (i < j)
    {
        int temps = end->data;

        end->data = temp->data;
        temp->data = temps;

        // null 0 1000 ,1000 1 2000...........4000 4 null
        temp = temp->next;
        end = end->prev;
        // printf("%d ",end->data);
        // printf("%d ",temp->data);
        i++;
        j--;
    }
}
void ADDataPosition(struct node *head, int pos, int data)
{

    struct node *HEAD = head;
    int i = 1;
    pos--;
    // HEAD = head;
    while (1 == 1)
    {

        HEAD = HEAD->next;
        i++;
        if (i == pos)
            break;
    }

    struct node *temp = malloc(sizeof(struct node));
    temp->next = HEAD->next;
    temp->data = data;
    temp->prev = HEAD;
    HEAD->next = temp;
}
void ADDatend(struct node *head, int data)
{

    struct node *temp = malloc(sizeof(struct node));
    struct node *HEAD = malloc(sizeof(struct node));
    HEAD = head;
    while (HEAD->next != NULL)
    {

        HEAD = HEAD->next;
    }
    temp->prev = HEAD;
    temp->next = NULL;
    temp->data = data;
    HEAD->next = temp;
}
void print(struct node *heads)
{
    struct node *temp = malloc(sizeof(struct node));
    temp = heads;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
struct node *AddtoEmptylist(struct node *head, int data)

{
    struct node *temp = malloc(sizeof(struct node));

    temp->prev = NULL;
    temp->next = NULL;
    temp->data = data;

    return temp;
}

struct node *AddatBeginning(struct node *head, int data)

{
    struct node *temp = malloc(sizeof(struct node));

    temp->prev = NULL;
    temp->next = head;
    temp->data = data;

    return temp;
}

int main()
{
    struct node *head = malloc(sizeof(struct node));

    head = AddtoEmptylist(head, 1);

    head = AddatBeginning(head, 0);
    head = AddatBeginning(head, -1);
    ADDatend(head, 2);
    ADDatend(head, 3);

    ADDataPosition(head, 3, 10); // 3 is position means -1,0,[here],1,2,3
    ADDataPosition(head, 4, 17);
    print(head);
    reverse(head);
    // print(head);
}