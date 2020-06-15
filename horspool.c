#include <stdio.h>
#include <string.h>
#define MAX 500
int t[MAX];

void shiftable(char p[])
{
	int i,j,m;
	m=strlen(p);
	for(i=0;i<MAX;i++)
		t[i]=m;
	for(j=0;j<m-1;j++)
		t[p[j]]=m-1-j;
}

int horspool(char a[], char p[])
{
	int i,j,k,m,n;
	n=strlen(a);
	m=strlen(p);
	i=m-1;
	while(i<n)
	{
		k=0;
	    while((k<m) && (p[m-1-k]==a[i-k]))
		    k=k+1;
	    if(k==m)
	        return (i-m+1);
	    else
		    i+=t[a[i]];
    }
    return -1;
}

void main()
{
	int pos;
	char p[100], a[100];
	printf("Enter the text in which pattern is to be searched\n");
	gets(a);
	printf("Enter the pattern to be searched\n");
	gets(p);
	shiftable(p);
	pos=horspool(a,p);
	if(pos>=0)
		printf("\nFound at %d",pos);
	else
		printf("\nNot Found");
}

