// Kamin Jittapassorn 66070503409

#include <stdio.h>
#include <stdlib.h>

int InputMatrix(int **matrix, int n, int m) {
    for (int i = 0; i < n; i++) { // loop through rows
        matrix[i] = (int *) malloc(m * sizeof(int));
        for (int j = 0; j < m; j++) { // loop through columns
            scanf("%d", &matrix[i][j]);
        }
    }
}

int SpiralToArray(int **matrix, int n, int m) {
    // allocate memory for array
    int *array = (int *) malloc(n * m * sizeof(int));
    int arrayIndex = 0;
    int rowStart = 0;
    int rowEnd = n - 1;
    int colStart = 0;
    int colEnd = m - 1;
    // loop through matrix in spiral order
    while (rowStart <= rowEnd && colStart <= colEnd) {
        // print row from left to right
        for (int i = colStart; i <= colEnd; i++) { // loop through columns
            array[arrayIndex++] = matrix[rowStart][i];
        }
        rowStart++;
        // print column from top to bottom
        for (int i = rowStart; i <= rowEnd; i++) { // loop through rows
            array[arrayIndex++] = matrix[i][colEnd];
        }
        colEnd--;
        // print row from right to left
        if (rowStart <= rowEnd) { // check if rowStart <= rowEnd
            for (int i = colEnd; i >= colStart; i--) { // loop through columns
                array[arrayIndex++] = matrix[rowEnd][i];
            }
            rowEnd--;
        }
        // print column from bottom to top
        if (colStart <= colEnd) { // check if colStart <= colEnd
            for (int i = rowEnd; i >= rowStart; i--) { // loop through rows
                array[arrayIndex++] = matrix[i][colStart];
            }
            colStart++;
        }
    }
    // print array
    for (int i = 0; i < n * m; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    // free memory
    free(array);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    // allocate memory for matrix
    int **matrix = (int **) malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        matrix[i] = (int *) malloc(m * sizeof(int));
    }
    // get input matrix
    InputMatrix(matrix, n, m);
    // print spiral array
    SpiralToArray(matrix, n, m);
    // free memory
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    return 0;
}