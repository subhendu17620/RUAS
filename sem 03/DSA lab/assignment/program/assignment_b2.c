/* header files */
#include <stdio.h>  
#include <string.h> 
#include <stdlib.h> 

/* function prototypes */
void read_files();  // For reading data from file1 and file2
void process_data(); // For processing the data and calling LCS function
void percentator(); // For calculating similarity percentage 
int max(int num1, int num2); // For calculating MAX of two numbers
int LCS(char **X, char **Y, int m, int n); // For calculating length of LCS and Printing LCS.
/* global variables */
char lcs[60][60];
char data1[100];
char data2[100];

int count = 0;

char *X[100];
int M = 0;
char *Y[100];
int N = 0;

int flag1 = 0;
int flag2 = 0;


void main() // main body
{
    while (1) // For Printing Main-Menu repeatedly
    {
        int ch;
        printf("<======================================================================>");
        printf("\nMAIN MENU\n 1. Print Common Sequences per Sentences\n 2. Print LCS\n 3. Exit ");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        printf("<======================================================================>");
        if (ch == 1)
        {
            flag1 = 1;
        }
        else if (ch == 2)
        {
            flag2 = 1;
        }
        else if (ch == 3)
        {
            exit(1);
        }
        else
        {
            printf("INVALID CHOICE !!!!");
        }
        process_data();
        flag1 = 0;
        flag2 = 0;
    }
}

void read_files()   // For reading data from file1 and file2
{
    FILE *f1, *f2;
    f1 = fopen("test1.txt", "r"); // Opening file1 in reading mode
    f2 = fopen("test2.txt", "r"); // Opening file2 in reading mode

    if (f1 == NULL || f2 == NULL)
    {
        printf("\n File Failed to Open.");
    }
    else
    {
        while (fgets(data1, 100, f1)); // data1 is a string of the whole data of file 1
        while (fgets(data2, 100, f2)); // data2 is a string of the whole data of file 2
        fclose(f1); 
        fclose(f2);
        printf("\n <== File Read Successfully ==> \n");
    }
}

void process_data() // For processing the data and calling LCS function
{
    read_files(); // reading files (calling function)
    /* data processing for file 1 */ 
    int i = 0;
    char *ar1[10];
    int n1 = 0;
    char *p = strtok(data1, ".");
    while (p != NULL)
    {
        n1++;
        ar1[i++] = p;
        p = strtok(NULL, ".");
    }
    // for (i = 0; i < n1; i++)
    //     printf("==> %s\n", ar1[i]);

    int u = 0;
    M = 0;
    i = 0;
    int j = 0;
    char *x[n1][20];
    int m[n1];
    m[0] = 0;
    while (u < n1)
    {
        i = 0;
        char *r = strtok(ar1[u], " ");
        while (r != NULL)
        {
            M++;
            m[u] += 1;
            x[u][i] = r;
            X[j++] = r;
            i++;
            r = strtok(NULL, " ");
        }
        u++;
        m[u] = 0;
    }
    /* X[i] contains all the words of the file 1 */
    //  for (int i = 0; i <M ; i++)
    //  printf("%s\n", X[i]);
    
    /* x[i][j] contains all the words of each line as an element of file 1 */
    /* eg: x[3][3] = {{"this","is","pen"},{"boy","man","girl"},{"orange","yellow","blue"}} */
    // for (i=0;i<n1;i++){
    //  for(j=0;j<m[i];j++){
    //       printf(" %s ",x[i][j]);
    //          }printf("\n");
    //      }

    /* data processing for file 2 */ 
    j = 0;
    char *ar2[20];
    int n2 = 0;
    char *q = strtok(data2, ".");
    while (q != NULL)
    {
        n2++;
        ar2[j++] = q;
        q = strtok(NULL, ".");
    }
    // for (i = 0; i < n2; i++)
    //     printf("==> %s\n", ar2[i]);

    u = 0;
    N = 0;
    i = 0;
    j = 0;
    char *y[n2][10];
    int n[n2];

    n[0] = 0;
    while (u < n2)
    {
        i = 0;
        char *s = strtok(ar2[u], " ");
        while (s != NULL)
        {
            N++;
            n[u] += 1;
            y[u][i] = s;
            Y[j++] = s;
            i++;
            s = strtok(NULL, " ");
        }
        u++;
        n[u] = 0;
    }
    /* Y[i] contains all the words of the file 2 */
    //  for (int i = 0; i <N ; i++)
    //  printf("%s\n", Y[i]); 

    /* y[i][j] contains all the words of each line as an element of file 2 */
    /* eg:   y[3][3] = {{"this","is","pen"},{"boy","man","girl"},{"orange","yellow","blue"}} */
    // for (i=0;i<n2;i++){
    //  for(j=0;j<n[i];j++){    
    //       printf(" %s ",y[i][j]);
    //          }printf("\n");
    //      }
    

    /* PRINTING */
    if (flag1 == 1)
    {
        printf("COMMON SEQUENCES PER SENTENCES ---------\n");
        for (int i = 0; i < n1; i++)
        {
            LCS(x[i], Y, m[i], N);
            memset(lcs, '\0', sizeof lcs);
        }
        percentator(count, M);
    }
    if (flag2 == 1)
    {
        printf("\nLONGEST COMMON SUBSEQUENCE  -------- \n");
        int t = LCS(X, Y, M, N);
        percentator(t, M);
    }
    count = 0;
}

void percentator(int num1, int num2) // For calculating similarity percentage 
{
    printf("\nPLAGIARISED PERCENTAGE => ");
    float percent = ((float)num1 / (float)num2) * 100;
    
    printf(" %0.2f %%", percent);
    if (percent > 30)
        printf("\n\t....PLAGIARISED....\n");
    else
        printf("\n\t....NOT PLAGIARISED....\n");
}

int max(int num1, int num2) // For calculating MAX of two numbers
{
    return (num1 > num2) ? num1 : num2;
}

int LCS(char **X, char **Y, int m, int n) // For calculating length of LCS and Printing LCS.
{   /* for calculating length of LCS */
    int L[m + 1][n + 1];
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (!(strcmp(X[i - 1], Y[j - 1])))
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }

    // printing length of LCS
    // printf("\nLength of lcs :: %d", L[m][n]);

    /* For Printing LCS */
    int index = L[m][n];
    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        if (!(strcmp(X[i - 1], Y[j - 1])))
        {
            strcpy(lcs[index - 1], X[i - 1]);
            i--;
            j--;
            index--;
        }
        else if (L[i - 1][j] > L[i][j - 1])
            i--;
        
        else
            j--;    
    }

    // Printing the LCS
    for (i = 0; i < L[m][n]; i++)
    {
        count++;
        printf("%s\t", lcs[i]);
    }
    printf("\n");

    return L[m][n]; // returning the length of the LCS
}