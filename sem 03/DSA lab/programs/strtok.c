
// int main()
// {
// 	// char str[] = "thi asdj sakdjask";
//     // //printf("%s",str);
// 	// int size = strlen(str);
// 	char delim[] = ".";

//  // char str[100]=" ";
//         // // printf("%s\n",S[i].ip);
//         // strcpy(str,S[i].ip);
//         // //printf("%s",str);
//     	// char delim[] = ".";
// 	    // char *ptr =  strtok(str, delim);
//         // printf("'%s'\n", ptr);
//         // octet_1[i]=ptr;
        
// 	// char *ptr = strtok(str, delim);
//     // printf("'%c'\n", ptr);
//     char S[50];
//     printf("Enter IP address[%d]:  " );
//     gets(S);
//     printf("printing");
//     puts(S);
  
//     char *ar[10]; 
//     int n=0;
//     int i=0;
//     char* token = strtok(S, "."); 
//     while (token != NULL) { 
//         n++;
//         ar[i++] = token;
//         token = strtok(NULL, ".");
//     } 
//     for (i = 0; i < n; i++)
//         printf("==> %d\n", atoi(ar[i]));



// 	return 0;
// }
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
char *ar[4]; 
void main() // For Inputing data 
{
    for (int i = 0; i < MAX; i++)
    {
        printf("Enter host name[%d] : ", i + 1);
        gets(S[i].host_name);
        label: 
        printf("Enter IP address[%d]:  ", i + 1);
        gets(S[i].ip);

       
        int n=0;
        int j=0;
        char* token = strtok(S[i].ip, "."); 
        while (token != NULL) 
      { 
        n++;
        ar[j++] = token;
        token = strtok(NULL, ".");
      }
        // printf("%d",n);
    //     for (int k = 0; k < n; i++)
    //   {
         for (i = 0; i < n; i++)
        printf("==> %d\n", atoi(ar[i]));
    //      printf(ar[i]);
         
    //   }

    //   for (int k = 0; k < n; i++)
    //   {
    //      ar[k]=atoi(ar[k]);
    //      printf(ar[i]);
    //      if (ar[k] > 255)
    //     {
    //         printf("Octet value can't be more than 255. PLEASE ENTER AGAIN !!!\n");
    //         goto label; // for asking IP-address again & again , if user inputs a value more than 255
    //     }
    //   }
    }
}