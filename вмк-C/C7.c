#include<stdio.h>
enum {N =5};

int main ()
{
	int matr[N][N];
	int i,j,sum=0,count=0;
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
			scanf("%d",&matr[i][j]);
			
			
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
		    if(i==j) sum=sum+matr[i][j];
		    
    sum=sum/N;
    //printf("sum=%d",sum);
    
    for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
		    if(matr[i][j]>sum) count++;
	printf("%d",count);
	return 0;
}