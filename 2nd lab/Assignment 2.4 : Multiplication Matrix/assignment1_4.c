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

int MultiplyMatrix(int **matrix1, int **matrix2, int n1, int m1, int n2, int m2) {
    int **result = (int **) malloc(n1 * sizeof(int *));
    for (int i = 0; i < n1; i++) {
        result[i] = (int *) malloc(m2 * sizeof(int));
    }
    // multiply matrix
    for (int i = 0; i < n1; i++) { // loop through rows
        for (int j = 0; j < m2; j++) { // loop through columns
            result[i][j] = 0;
            for (int k = 0; k < m1; k++) { // loop through columns of matrix 1
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    // copy result to matrix1
    for (int i = 0; i < n1; i++) { // loop through rows
        for (int j = 0; j < m2; j++) { // loop through columns
            matrix1[i][j] = result[i][j];
        }
    }
    // free memory
    for (int i = 0; i < n1; i++) {
        free(result[i]);
    }
}

int main() {
    int n1, m1, n2, m2;
    // get number of rows and columns of matrix 1
    scanf("%d %d", &n1, &m1);
    // allocate memory for matrix 1
    int **matrix1 = (int **) malloc(n1 * sizeof(int *));
    for (int i = 0; i < n1; i++) {
        matrix1[i] = (int *) malloc(m1 * sizeof(int));
    }
    // get input matrix 1
    InputMatrix(matrix1, n1, m1);
    // get number of rows and columns of matrix 2
    scanf("%d %d", &n2, &m2);
    // allocate memory for matrix 2
    int **matrix2 = (int **) malloc(n2 * sizeof(int *));
    for (int i = 0; i < n2; i++) {
        matrix2[i] = (int *) malloc(m2 * sizeof(int));
    }
    // get input matrix 2
    InputMatrix(matrix2, n2, m2);

    // check if matrix 1 and matrix 2 can be multiplied
    if (m1 != n2) {
        printf("Not Compatible\n");
        return 0;
    }
    // multiply matrix 1 and matrix 2
    MultiplyMatrix(matrix1, matrix2, n1, m1, n2, m2);
    // print result
    for (int i = 0; i < n1; i++) { // loop through rows
        for (int j = 0; j < m2; j++) { // loop through columns
            printf("%d ", matrix1[i][j]);
        }
        printf("\n");
    }
    // free memory
    for (int i = 0; i < n1; i++) {
        free(matrix1[i]);
    }
    for (int i = 0; i < n2; i++) {
        free(matrix2[i]);
    }
    return 0;
}