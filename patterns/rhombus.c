#include<stdio.h>

int main()
{
    int n;
    printf("Enter the number of rows: ");
    scanf("%d", &n);
    //rhombus
    for (int i = 1; i <=n; i++)
    {
        //spaces
        for ( int j =1; j <=i ; j++)
        {
            printf(" ");    
        }
        //stars
        for ( int k =1; k <=n ; k++)
        {
            printf("* ");
        }
        printf("\n");
    }
    
    return 0;
}