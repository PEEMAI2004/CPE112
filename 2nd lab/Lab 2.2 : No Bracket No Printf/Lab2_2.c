// Kamin Jittapassorn 66070503409

#include <stdio.h>
#include <stdlib.h>

void printg(int *num)
{
    int temp = *num;

    // Handle the case when the number is zero separately
    if (temp == 0)
    {
        putchar('0');
    }
    else
    {
        // Handle negative numbers
        if (temp < 0)
        {
            putchar('-');
            temp = -temp;
        }
        // Find the number of digits in the integer
        int divisor = 1;
        while (temp / divisor > 9)
        {
            divisor *= 10;
        }

        // Print each digit individually
        while (divisor > 0)
        {
            putchar((temp / divisor) + '0');
            temp %= divisor;
            divisor /= 10;
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    // allocate memory for elements
    int *arr = (int *)malloc(n * sizeof(int));
    // get 1st address of array
    int *ptr = arr;
    // get numbers
    for (int i = 0; i < n; i++)
    {
        scanf("%d", ptr);
        ptr++;
    }
    // find largest and smallest number
    int largest = *arr;
    int smallest = *arr;
    int largestIndex = 0;
    int smallestIndex = 0;
    for (int i = 1; i < n; i++)
    {
        // find largest
        if (*(arr + i) > largest)
        {
            largest = *(arr + i);
            largestIndex = i;
        }
        // find smallest
        if (*(arr + i) < smallest)
        {
            smallest = *(arr + i);
            smallestIndex = i;
        }
    }
    // print value
    printg(arr + largestIndex);
    putchar(' ');
    // print index
    printg(&largestIndex);
    putchar('\n');
    // print value
    printg(arr + smallestIndex);
    putchar(' ');
    // print index
    printg(&smallestIndex);

    // free memory
    free(arr);
    return 0;
}