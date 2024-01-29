// Kamin Jittapassorn 66070503409
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, start, end, step;
    // get n
    scanf("%d", &n);
    int re_index = -n;
    int *index = (int *)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++)
        *(index + i) = re_index++;

    int *arr = (int *)malloc(n * sizeof(int));
    // get array
    for (int i = 0; i < n; i++)
        scanf("%d", (arr + i));
    // get start, end, step
    scanf("%d %d %d", &start, &end, &step);
    // if start is negative 
    if (start < 0)
    {
        if (start < index[0])
            start = 0; // set start to 0
        for (int i = 0; i < n; i++)
            if (start == *(index + i))
                start = i; // set start to i
    }
    // if end is negative
    if (end < 0)
    {
        if (end < index[0])
            end = 0; // set end to 0
        for (int i = 0; i < n; i++)
            if (end == *(index + i))
                end = i; // set end to i
    }
    if ((start > end && step < 0) || (start < end && step > 0)) // if start > end and step < 0 or start < end and step > 0
    {
        if (start > n) // if start > n
            start = n - 1;
        if (end > n) // if end > n
            end = n;
        if (start < end && step > 0) // if start < end and step > 0
            for (int i = start; i < end; i += step)
                printf("%d ", *(arr + i));
        else if (start > end && step < 0) // if start > end and step < 0
        {
            for (int i = (start); i > end; i += step)
                printf("%d ", *(arr + i));
        }
    }
    else
        printf("empty");
    return 0;
}