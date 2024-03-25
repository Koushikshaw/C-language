#include<stdio.h>

int main()
{
    int n,n1;
    printf("Enter the number of rows: ");
    scanf("%d", &n);
    //inverted right half pyramid
    for (int i = 1; i <=n; i++)
    {
        //stars
        for ( int k = n-i+1; k >0 ; k--)
        {
            printf("* ");
        }
        printf("\n");
    }
    
    return 0;
}