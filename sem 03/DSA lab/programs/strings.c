// A C/C++ program for splitting a string 
// using strtok() 
#include <stdio.h> 
#include <string.h> 

int main() 
{ 
	char buf[] ="this is subhendu. i am not a terrorirst. .";
    int i = 0;
    char *p = strtok (buf, ".");
    char *array[10];

    while (p != NULL)
    {
        array[i++] = p;
        p = strtok (NULL, ".");
    }
    for (i = 0; i < 3; i++) 
        printf("%s\n", array[i]);

	return 0; 
} 
