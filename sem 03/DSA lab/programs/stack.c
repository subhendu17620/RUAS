// stack operations
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int STACK[MAX], TOP;
void display(int[]);
void PUSH(int[], int);
void POP(int[]);

void main()
{
    int ITEM = 0;
    int choice = 0;
    TOP = -1;

    while (1)
    {
        
        printf("Enter Choice (1: display, 2: PUSH, 3: POP, 4: Exit..:");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            display(STACK);
            break;
        case 2:
            printf("Enter Item to be insert :");
            scanf("%d", &ITEM);
            PUSH(STACK, ITEM);
            break;
        case 3:
            POP(STACK);
            break;
        case 4:
            exit(0);
        default:
            printf("\nInvalid choice.");
            break;
        }
    }
}

void display(int stack[])
{
    int i = 0;
    if (TOP == -1)
    {
        printf("Stack is Empty .\n");
        return;
    }

    printf("%d ", stack[TOP]);
    for (i = TOP - 1; i >= 0; i--)
    {
        printf("\n%d", stack[i]);
    }
    printf("\n\n");
}

void PUSH(int stack[], int item)
{
    if (TOP == MAX - 1)
    {
        printf("\nSTACK is FULL CAN't ADD ITEM\n");
        return;
    }
    TOP++;
    stack[TOP] = item;
}

void POP(int stack[])
{
    int deletedItem;
    if (TOP == -1)
    {
        printf("STACK is EMPTY.\n");
        return;
    }

    deletedItem = stack[TOP];
    TOP--;
    printf("%d deleted successfully\n", deletedItem);
    return;
}
