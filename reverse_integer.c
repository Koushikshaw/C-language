#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<time.h>
#include<stdint.h>
#include<limits.h>

int reverse(int x){
    
    // Convert the integer to a string
    char str[12]; // Large enough to accommodate any 32-bit integer
    sprintf(str, "%d", x);

    // Check if the number is negative
    int isNegative = (x < 0) ? 1 : 0;

    // Reverse the string
    int start = isNegative ? 1 : 0; // Skip the negative sign if present
    int end = strlen(str) - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }

    // Convert the reversed string back to an integer
    int64_t reversedNumber = strtoll(str, NULL, 10);

    // Check boundaries before returning the result
    if (reversedNumber > INT_MAX || reversedNumber < INT_MIN) {
        return 0;
    } else {
        return (int)reversedNumber;
    }
}

int main()
{
    //Taking input from the user
    int a;
    printf("\t\tReversing a Integer\n");
    printf("Enter the integer to reverse: ");
    scanf("%d",&a);
    int reversed = reverse(a);
    if (reversed == 0)
    {
        printf("The reverse number of the number you entered is of size more than 32 bit.");
    }
    else{
        printf("The reverse of the number you enetered is %d",reversed);
    }
    return 0;
}