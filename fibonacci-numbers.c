#include<stdio.h>

int main()
{
    int n1,n2,n3,p;
    n1=0;
    n2=1;
    printf("Enter the number of terms you want to print of fibonacci : ");
    scanf("%d",&p);
    if (p==1)
    {
        printf("%d",n1);
    }
    else if (p==2)
    {
        printf("%d ,%d",n1,n2);
    }
    else
    {
        printf("%d , %d ,",n1,n2);
        for (int i = 0; i < (p-2); i++)
        {
            n3= n1+n2;
            printf(" %d ",n3);
            n1= n2;
            n2= n3;
        }
        
    }
    return 0;
}