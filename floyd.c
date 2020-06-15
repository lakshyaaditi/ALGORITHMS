#include <stdio.h>

int min(int a, int b)
{
    if(a<b)
        return a;
    else
        return b;
}

void main()
{
    int n;
    int i,j,k;
    printf("\n Enter the number of vertices:");
    scanf("%d",&n);
    int A[n][n];
    printf("\n Enter the weight matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        scanf("%d",&A[i][j]);
        for(k=0;k<n;k++)
            for(i=0;i<n;i++)
            for(j=0;j<n;j++)
            A[i][j]=min((A[i][j]), ((A[i][k])+(A[k][j])));
        printf("\n Shortest path matrix: \n");
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
                printf("%d\t", A[i][j]);
            printf("\n");
        }
}

