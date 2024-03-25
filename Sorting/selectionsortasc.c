#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <limits.h>

int main()
{
    printf("\t\tSORTING OF ARRAYS BY SELECTION SORT\t \n\n ");
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

    // Selection Sort :

    for (int i = 0; i < n - 1; i++)
    {
        int min = __INT_MAX__;
        int mindx = -1;
        for (int j = i; j < n; j++)
        {
            if (min > arr[j])
            {
                min = arr[j];
                mindx = j;
            }
        }
        // Now Swap the minimum part to the first elementof the non Sorted part
        int temp = arr[mindx];
        arr[mindx] = arr[i];
        arr[i] = temp;
    }

    printf("Sorted Array : \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    return 0;
}