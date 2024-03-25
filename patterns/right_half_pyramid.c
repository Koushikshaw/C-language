#include<stdio.h>

int main()
{
    int n,n1;
    printf("Enter the number of rows: ");
    scanf("%d", &n);
    //upper half of the right half pyramid
    for (int i = 1; i <=n; i++)
    {
        //stars
        for ( int k = 1; k <=i ; k++)
        {
            printf("* ");
        }
        printf("\n");
    }
    
    return 0;
}