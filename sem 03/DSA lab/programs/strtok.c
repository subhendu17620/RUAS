#include <stdio.h>
#include <string.h>

int main()
{
	char str[] = "12252.168.23.333";
    //printf("%s",str);
	int size = strlen(str);
	char delim[] = ".";

 // char str[100]=" ";
        // // printf("%s\n",S[i].ip);
        // strcpy(str,S[i].ip);
        // //printf("%s",str);
    	// char delim[] = ".";
	    // char *ptr =  strtok(str, delim);
        // printf("'%s'\n", ptr);
        // octet_1[i]=ptr;
        
	char *ptr = strtok(str, delim);
    printf("'%s'\n", ptr);


	return 0;
}