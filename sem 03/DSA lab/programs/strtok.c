#include <stdio.h>
#include <string.h>

int main()
{
	char str[] = "thi asdj sakdjask";
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
    printf("'%c'\n", ptr);


	return 0;
}