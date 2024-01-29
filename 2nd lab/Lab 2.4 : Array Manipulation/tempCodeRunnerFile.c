// Kamin Jittapassorn 66070503409
#include <stdio.h>
#include <stdlib.h>

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    // printf("\n");
}

void insertion(int *input, int *size, int index, int value)
{
    // create new array with size + 1
    int *temp = (int *)malloc((*size + 1) * sizeof(int));
    // copy all element from input to temp
    for (int i = 0; i < *size; i++)
    {
        if (i < index) // if i < index copy normally
        {
            *(temp + i) = *(input + i);
        }
        else if (i == index) // if i == index copy value
        {
            *(temp + i) = value;
        }
        else // if i > index copy normally
        {
            *(temp + i) = *(input + i - 1);
        }
    }
    // print temp
    printArray(temp, *size + 1);
    // resize input
    *size = *size + 1;
    // copy temp to input
    for (int i = 0; i < *size; i++)
    {
        *(input + i) = *(temp + i);
    }
    // free temp
    free(temp);
    // Enter new line
    printf("\n");
}

void deletion(int *input, int *size, int index)
{
    // Check if index is in range
    if (index+1 > *size)
    {
        printf("Index out of bounds\n");
        return;
    }
    // create new array with size - 1
    int *temp = (int *)malloc((*size - 1) * sizeof(int));
    // copy all element from input to temp
    for (int i = 0; i < *size; i++)
    {
        if (i < index) // if i < index copy normally
        {
            *(temp + i) = *(input + i);
        }
        else if (i == index) // if i == index skip
        {
            continue;
        }
        else // if i > index copy normally
        {
            *(temp + i - 1) = *(input + i);
        }
    }
    // print temp
    printArray(temp, *size - 1);
    // resize input
    *size = *size - 1;
    // copy temp to input
    for (int i = 0; i < *size; i++)
    {
        *(input + i) = *(temp + i);
    }
    // free temp
    free(temp);
    // Enter new line
    printf("\n");
}

void merge(int *input1, int *input2, int size1, int size2) {
    // create new array with size1 + size2
    int *temp = (int *)malloc((size1 + size2) * sizeof(int));
    // copy all element from input1 to temp
    for (int i = 0; i < size1; i++)
    {
        *(temp + i) = *(input1 + i);
    }
    // copy all element from input2 to temp
    for (int i = 0; i < size2; i++)
    {
        *(temp + i + size1) = *(input2 + i);
    }
    // print temp
    printArray(temp, size1 + size2);
    // free temp
    free(temp);
    // Enter new line
    printf("\n");
}

int main()
{
    int n1, n2;
    scanf("%d", &n1); // Read the number of elements in the 1st array
    int *arr1 = malloc(n1 * sizeof(int));
    for (int i = 0; i < n1; i++)
    {
        scanf("%d", &arr1[i]); // Read the elements of the 1st array
    }

    scanf("%d", &n2); // Read the number of elements in the 2nd array
    int *arr2 = malloc(n2 * sizeof(int));
    for (int i = 0; i < n2; i++)
    {
        scanf("%d", &arr2[i]); // Read the elements of the 2nd array
    }

    int insertIndex;
    scanf("%d", &insertIndex); // Read the index for insertion

    int insertValue;
    scanf("%d", &insertValue); // Read the value to insert

    int deleteIndex;
    scanf("%d", &deleteIndex); // Read the index for deletion

    // Call the insertion function
    insertion(arr1, &n1, insertIndex, insertValue);
    // Call the deletion function
    deletion(arr2, &n2, deleteIndex);
    // Call the merge function
    merge(arr1, arr2, n1, n2);

    free(arr1);
    free(arr2);

    return 0;
}
