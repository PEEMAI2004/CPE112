// Kamin Jittapassorn 66070503409
#include <stdio.h>
#include <stdlib.h>
void printArray (int arr[], int size);
int* insertArray(int* arr, int* size, int index, int value);
int* deleteArray(int* arr, int* size, int index);
int* mergeArray(int* arr1, int* size1, int* arr2, int* size2);

int main() {
    int n1, n2;
    scanf("%d", &n1); // Read the number of elements in the 1st array
    int* arr1 = malloc(n1 * sizeof(int));
    for (int i = 0; i < n1; i++) {
        scanf("%d", &arr1[i]); // Read the elements of the 1st array
    }

    scanf("%d", &n2); // Read the number of elements in the 2nd array
    int* arr2 = malloc(n2 * sizeof(int));
    for (int i = 0; i < n2; i++) {
        scanf("%d", &arr2[i]); // Read the elements of the 2nd array
    }

    int insertIndex;
    scanf("%d", &insertIndex); // Read the index for insertion

    int insertValue;
    scanf("%d", &insertValue); // Read the value to insert

    int deleteIndex;
    scanf("%d", &deleteIndex); // Read the index for deletion
    
    // Print the 1st array
    arr1 = insertArray(arr1, &n1, insertIndex, insertValue);
    // Print the 2nd array
    arr1 = deleteArray(arr1, &n1, deleteIndex);
    // Print the merged array
    arr1 = mergeArray(arr1, &n1, arr2, &n2);

    // Free the allocated memory
    free(arr1);
    free(arr2);

    return 0;
}

int* insertArray(int* arr, int* size, int index, int value) {
    // Check if the index is valid
    if (index < 0 || index > *size) {
        printf("Index out of bounds\n");
        return arr;
    }
    // Increase the size of the array
    (*size)++;
    // Reallocate memory for the new element
    arr = realloc(arr, (*size) * sizeof(int));
    // Shift the elements to the right
    for (int i = (*size) - 1; i > index; i--) {
        arr[i] = arr[i - 1];
    }
    // Insert the new element
    arr[index] = value;
    // Print the array
    printArray(arr, *size);
    // Modify the size of the array
    

    return arr;
}

int* deleteArray(int* arr, int* size, int index) {
    // Check if the index is valid
    if (index < 0 || index >= *size) {
        printf("Index out of bounds\n");
        return arr;
    }
    // Shift the elements to the left
    for (int i = index; i < (*size) - 1; i++) {
        arr[i] = arr[i + 1];
    }
    // Decrease the size of the array
    (*size)--;
    // Reallocate memory for the new size
    arr = realloc(arr, (*size) * sizeof(int));
    // Print the array
    printArray(arr, *size);

    return arr;
}

int* mergeArray(int* arr1, int* size1, int* arr2, int* size2) {
    // Increase the size of the 1st array
    int newSize = *size1 + *size2;
    arr1 = realloc(arr1, newSize * sizeof(int));
    // Merge the 2 arrays
    for (int i = 0; i < *size2; i++) {
        arr1[*size1 + i] = arr2[i];
    }
    // Print the array
    printArray(arr1, newSize);

    return arr1;
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
