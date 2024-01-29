// Kamin Jittapassorn 66070503409
#include <stdio.h>
#include <stdlib.h>

void sliceArray(int *arr, int *size, int start, int end, int step);

int main()
{
    int n;
    // 1st line get the number of elements in the array
    scanf("%d", &n);
    // 2nd line get the elements of the array
    int *arr = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    // 3rd line get the start , end and step of the slice
    int start, end, step;
    scanf("%d %d %d", &start, &end, &step);

    // if step is negative then swap start and end and make step positive
    if (step < 0)
    {
        int temp = start;
        start = end;
        end = temp;
        step = -step;
    }

    // Call the sliceArray function
    sliceArray(arr, &n, start, end, step);

    // Free the allocated memory
    free(arr);

    return 0;
}

void sliceArray(int *arr, int *size, int start, int end, int step)
{
    // Check if start and end are in the range of the array
    if (end < arr[0] || start > arr[*size - 1])
    {
        printf("empty");
        return;
    }
    // calculate total steps
    int totalStep = (end - start) / step;
    // print the elements
    int flag = 0;
    for (int i = 0; i < totalStep; i++)
    {
        if (start + i * step < arr[0])
        {
            continue;
        }
        else if (start + i * step > arr[*size - 1])
        {
            break;
        }
        else
        {
            printf("%d ", arr[start + i * step]);
            flag = 1;
        }
    }
    // if no element print empty
    if (flag == 0)
    {
        printf("empty");
    }
    
}