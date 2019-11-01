// inserting an element at end
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top=NULL;

void push(int x){
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
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
            printf("%d\n", temp->data);
            temp = temp->next;
        }
    }
}
int main(int argc, char const *argv[])
{
    int ITEM, choice;
    while (1)
    {
        printf("Enter Choice (1: PRINT, 2: PUSH, 3: POP, 4: Exit..:");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            print();
            break;
        case 2:
            printf("Enter Item to be insert :");
            scanf("%d", &ITEM);
            push(ITEM);
            break;
        case 3:
            pop();
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
