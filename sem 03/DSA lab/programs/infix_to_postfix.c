// infix to postfix using stack
#include <stdio.h>
#include <ctype.h>

char s[50];
int top = -1;
char push(char elem)
{
    top++;
    s[top] = elem;
    return s[top];
}

char pop()
{
    if (top == -1)
        return -1;
    else
        return (s[top--]);
}

int pr(char elem)
{
    if (elem == '(')
        return 0;
    if (elem == '+' || elem == '-')
        return 1;
    if (elem == '*' || elem == '/')
        return 2;
}

void main()
{
    char infx[50], *e, elem;

    printf("\n\nInfix Expression: ");
    scanf("%s", infx);
    e = infx;
    while ((*e != '\0'))
    {
        if (isalnum(*e))
        {
            printf("%c", *e);
        }
        else if (*e == '(')
        {
            push(*e);
        }

        else if (*e == ')')
        {
            while ((elem = pop()) != '(')
            {
                printf("%c", elem);
            }
        }
        else
        {
            while (pr(s[top]) >= pr(*e))
            {
                printf("%c", pop());
            }
            push(*e);
        }
        e++;
    }
    while (top != -1)
    {
        printf("%c", pop());
    }
}