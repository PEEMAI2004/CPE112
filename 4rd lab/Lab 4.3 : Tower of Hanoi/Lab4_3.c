// Kamin Jittapassorn 66070503409

#include <stdio.h>

void towerOfHanoi(int n, char source, char destination, char auxiliary, int *moves) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, destination);
        (*moves)++;
        return;
    }
    towerOfHanoi(n - 1, source, auxiliary, destination, moves);
    printf("Move disk %d from %c to %c\n", n, source, destination);
    (*moves)++;
    towerOfHanoi(n - 1, auxiliary, destination, source, moves);
}

int main() {
    int n;
    scanf("%d", &n);

    int moves = 0;
    towerOfHanoi(n, 'A', 'C', 'B', &moves);

    printf("Total moves: %d\n", moves);

    return 0;
}
