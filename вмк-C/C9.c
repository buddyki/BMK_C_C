#include<stdio.h>
#include<stdlib.h>
int sum_max(int **matr,int N,int M);

int main()
{   //matr1:  2*3 row1*col1
	int i,j,row1,col1;
	int **matr1;
	scanf("%d %d",&row1,&col1);
	matr1 = (int**)malloc(row1*sizeof(int*));
	if (matr1 == NULL)
	{
		printf("-1");
		return 0;
	}
	for(i=0;i<row1;i++)
	{
		matr1[i]=(int*)malloc(col1*sizeof(int));
		if(matr1[i]==NULL)
		{
			printf("-1");
            return 0;
		}
	}
	for(i=0;i<row1;i++)
		for(j=0;j<col1;j++)
			scanf("%d",&matr1[i][j]);
			
	//matr2: 3*4 row2*col2
	int row2,col2;
	int **matr2;
	scanf("%d %d",&row2,&col2);
	
	matr2 = (int**)malloc(row2*sizeof(int*));
	if (matr2 == NULL)
	{
		printf("-1");
        return 0;
	}
	for(i=0;i<row2;i++)
	{
		matr2[i]=(int*)malloc(col2*sizeof(int));
		if(matr2[i]==NULL)
		{
			printf("-1");
            return 0;
		}
	}
	for(i=0;i<row2;i++)
		for(j=0;j<col2;j++)
			scanf("%d",&matr2[i][j]);		
	
	//printf("col1=%d row2=%d\n",col1,row2);
	if(col1 != row2)  {printf("-1");return 0;}
	
	//sum=matr1[i][k]*matr2[k][j];
	int k=0;long sum=0;
	for(i=0;i<row1;i++){
	    sum=0;
	    for(int j=0;j<col2;j++){
	        sum=0;
            for(int k=0;k<col1;k++){
                sum=sum+matr1[i][k]*matr2[k][j];
                //printf("%d ",sum);
                //printf("a=%d %d b=%d %d\n",i,k,k,j);
            }
            printf("%ld ",sum);
	        
	    }
	    printf("\n");
	}
		//sum=matr1[i][k]*matr2[k][i];
        // printf("sum=%d ",sum);
		
	for(i=0;i<row1;i++)
		free(matr1[i]);
	free(matr1);
	
	for(i=0;i<row2;i++)
		free(matr2[i]);
	free(matr2);
	return 0;
}