#include <stdio.h>
#include <string.h>

int main()
{
	char str[] = "192.168.12.20";
    printf("%s",str);
	int size = strlen(str);
	char delim[] = ".";

	char *ptr = strtok(str, delim);

	while (ptr != NULL)
	{
		printf("'%s'\n", ptr);
		ptr = strtok(NULL, delim);
	}
    printf("%s",str);
	return 0;
}