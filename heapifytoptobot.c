#include <stdio.h>

struct PriorityQueue {
    int a[100]; // Assuming a fixed size for the array
};

int main() {
    int n;
    printf("Enter the size: ");
    scanf("%d", &n);

    struct PriorityQueue *pq; // Declare a pointer to the struct
    pq = malloc(sizeof(struct PriorityQueue)); // Allocate memory for the struct

    printf("\nEnter the elements:\n");
    int i;
    for (i= 0; i < n; i++) {
        scanf("%d", &pq->a[i]);
    }

    int ele, p, c;
    for (i = n - 1; i >= 0; i--) {
        ele = pq->a[i];
        pq->a[i] = pq->a[0];
        p = 0;

        if (i == 1)
            c = -1;
        else
            c = 1;

        if (i > 2 && pq->a[2] > pq->a[1])
            c = 2;

        while (c >= 0 && pq->a[c] < ele) {
            pq->a[p] = pq->a[c];
            p = c;
            c = 2 * p + 1;
            if (c + 1 <= i - 1 && pq->a[c + 1] > pq->a[c])
                c = c + 1;
            if (c > i - 1)
                c = -1;
        }
        pq->a[p] = ele;
    }

    printf("\nSorted elements (Heap sort):\n");
for (i = n - 1; i >= 0; i--) {
    printf("%d ", pq->a[i]);
}
    printf("\n");

    free(pq);// Free the allocated memory for the struct

    return 0;
}