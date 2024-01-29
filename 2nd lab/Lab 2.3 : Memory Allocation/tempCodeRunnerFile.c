// Kamin Jittapassorn 66070503409
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // size of array
    int size = 1000000;

    // Dynamic memory allocation using malloc()
    int *arr1 = (int *)malloc(size * sizeof(int));

    // Dynamic memory allocation using calloc()
    int *arr2 = (int *)calloc(size, sizeof(int));

    // Compute the sum from 1 - 1000000
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        arr1[i] = i + 1;
        arr2[i] = size - i;
    }

    // Print out the sum
    printf("%d", sum);
    // Print out diff
    printf("%d", sum);
}