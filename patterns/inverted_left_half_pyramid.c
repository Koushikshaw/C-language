#include<stdio.h>

int main()
{
    int n;
    printf("Enter the number of rows: ");
    scanf("%d", &n);
    //inverted_left half pyramid
    for (int i = 1; i <=n; i++)
    {
        //spaces
        for ( int j = 1; j <i ; j++)
        {
            printf("  ");    
        }
        //stars
        for ( int k =n-i+1; k >0 ; k--)
        {
            printf("* ");
        }
        printf("\n");
    }
    
    return 0;
}