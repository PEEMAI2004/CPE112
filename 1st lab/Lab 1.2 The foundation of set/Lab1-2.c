#include <stdio.h>

void printSet(int set[], int size) {
    // sort set
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; ++j) {
            if (set[i] > set[j]) {
                int temp = set[i];
                set[i] = set[j];
                set[j] = temp;
            }
        }
    }
    // print set
    if (size == 0) {
        printf("empty");
    } else {
        for (int i = 0; i < size; i++) {
            printf("%d ", set[i]);
        }
    }
    printf("\n");
}

int main() {
    // 1st line get Two integers m,n in which -10,000 ≤ m < n ≤ 10,000 as the range of the universe.
    int m, n;
    scanf("%d %d", &m, &n);
    if (m < -10000 || m >= n || n > 10000) {
        printf("Invalid input");
        return 0;
    }

    // 2nd line get An integer p in which 0 ≤ p ≤100, stating the number of elements in an array A
    int p;
    scanf("%d", &p);

    // 3rd line get A sequence of non-decreasing order array A of integer a1,a2 … ap separating between element with a whitespace.
    int a[p];
    for (int i = 0; i < p; i++) {
        scanf("%d", &a[i]);
    }

    // 4th line get An integer q in which 0 ≤ q ≤ 100, stating the number of elements in an array B
    int q;
    scanf("%d", &q);

    // 5th line get A sequence of non-decreasing order array B of integer b1,b2 … bq separating between element with a whitespace.
    int b[q];
    for (int i = 0; i < q; i++) {
        scanf("%d", &b[i]);
    }

    // output

    // 1st line The set SA which is equivalent to array A and is a subset of the universe.
    int sa[p];
    int k = 0;
    for (int i = 0; i < p; i++) {
        int flag = 0;
        for (int j = 0; j < k; j++) {
            if (a[i] == sa[j]) {
                flag = 1;
                break;
            }
        }
        if (flag == 0 && a[i] >= m && a[i] <= n) {
            sa[k] = a[i];
            k++;
        }
    }
    printSet(sa, k);

    // 2nd line The set SB which is equivalent to array B and is a subset of the universe.
    int sb[q];
    int l = 0;
    for (int i = 0; i < q; i++) {
        int flag = 0;
        for (int j = 0; j < l; j++) {
            if (b[i] == sb[j]) {
                flag = 1;
                break;
            }
        }
        if (flag == 0 && b[i] >= m && b[i] <= n) {
            sb[l] = b[i];
            l++;
        }
    }
    printSet(sb, l);

    // 3rd line The result from applying “Union” (SA∪SB)
    int unionSet[k + l];
    int unionSetSize = 0;
    // add sa to unionSet
    for (int i = 0; i < k; i++) {
        unionSet[unionSetSize] = sa[i];
        unionSetSize++;
    }
    // add sb to unionSet if not exist in unionSet
    for (int i = 0; i < l; i++) {
        int flag = 0;
        for (int j = 0; j < unionSetSize; j++) {
            if (sb[i] == unionSet[j]) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            unionSet[unionSetSize] = sb[i];
            unionSetSize++;
        }
    }
    // sort unionSet
    for (int i = 0; i < unionSetSize; i++) {
        for (int j = i + 1; j < unionSetSize; j++) {
            if (unionSet[i] > unionSet[j]) {
                int temp = unionSet[i];
                unionSet[i] = unionSet[j];
                unionSet[j] = temp;
            }
        }
    }
    printSet(unionSet, unionSetSize);

    // 4th line The result from applying “Intersection” (SA∩SB)
    int intersectionSet[k + l];
    int intersectionSetSize = 0;
    // add sa to intersectionSet if exist in sb
    for (int i = 0; i < k; i++) {
        int flag = 0;
        // check if sa[i] exist in sb
        for (int j = 0; j < l; j++) {
            if (sa[i] == sb[j]) {
                flag = 1;
                break;
            }
        }
        // if exist add to intersectionSet
        if (flag == 1) {
            intersectionSet[intersectionSetSize] = sa[i];
            intersectionSetSize++;
        }
    }
    printSet(intersectionSet, intersectionSetSize);

    // 5th line The result from applying “Difference” (SA-SB)
    int differenceSet[k];
    int differenceSetSize = 0;
    // add sa to differenceSet if not exist in sb
    for (int i = 0; i < k; i++) {
        int flag = 0;
        // check if sa[i] exist in sb
        for (int j = 0; j < l; j++) {
            if (sa[i] == sb[j]) {
                flag = 1;
                break;
            }
        }
        // if not exist add to differenceSet
        if (flag == 0) {
            differenceSet[differenceSetSize] = sa[i];
            differenceSetSize++;
        }
    }
    printSet(differenceSet, differenceSetSize);

    // 6th line The result from applying “Difference” (SB)
    int differenceSet2[l];
    int differenceSetSize2 = 0;
    // add sb to differenceSet if not exist in sa
    for (int i = 0; i < l; i++) {
        int flag = 0;
        // check if sb[i] exist in sa
        for (int j = 0; j < k; j++) {
            if (sb[i] == sa[j]) {
                flag = 1;
                break;
            }
        }
        // if not exist add to differenceSet
        if (flag == 0) {
            differenceSet2[differenceSetSize2] = sb[i];
            differenceSetSize2++;
        }
    }
    printSet(differenceSet2, differenceSetSize2);

    // 7th line The result from applying “Complement” (SA)
    int complementSet[k];
    int complementSetSize = 0;
    // add sa to complementSet if not exist in universe
    for (int i = m; i <= n; i++) {
        int flag = 0;
        // check if sa[i] exist in universe
        for (int j = 0; j < k; j++) {
            if (i == sa[j]) {
                flag = 1;
                break;
            }
        }
        // if not exist add to complementSet
        if (flag == 0) {
            complementSet[complementSetSize] = i;
            complementSetSize++;
        }
    }
    printSet(complementSet, complementSetSize);

    // 8th line The result from applying “Complement” (SB)
    int complementSet2[l];
    int complementSetSize2 = 0;
    // add sb to complementSet if not exist in universe
    for (int i = m; i <= n; i++) {
        int flag = 0;
        // check if sb[i] exist in universe
        for (int j = 0; j < l; j++) {
            if (i == sb[j]) {
                flag = 1;
                break;
            }
        }
        // if not exist add to complementSet
        if (flag == 0) {
            complementSet2[complementSetSize2] = i;
            complementSetSize2++;
        }
    }
    printSet(complementSet2, complementSetSize2);
}
