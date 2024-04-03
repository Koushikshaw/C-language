#include<stdio.h>
void sequentialDigits(int low, int high) {
    for(int i=low;i<=high;i++)
    {
        int digits=0;
        int k=i,l=i;
        // while(l!=0)
        // {
        //     l=l/10;
        //     digits++;
        // }
        // printf("%d ",digits);
        int flag=0;
        while(i>=0)
        {
            // if((i/10)!=0)
            // {
            //     int r1,r2,temp;
            //     r1=i%10;
            //     temp = i/10;
            //     r2 = temp%10;
            //     if((r1-1)==r2)
            //     {
            //     flag++;}
            // }
            i=i/10;
        }
        if(flag==2)
        {
            // elements++;
            // *(returnSize+elements)=k;
            printf("%d ",k);
        }
        
    }
    
}
int main()
{
    int low,high;
    printf("Enter the range: ");
    scanf("%d%d",&low,&high);
    sequentialDigits(low,high); 
    return 0;
}