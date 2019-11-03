// llinked list - insertion at beginning & at end
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *next;
};
struct node *top = NULL;

void pushbeg(int x)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->info = x;
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

void pushaftr(int x){
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->info=x;
    newnode->next=NULL;

    struct node* temp=top;

    if (top==NULL){
        top=newnode;
        // top->next=NULL;
    }
    else{
        while (temp->next!=NULL)
        {   
            temp=temp->next;
        }
        temp->next=newnode;

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
            printf("%d--> ", temp->info);
            temp = temp->next;
        }
    }
}
int main(int argc, char const *argv[])
{
    int ITEM, choice;
    while (1)
    {
        printf("\nEnter Choice 1: PRINT, 2: PUSH at start, 3: PUSH at end,, 4. EXIT..:");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            print();
            break;s
        case 2:
            printf("Enter Item to be insert at beginning :");
            scanf("%d", &ITEM);
            pushbeg(ITEM);
            break;
        
        case 3:
            printf("Enter Item to be insert at end :");
            scanf("%d", &ITEM);
            pushaftr(ITEM);
            break;
        case 4:
            exit(0);
        default:
            printf("\nInvalid choice.");
            break;
        }
    }
    return 0;
}
