#include<stdio.h>

int main()
{
    int n;
    printf("Enter the number of rows: ");
    scanf("%d", &n);
    //left half pyramid
    for (int i = 1; i <=n; i++)
    {
        //spaces
        for ( int j = n-i; j >0 ; j--)
        {
            printf("  ");    
        }
        //stars
        for ( int k =1; k <=i ; k++)
        {
            printf("* ");
        }
        printf("\n");
    }
    
    return 0;
}