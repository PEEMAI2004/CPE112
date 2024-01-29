// Kamin Jittapassorn 66070503409
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000000

int main()
{
    long long p = 0;
    long long q = 0;

    // allocate memory for elements
    for (int i = 0; i <= MAX; i++)
    {
        long long *ptr = (long long *)malloc(sizeof(long long));
        *ptr = p;
        *ptr += i;
        p = *ptr;
        free(ptr);
    }

    // allocate memory for elements
    for (int i = 0; i <= MAX; i++)
    {
        long long *ptr = (long long *)malloc(sizeof(long long));
        *ptr = q;
        *ptr -= i;
        q = *ptr;
        free(ptr);
    }
    printf("%lld \n%lld ", p, q);
}