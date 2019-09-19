#include<stdio.h>

int main(int argc, char const *argv[])
{   char st[20];
    printf("Enter String: ");
    gets(st);
    int i,len =0;
    
    for ( i=0;st[i]!='\0';i++){ // for calculating length of the string 
        len++;
    }
    char rev[20];
    for (i=len-1; i >= 0; i--)
    {
        rev[len-i-1]=st[i]; // reverse of the input string
    }
    int flag=1;
    for (i = 0; i < len; i++)
    {
        if (rev[i]!=st[i]){
            flag=0;
        }
    }
    if (flag==1)
        printf("palindrome");
    else
        printf("not a palindrome");
    
    return 0;
}

