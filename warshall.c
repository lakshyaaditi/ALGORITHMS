#include<stdio.h>

    void main() {
	int n,i,j,k;
	printf("\n Enter the number of vertices:");
	scanf("%d",&n);
	int A[n][n];

	printf("\n Enter the adjacency matrix: \n");
	for (i=0;i<n;i++)
		for (j=0;j<n;j++)
		   scanf("%d",&A[i][j]);

        for (k=0;k<n;k++)
	  for (i=0;i<n;i++)
	   for (j=0;j<n;j++)
	    A[i][j] = (A[i][j] || (A[i][k]&&A[k][j]));

	printf("\n Transitive closure: \n");
	for (i=0;i<n;i++) {
		for (j=0;j<n;j++)
		   printf("%d\t",A[i][j]);
		printf("\n");
	}
    }
