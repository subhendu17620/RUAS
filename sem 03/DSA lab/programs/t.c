#include<stdio.h>
int main()
{
    int x;
float bal;
scanf("%d%f", &x,&bal);

 if ( (x%5==0) && (bal >= (x+0.5)))
 {
     bal=bal-x-0.50;
 }
 printf("%0.2f",bal);
    return 0;
}



