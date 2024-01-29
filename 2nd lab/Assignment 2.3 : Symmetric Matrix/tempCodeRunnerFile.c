// Kamin Jittapassorn 66070503409

#include <stdio.h>

int InputMatrix(int **matrix, int n, int m) {
    for (int i = 0; i < n; i++) { // loop through rows
        matrix[i] = (int *) malloc(m * sizeof(int));
        for (int j = 0; j < m; j++) { // loop through columns
            scanf("%d", &matrix[i][j]);
        }
    }
}

int IsSymmetric(int **matrix, int n, int m) {
    int isSymmetric = 1;
    for (int i = 0; i < n && isSymmetric; i++) { // loop through rows
        for (int j = 0; j < m && isSymmetric; j++) { // loop through columns
            if (matrix[i][j] != matrix[j][i]) { // check if matrix[i][j] != matrix[j][i]
                isSymmetric = 0;
            }
        }
    }
    return isSymmetric; // return 1 if symmetric, 0 if not
}

int IsSkewSymmetric(int **matrix, int n, int m) {
    int isSkewSymmetric = 1;
    for (int i = 0; i < n && isSkewSymmetric; i++) { // loop through rows
        for (int j = 0; j < m && isSkewSymmetric; j++) { // loop through columns
            if (matrix[i][j] != -matrix[j][i]) { // check if matrix[i][j] != -matrix[j][i]
                isSkewSymmetric = 0;
            }
        }
    }
    return isSkewSymmetric; // return 1 if skew symmetric, 0 if not
}


int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    if (n != m) {
        printf("None\n");
        return 0;
    }

    // allocate memory for matrix
    int **matrix = (int **) malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        matrix[i] = (int *) malloc(m * sizeof(int));
    }
    // get input matrix
    InputMatrix(matrix, n, m);

    // check if matrix is symmetric
    if (IsSymmetric(matrix, n, m)) {
        printf("Symmetric\n");
    } else if (IsSkewSymmetric(matrix, n, m)) {
        printf("Skew Symmetric\n");
    } else {
        printf("None\n");
    }
}