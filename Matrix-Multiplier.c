#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
int main()
{
    int i, j, k, l;
    printf("\t\tMATRIX MULTIPLICATION\t\t\n\n");
    printf("Matrix 1: \n");
    printf("Enter the number of rows of first matrix : ");
    scanf("%d", &i);
    printf("Enter the number of column in the first matrix :");
    scanf("%d", &j);
    int arr[i][j];
    for (int m = 0; m < i; m++)
    {
        for (int n = 0; n < j; n++)
        {
            printf("Enter the value of %d , %d position of the matrix : ", m + 1, n + 1);
            scanf("%d", &arr[m][n]);
        }
    }
    printf("Matrix 2: \n");
    printf("Enter the number of rows of second matrix : ");
    scanf("%d", &k);
    printf("Enter the number of column in the second matrix :");
    scanf("%d", &l);
    int arr2[k][l];
    int arr3[i][l];
    for (int o = 0; o < k; o++)
    {
        for (int p = 0; p < l; p++)
        {
            printf("Enter the value of %d , %d position of the matrix : ", o + 1, p + 1);
            scanf("%d", &arr2[o][p]);
        }
    }
    printf("Matrix 1 : \n");
    for (int v = 0; v < i; v++)
    {
        for (int w = 0; w < j; w++)
        {
            printf("%d\t", arr[v][w]);
        }
        printf("\n");
    }
    printf("Matrix 2 :\n");
    for (int v = 0; v < k; v++)
    {
        for (int w = 0; w < l; w++)
        {
            printf("%d\t", arr2[v][w]);
        }
        printf("\n");
    }

    if (j == k)
    {
        int t;
        static int u = 0;
        printf("These matrices can be multilied..\n");
        for (int m = 0; m < i; m++)
        {
            for (int n = 0; n < l; n++)
            {
                for (int o = 0; o < j; o++)
                {
                    t = arr[m][o] * arr2[o][n];
                    u = u + t;
                }
                arr3[m][n] = u;
                u = 0;
                t = 0;
            }
        }
        printf("The multiplicated Matrix is : \n");
        for (int q = 0; q < i; q++)
        {
            for (int r = 0; r < l; r++)
            {
                printf("%d\t", arr3[q][r]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("The two matrices cannot be multiplied....");
    }

    return 0;
} 

