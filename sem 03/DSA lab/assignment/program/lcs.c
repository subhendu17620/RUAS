#include <stdio.h>
#include <string.h>

int max(int num1, int num2);
void lcs(char **X, char **Y, int m, int n);

void main()
{
    FILE *f1, *f2;
    char data1[100];
    char data2[100];

    f1 = fopen("test1.txt", "r");
    f2 = fopen("test2.txt", "r");

    if (f1 == NULL || f2 == NULL)
    {
        printf(" file failed to open.");
    }
    else
    {
        while (fgets(data1, 100, f1) );
        while (fgets(data2, 100, f2) );
        // { printf( "%s" , data1 ) ;
        //  }
        fclose(f1);
        fclose(f2);
    }

    int i = 0;
    char *p = strtok(data1, ".");
    char *ar1[10];
    int n1 = 0;
    while (p != NULL)
    {
        n1++;
        ar1[i++] = p;
        p = strtok(NULL, ".");
    }

    int j = 0;
    char *q = strtok(data2, ".");
    char *ar2[10];
    int n2 = 0;
    while (q != NULL)
    {
        n2++;
        ar2[j++] = q;
        q = strtok(NULL, ".");
    }
    // for (i = 0; i < 2; i++)
    //     printf("%s\n", ar2[i]);

    int u = 0;
    int m = 0;
    i = 0;
    char *X[10];
    while (u < n1)
    {
        char *r = strtok(ar1[u], " ");
        while (r != NULL)
        {
            m += 1;
            X[i++] = r;
            r = strtok(NULL, " ");
        }
        u++;
    }
    // for (int i = 0; i < m; i++)
    //     printf("%s\n", X[i]);

    u = 0;
    int n = 0;
    j = 0;
    char *Y[10];
    while (u < n2)
    {
        char *s = strtok(ar2[u], " ");
        while (s != NULL)
        {
            n += 1;
            Y[j++] = s;
            s = strtok(NULL, " ");
        }
        u++;
    }
    //  for (int i = 0; i < n; i++)
    //      printf("%s\n", Y[i]);

    lcs(X, Y, m, n);
}

int max(int num1, int num2)
{
    return (num1 > num2) ? num1 : num2;
}

/* Returns length of LCS for X[0..m-1], Y[0..n-1] */

void lcs(char **X, char **Y, int m, int n)
{
    int L[m + 1][n + 1];

    /* Following steps build L[m+1][n+1] in bottom up fashion. Note 
	that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
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
    printf("length of lcs ::%d", L[m][n]);

    // Following code is used to print LCS
    int index = L[m][n];
    char lcs[index + 1][15]; // Create a character array to store the lcs string
    // lcs[index] = '\0'; // Set the terminating character

    // Start from the right-most-bottom-most corner and
    // one by one store characters in lcs[]
    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        // If current character in X[] and Y are same, then
        // current character is part of LCS
        if (!(strcmp(X[i - 1], Y[j - 1])))
        {
            strcpy(lcs[index - 1], X[i - 1]); // Put current character in result

            i--;
            j--;
            index--; // reduce values of i, j and index
        }

        // If not same, then find the larger of two and
        // go in the direction of larger value
        else if (L[i - 1][j] > L[i][j - 1])
            i--;
        else
            j--;
    }

    // Print the lcs
    for (i = 0; i < L[m][n]; i++)
    {
        printf("%s\t", lcs[i]);
    }
}