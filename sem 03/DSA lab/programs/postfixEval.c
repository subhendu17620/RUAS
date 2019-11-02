// postfix evalution
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define max 10

int s[max];
int top = -1;

void push(int n)
{
  if (top > max)
  {
    printf("\nStack Overflow!!\n");
  }
  else
  {
    s[++top] = n;
  }
}

int pop()
{
  if (top < 0)
  {
    printf("\nStack Empty!!!\n");
  }
  else
  {
    int x = s[top--];
    return x;
  }
}

void print()
{
  printf("\n Evaluted No.: ");
  for (int i = top; i >= 0; i--)
  {
    printf("%d\n", s[i]);
  }
  printf("\n");
}

void main()
{
  char str[10], operator;
  int op1, op2;
  printf("Postfix Expression : ");
  gets(str);
  for (int i = 0; i < strlen(str); i++)
  {
    if (isalnum(str[i]))
    {
      push(str[i] - '0');
    }
    else
    {
      operator= str[i];
      op1 = pop();
      op2 = pop();
      switch (operator)
      {
      case '*':
        push(op1 * op2);
        break;
      case '/':
        push(op2 / op1);
        break;
      case '%':
        push(op1 % op2);
        break;
      case '+':
        push(op1 + op2);
        break;
      case '-':
        push(op2 - op1);
        break;
      default:
        break;
      }
    }
  }
  print();
}
