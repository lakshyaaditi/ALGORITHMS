#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main() {
    int i,n,j,temp;
    clock_t start, end;
    double total;
    printf("\nEnter no of elements :");
    scanf("%d", &n);
    int a[n];

    printf("\n\nUnSorted Array\n");
    for (i = 0; i < n; i++) {
        a[i] = rand();
        printf("%d\t",a[i]);
    }
    start = clock();
    for (i = 0; i < n-1; i++) {
        for(j = 0; j < n-i-1; j++) {
            if (a[j+1] < a[j]) {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    end = clock();
    printf("\n\nSorted Array\n");
    for (i = 0; i < n; i++) {
        printf("%d\t",a[i]);
    }

    total = (double)(end-start)/CLOCKS_PER_SEC;
    printf("\n\nTime taken : %lf", total);
}

