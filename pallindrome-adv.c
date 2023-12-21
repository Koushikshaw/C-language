#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>
#include<time.h>


bool isPalindrome(int x){
    char str[20];
    sprintf(str,"%d",x);

    //checking length of the string 2
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
     char str2[length];

    //for debugging purpose 1
    // for (int i = 0; i < length; i++)
    // {
    //     printf("%c\n",str[i]);
    // }
    int start = 0;
    int end = length - 1;

    while (start < length) {
        str2[start] = str[end];
        start++;
        end--;
    }

    //for debugging purpose 2
    // for (int i = 0; i < length; i++)
    // {
    //     printf("%c\n",str2[i]);
    // }
    
    //Checking if arrays are equal
    int a = 1;
    for (int i = 0; i < length; i++) {
        if (str[i] != str2[i]) {
            a = 0;  
        }
    }
    if (a==1)
    {
        return true;
    }
    else{
        return false;
    }   
}

int main()
{
    //Write your C code Here
    int x;
    printf("Chceck if the number is pallindrome or not (signs included)\n");
    printf("Enter the number You want to check : ");
    scanf("%d",&x);
    int b = isPalindrome(x);
    if (b ==1)
    {
        printf("The bumber is a pallindrome");
    }
    else{
        printf("The number you entered is not a pallindrome");
    }
    
    return 0;
}