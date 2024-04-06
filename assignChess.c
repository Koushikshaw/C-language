#include<stdio.h>
struct coordinates
{
    int x;
    int y;
}dimen;
int main()
{
    int q;
    printf("Enter the dimensions of the board:\n");
    scanf("%d%d",&dimen.x,&dimen.y);
    printf("Enter the number of coordinates: ");
    scanf("%d",&q);
    struct coordinates c[q];
    printf("Enter %d coordinates:\n",q);
    for (int i = 0; i < q; i++)
    {
        printf("coordinates : ");
        scanf("%d%d",&c[i].x,&c[i].y);
    }
    for (int i = 0; i < dimen.x; i++)
    {
        for (int j = 0; j < dimen.y; j++)
        {
            int count=0;
            for (int k = 0; k < q; k++)
            {
                if ((c[k].x==i)&&(c[k].y==j))
                {
                    count=1;
                }
            }
            if (count==1)
            {
                printf("Q ");
            }
            else if (count==0)
            {
                printf("* ");
            }  
        }
        printf("\n"); 
    }
    return 0;
}