#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void read_files();
int max(int num1, int num2);
void process_data();
int LCS(char **X, char **Y, int m, int n);
void percentator();

char lcs[150][60];
int count = 0;
char data1[100];
char data2[100];

char *X[50];
int M = 0;
char *Y[50];
int N = 0;

int flag1 = 0;
int flag2 = 0;


void main()
{   
    while (1)
    {

        int ch;
        printf("MAIN MENU\n 1. Print Common Sequences per Sentences\n 2. Print LCS of whole data \n 3. Exit ");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        char temp;
        scanf("%c", &temp);
        if (ch==1){
            flag1=1;
        }
        else if(ch==2){
            flag2=1;
        }
        else if(ch==3){
            exit(1);
        }
        else{
            printf("wrong choice!!!!");
        }
        process_data();
        flag1=0;
        flag2=0;
    }
}

void read_files()
{
    FILE *f1, *f2;
    f1 = fopen("test1.txt", "r");
    f2 = fopen("test2.txt", "r");

    if (f1 == NULL || f2 == NULL)
    {
        printf(" File Failed to Open.");
    }
    else
    {
        while (fgets(data1, 100, f1))
            ;
        while (fgets(data2, 100, f2))
            ;
        fclose(f1);
        fclose(f2);
        printf("....File Read Successfully . .\n");
    }
}

void process_data()
{
    read_files();
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
    char *x[n1][10];
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
    //  for (int i = 0; i <M ; i++)
    //  printf("%s\n", X[i]);
    // for (i=0;i<n1;i++){
    //  for(j=0;j<m[i];j++){
    //       printf(" %s ",x[i][j]);
    //          }printf("\n");
    //      }

            j = 0;
            char *ar2[10];
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
    
    //  for (int i = 0; i <N ; i++)
    //  printf("%s\n", Y[i]);
    // for (i=0;i<n2;i++){
    //  for(j=0;j<n[i];j++){
    //       printf(" %s ",y[i][j]);
    //          }printf("\n");
    //      }
    }

    if (flag1 == 1)
    {
        printf("COMMON SEQUENCES PER SENTENCES ---------\n");

        for (int i = 0; i < n1; i++)
        {
            LCS(x[i], Y, m[i], N);
            memset(lcs, '\0', sizeof lcs);
        }
        printf("count=%d, M= %d",count,M);
        percentator(count, M);
        
    }
    if (flag2 == 1)
    {
        printf("\nLONGEST COMMON SUBSEQUENCE  -------- \n");
        int t = LCS(X, Y, M, N);
        percentator(t, M);
        
    }
    count=0;
}

void percentator(int num1, int num2)
{
    // printf("%d",count);
    printf("\nSIMILARITY PERCENTAGE => ");
    float percent = ((float)num1 / (float)num2) * 100;
    printf(" %0.3f %%", percent);
    if (percent > 40)
    {
        printf("\n\t....PLAGIARISED....\n");
    }
    else
        printf("\n\t....NOT PLAGIARISED....\n");
}


int max(int num1, int num2)
{
    return (num1 > num2) ? num1 : num2;
}

int LCS(char **X, char **Y, int m, int n)
{
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
    // printing length of lcs
    // printf("\nlength of lcs ::%d", L[m][n]);

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
        {
            i--;
        }
        else
        {
            j--;
        }
    }

    // Print the lcs
    for (i = 0; i < L[m][n]; i++)
    {
        count++;
        printf("%s\t", lcs[i]);
    }
    printf("\n");
    return L[m][n];
}