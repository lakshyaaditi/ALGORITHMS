#include<stdio.h>
#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))

void knapsack(int m, int n, int w[], int p[]) {
  int v[100][200], x[10], i, j, sum = 0;
  for (i = 0; i <= m; i++)
    v[0][i] = 0;
  for (i = 0; i <= m; i++)
    v[0][i] = 0;
  for (i = 1; i <= n; i++) {
    for (j = 0; j <= m; j++) {
      if (j >= w[i])
        v[i][j] = MAX(v[i - 1][j], v[i - 1][j - w[i]] + p[i]);
      else
        v[i][j] = v[i - 1][j];
    }
  }
  for (i = 1; i <= n; i++)
    x[i] = 0;
  i = n;
  j = m;
  while (i > 0 && j > 0) {
    if (v[i][j] != v[i - 1][j]) {
      x[i] = 1;
      j = j - w[i];
    }
    i--;
  }
  printf("\nThe optimal set of items is:\n");
  for (i = 1; i <= n; i++) {
    if (x[i] == 1) {
      printf("%d\t", i);
      sum = sum + p[i];
    }
  }
  printf("\n\nTotal profit = %d", sum);
}

void main() {
  int w[10], p[10], m, n, i;
  printf("\nEnter no of items:");
  scanf("%d", &n);
  printf("\nEnter the weights of the items:\n");
  for (i = 1; i <= n; i++)
    scanf("%d", &w[i]);
  printf("\nEnter the profits:\n");
  for (i = 1; i <= n; i++)
    scanf("%d", &p[i]);
  printf("\nEnter the capacity of knapsack:");
  scanf("%d", &m);
  knapsack(m, n, w, p);
}
