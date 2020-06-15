#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high- 1; j++) {
        if (arr[j] < pivot) {
            swap(&arr[++i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

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
    quickSort(a, 0, n - 1);
    end = clock();

    printf("\n\nSorted Array\n");
    for (i = 0; i < n; i++) {
        printf("%d\t",a[i]);
    }

    total = (double)(end-start)/CLOCKS_PER_SEC;
    printf("\n\nTime taken : %lf", total);
}

