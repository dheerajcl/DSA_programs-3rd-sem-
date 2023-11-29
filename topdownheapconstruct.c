#include <stdio.h>
#define MAX 50
int main()
{
    int a[MAX];
    int i, c, p, n, elt;
    printf("enter the number of elements\n");
    scanf("%d", &n);
    printf("enter the elements\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    // Heapify
    for (i = 1; i < n; i++)
    {
        elt = a[i];
        c = i;
        p = (c - 1) / 2;
        while (c > 0 && a[p] < elt)
        {
            a[c] = a[p];
            c = p;
            p = (c - 1) / 2;
        }
        a[c] = elt;
    }
    // display heapified elements
    printf("\nElements of heap:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    // Heap sort
    for (i = n - 1; i > 0; i--)
    {
        elt = a[i];
        a[i] = a[0];
        p = 0;
        if (i == 1)
            c = -1;
        else
            c = 1;
        if (i > 2 && a[2] > a[1])
            c = 2;
        while (c >= 0 && elt < a[c])
        {
            a[p] = a[c];
            p = c;
            c = 2 * p + 1;
            if (c + 1 <= i - 1 && a[c] < a[c + 1])
                c = c + 1;
            if (c > i - 1)
                c = -1;
        }
        a[p] = elt;
    }
    printf("\nSorted elements(Heap sort):\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}