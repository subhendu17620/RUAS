#include <stdio.h>
#include <string.h>

#define MAX 2

struct systemIP
{   char host_name[20];
    char ip[20];
};

struct systemIP S[MAX];
int octet_1[MAX];

void get_data();
void get_octet1();
void print_data();

void main(int argc, char** argv) {
    get_data();
    get_octet1();
    //print_data();
}

void get_data() {
    for ( int i = 0; i < MAX; i++)
    {
    // printf("Enter host name[%d] : ",i+1);
    // gets(S[i].host_name);
    printf("Enter IP address[%d]:  ",i+1);
    gets(S[i].ip);

    }
}

void get_octet1() {
    for ( int i = 0; i < MAX; i++)
    {  
        // atoi converts string to integer
        int int_octet = atoi(S[i].ip);
        octet_1[i] = int_octet;
    }
    for ( int i = 0; i < MAX; i++)
    { 
        printf("%d\n",octet_1[i]);
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
