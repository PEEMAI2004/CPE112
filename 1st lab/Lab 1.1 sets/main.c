#include <stdio.h>

int main() {
    //first line get number of elements
    int n;
    scanf("%d", &n);
    //2nd line get elements of set A
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    // remove duplicates
    int b[n];
    int k = 0;
    for (int i = 0; i < n; i++) {
        int flag = 0;
        for (int j = 0; j < k; j++) {
            if (a[i] == b[j]) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            b[k] = a[i];
            k++;
        }
    }
    // k is the number of elements in set B
    // print number of elements in set B
    printf("%d\n", k);
    // print elements of set B
    for (int i = 0; i < k; i++) {
        printf("%d ", b[i]);
    }
}