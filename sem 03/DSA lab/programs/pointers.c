#include<stdio.h>
int main(int argc, char const *argv[])
{
    int *ptr, q;
   q = 50;
   /* address of q is assigned to ptr */
   ptr = &q;
   /* display q's value using ptr variable */
   printf("%d--%d", *ptr,ptr);
    return 0;
}
