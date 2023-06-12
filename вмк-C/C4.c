#include <stdio.h>
#include<stdlib.h>

void sort(int *arr,int N)
{
	int i,j,tmp;
	for(i=0;i<N;i++)
	{
	    for(j=i+1;j<N;j++)
	    {
	        if(arr[i]>arr[j])
	        {
	            tmp=arr[i];
	            arr[i]=arr[j];
	            arr[j]=tmp;
	        }
	    }
	}
}

int main()
{
    char ch;
    int *arr;
    int n=0,sum=0,i=0,j;
    int num=100;
    arr=(int*)malloc(num*sizeof(int));
    if(arr == NULL){
        printf("Error:can't allocate memory\n");
        return 1;
    }
    
    ch=getchar();
    while(ch!= EOF && ch !='\n')
    {
        if(ch >= '0' && ch <= '9')
        {
                while(ch >= '0' && ch <= '9')
                {
                    arr[i]=10*arr[i]+(ch-'0');
                    ch=getchar();
                }
            
            i++;
            if(i==num)
            {
                int *ar;
                num*=10;
                ar=(int*)realloc(arr,num*sizeof(int));
                
                if(ar == NULL)
                {
                    printf("Error:can't allocate memory\n");
                    return 1;
                }
                else arr=ar;
            }
        }
        ch=getchar();
        
    }
    
    j=i;
    sort(arr,j);
    for(i=0;i<j;i++)
	{
	    //printf("a[%d]=%d\n",i,arr[i]);
	    printf("%d ",arr[i]);
	}
    free(arr);
    return 0;
}