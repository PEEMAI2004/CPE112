// Kamin Jittapassorn 66070503409
#include <stdio.h>
int main() {
    int rows, cols;
    scanf("%d %d", &rows, &cols);

    if (rows != cols) {
        printf("ERROR\n");
        return 0;
    }

    int matrix[rows][cols];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int primarySum = 0;
    int secondarySum = 0;
    for (int i = 0; i < rows; i++) {
        primarySum += matrix[i][i];
        secondarySum += matrix[i][cols - i - 1];
    }

    printf("Primary: %d\n", primarySum);
    printf("Secondary: %d\n", secondarySum);

    return 0;
}
