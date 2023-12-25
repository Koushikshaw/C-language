#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

int main()
{
    // Write your C code Here
    int nums[] = {3, 2, 1, 0, 4};
    int length = sizeof(nums) / sizeof(nums[0]);
    printf("%d", length);
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length; j++)
        {
            if (i == j)
            {
                continue;
            }
            else
            {
                if ((nums[i] + nums[j]) == (length - 1))
                {
                    printf("true\n");
                    goto end;
                }
                else
                {
                    continue;
                }
            }
        }
    }
    end:
    printf("false\n");

    return 0;
}