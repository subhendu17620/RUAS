#include<stdio.h>
#include<string.h>
#define MAX 3
struct systemIP
{   char host_name[20];
    char ip[20];
    
};
struct systemIP S[MAX];
int octet_1[MAX];
void get_data(){
    for ( int i = 0; i < MAX; i++)
    {
    printf("Enter host name[%d] : ",i+1);
    gets(S[i].host_name);
    printf("Enter IP address[%d]:  ",i+1);
    gets(S[i].ip);
    }
}
void get_octet1()
{
    for ( int i = 0; i < MAX; i++)
    {   
        char str[]=" ";
        strcpy(str,S[i].ip);
        //printf("%s",str);
	    int size = strlen(str);
	    char delim[] = ".";
	    char *ptr = strtok(str, delim);

        while (ptr != NULL)
        {
            //printf("'%s'\n", ptr);
            ptr = strtok(NULL, delim);
        }
        strcpy(octet_1[i],str);
        for ( i = 0; i < MAX; i++)
        {
            printf("%d",octet_1[i]);
        }
        
        //printf("%s\n",str);
    }
    
}
void print_data()
{
    for ( int i = 0; i < MAX; i++)
    {
    printf("Host name[%d] : ",i+1);
    puts(S[i].host_name);
    printf("IP address[%d]:  ",i+1);
    puts(S[i].ip);
    }
    
}


void main()
{
    get_data();
    get_octet1();
}