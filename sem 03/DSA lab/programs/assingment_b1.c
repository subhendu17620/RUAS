/* header files */
#include <stdio.h>  
#include <string.h> 
#include <stdlib.h> 

#define MAX 3 // no. of inputs user want to give

struct systemIP
{
    char host_name[20];
    char ip[20];
};

struct systemIP S[MAX]; // declaring variables of struct systemIP
int octet_1[MAX];

/* function protypes */
void get_data();
void print_data();
void get_octet();
char class_select(int);
void print_by_host_name();
void print_data_class();

void main(int argc, char **argv) // main body
{

    while (1)
    {
        int ch;
        printf("<======================================================================>");
        printf("\nMAIN MENU\n 1. Input data\n 2. Print Data\n 3. Print Class of IP by Host-Name\n 4. Print classes of all data\n 5. Exit ");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        char temp;
        scanf("%c", &temp);
        switch (ch)
        {
        case 1:
            get_data();
            printf("\nDATA SUCCESSFULLY ENTERED... ");
            break;
        case 2:
            print_data();
            break;
        case 3:
            print_by_host_name();
            break;
        case 4:
            printf("\nPRINTING .....\n");
            for (int i = 0; i < MAX; i++)
            {
                print_data_class(i);
            }
            break;
        case 5:
            exit(1);
            break;
        default:
            printf("\nWrong Choice!!! ");
            break;
        }
    }
}

void get_data() // For Inputing data 
{
    for (int i = 0; i < MAX; i++)
    {
        printf("Enter host name[%d] : ", i + 1);
        gets(S[i].host_name);
        label: 
        printf("Enter IP address[%d]:  ", i + 1);
        gets(S[i].ip);
        get_octet();
        if (octet_1[i] > 255)
        {
            printf("Octet value can't be more than 255. PLEASE ENTER AGAIN !!!\n");
            goto label; // for asking IP-address again & again , if user inputs a value more than 255
        }
    }
}

void print_data() // For printing the inputed data
{
    for (int i = 0; i < MAX; i++)
    {
        printf("Host name[%d] : ", i + 1);
        puts(S[i].host_name);
        printf("IP address[%d]:  ", i + 1);
        puts(S[i].ip);
    }
}

void get_octet() // For getting the first octet of the IP Address
{
    for (int i = 0; i < MAX; i++)
    {
        // atoi converts string to integer
        int int_octet = atoi(S[i].ip);
        octet_1[i] = int_octet;
    }
}

char class_select(int oct) // For Getting the class of an IP Address
{
    char cl;
    if (oct >= 1 && oct <= 126)
    {
        cl = 'A';
    }
    else if (oct >= 127 && oct <= 191)
    {
        cl = 'B';
    }
    else if (oct >= 192 && oct <= 223)
    {
        cl = 'C';
    }
    else if (oct >= 224 && oct <= 239)
    {
        cl = 'D';
    }
    else if (oct >= 240 && oct <= 254)
    {
        cl = 'E';
    }
    return cl;
}
void print_by_host_name() // Searching a data by host-name (Linear Search) 
{
    char srch_hstnm[20];
    printf("Enter host name: ");
    gets(srch_hstnm);
    int pos, flag = 0;
    for (int i = 0; i < MAX; i++)
    {
        if (!(strcmp(srch_hstnm, S[i].host_name)))
        {
            flag = 1;
            pos = i;
            break;
        }
    }
    if (flag == 0)
    {
        printf("Host-Name Not Found!!!\n");
    }
    else
    {
        printf("FOUND..!!");
        print_data_class(pos);
    }
}
void print_data_class(int n) // For Printing all the data with class of the IP address
{
    get_octet();
    printf("Host name[%d] : ", n + 1);
    puts(S[n].host_name);
    printf("IP address[%d]:  ", n + 1);
    puts(S[n].ip);
    char cla = class_select(octet_1[n]);
    printf("Class = %c ", cla);
    printf("\n\n");
}
