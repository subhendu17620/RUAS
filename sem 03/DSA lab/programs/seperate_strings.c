#include<stdio.h>
#include<string.h>

int main(int argc, char const *argv[])
{   int i=0,j=0;
    char str[]="this is a sentence";
    char st[]=" ";
    while(str[i]!='\0')
    {   if (str[i]==' ')
        {   st[j]='\0';

        }
        i++;

    }
     
    return 0;
}
