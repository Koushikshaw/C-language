#include <stdio.h>

int main()
{
    int n,n1;
    printf("Enter the number of rows: ");
    scanf("%d", &n);
    //upper half of the hour glass
    for (int i = 1; i <=n; i++)
    {
        //spaces
        for ( int j = 1; j <i ; j++)
        {
            printf(" ");
        }
        //stars
        for ( int k = n-i+1; k >0 ; k--)
        {
            printf("* ");
        }
        printf("\n");
    }
    //lower half of the hour glass
    for (int i = 1; i <n; i++)
    {
        //spaces
        for ( int k =n-i-1; k >0 ; k--)
        {
            printf(" ");
        }
        //stars
        for ( int j = i+1; j >0 ; j--)
        {
            printf("* ");
        }
        printf("\n");
    }
    return 0;
}