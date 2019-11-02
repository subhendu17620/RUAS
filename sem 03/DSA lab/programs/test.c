#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

void push(int x)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;
    if (top == NULL)
    {
        top = newnode;
        top->next = NULL;
    }
    else
    {
        newnode->next = top;
        top = newnode;
    }
}
void pushbfr(int n, int x)
{

    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;

    struct node *temp = top, *back;

    while (temp->data != n)
    {
        back = temp;
        temp = temp->next;
    }
    back->next = newnode;
    newnode->next = temp;
}

void pushaftr(int n, int x)
{

    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;

    struct node *temp = top, *aftr;
    while (temp->data!=n)
    {
        aftr=temp;
        temp=temp->next;
    }
    
    temp->next=newnode;
    newnode->next=aftr;

   
}

void pop()
{
    struct node *temp = top;
    if (top == NULL)
    {
        printf("Empty stack ");
    }
    else
    {
        top = top->next;
        free(temp);
    }
}
void print()
{
    struct node *temp = top;
    if (top == NULL)
        printf("Empty Stakc");
    else
    {
        while (temp != NULL)
        {
            printf("%d-", temp->data);
            temp = temp->next;
        }
    }
}
int main(int argc, char const *argv[])
{
    // int ITEM,prev, choice;
    push(2);
    push(3);
    push(4);
    push(5);
    push(6);

    // print();
    // printf("huhi");
    // pushbfr(5, 8);
    // print();
    pushaftr(4,10);
    print();
    // while (1)
    // {
    //     printf("Enter Choice (1: PRINT, 2: PUSH, 3: POP, 4: Exit..:");
    //     scanf("%d", &choice);

    //     switch (choice)
    //     {
    //     case 1:
    //         print();
    //         break;
    //     case 2:
    //         printf("Enter Item to be insert :");
    //         scanf("%d", &ITEM);
    //         printf("prev one: ");
    //         scanf("%d",&prev);
    //         push(ITEM);
    //         pushbfr(prev,ITEM);
    //         break;
    //     case 3:
    //         pop();
    //         break;
    //     case 4:
    //         exit(0);
    //     default:
    //         printf("\nInvalid choice.");
    //         break;
    //     }
    // }
    return 0;
}
