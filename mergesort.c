#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
    i = j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }
    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }}
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
    mergeSort(a, 0, n - 1);
    end = clock();
    printf("\n\nSorted Array\n");
    for (i = 0; i < n; i++) {
        printf("%d\t",a[i]);
    }
    total = (double)(end-start)/CLOCKS_PER_SEC;
    printf("\n\nTime taken : %lf", total); }

