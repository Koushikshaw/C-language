#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main()
{
    printf("\t\t SORTING OF ARRATYS BY BUBBLE SORT \t\n\n");
    int n;
    printf("Enter the numer of elements you want to put inside the Array : \n");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the Elements of the array : \n");
    for (int k = 0; k < n; k++)
    {
        printf("Ente the value of %d position of the array : \n", k + 1);
        scanf("%d", &arr[k]);
    }
    printf("Unsorted Array : \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");

    // Bubble Sort :

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
            else
            {
                continue;
            }
        }
    }
    printf("Sorted Array : \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    return 0;
}