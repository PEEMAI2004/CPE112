// Kamin Jittapassorn 66070503409
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int mode;
    int flag = 0;
    scanf("%d", &n);
    // allocate memory for int
    int *arr = (int *)malloc(n * sizeof(int));
    // get 1st address of array
    int *ptr = arr;
    // get nnumbers
    for (int i = 0; i < n; i++)
    {
        scanf("%d", ptr);
        ptr++;
    }
    // get mode
    // 0: Print out the even index of the array
    // 1: Print out the odd index of the array
    scanf("%d", &mode);
    // print out
    for (int i = 0; i < n; i++)
    {
        int *ptr = arr + i;
        if (mode == 0 && i % 2 == 0)
        {
            printf("%d ", *ptr);
            flag = 1;
        }
        else if (mode == 1 && i % 2 == 1)
        {
            printf("%d ", *ptr);
            flag = 1;
        }
    }
    if (flag == 0)
    {
        printf("none");
    }
}