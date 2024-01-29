// Kamin Jittapassorn 66070503409

#include <stdio.h>
#include <limits.h>

#define MAX 100

int minJumps(int start, int end, int arr[], int size) {
    if (start == end) { // base case
        return 0;
    }
    if (arr[start] == 0) { // base case 
        return INT_MAX;
    }
    int min = INT_MAX; // initialize min value
    // traverse through all the points reachable from arr[start]
    /* Recursively get the minimum number of jumps needed to reach arr[end] from these reachable points.
     If a reachable point finally reaches arr[end], update min.
    */
   for (int i = start + 1; i <= end && i <= start + arr[start]; i++) { 
        int jumps = minJumps(i, end, arr, size); 
        if (jumps != INT_MAX && jumps + 1 < min) { // check if jumps + 1 is less than min
            min = jumps + 1; // update min
        }
    }
    return min;
}

int main() {
    int n;
    // get number of elements
    scanf("%d", &n);
    int arr[n];
    // get elements
    for (int i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }
    // print result
    int result = minJumps(0, n - 1, arr, n);
    if (result == INT_MAX) {
        printf("Not possible\n");
    } else {
        printf("%d\n", result);
    }
}