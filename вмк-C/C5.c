#include <stdio.h>
#include<stdlib.h>

char* sort(char arr[],int n)
{
    int i,j=0;
    char *brr;
    brr=(char*)malloc(n*sizeof(char));
    for(i=0;i<n;i++)
	{
    	if(arr[i] >= 'a' && arr[i] <= 'z')
    	{
    	    brr[j]=arr[i];
    	    j++;
        }
	}
	for(i=0;i<n;i++)
	{
    	if(arr[i] < 'a')
    	{
    	    brr[j]=arr[i];
    	    j++;
        }
	}
	
// 	for(i=0;i<j;i++)
// 	{
//     	printf("%c",brr[i]);
// 	}
   brr[j]='\0';
   return brr;
   free(brr);
   
   
}


int main()
{
    char *arr,*ptr;
    int n=0,i=0,j,num=10,count=0;
    arr=(char*)malloc(num*sizeof(char));
    
    if(arr == NULL){
        printf("Error:can't allocate memory\n");
        return 1;
    }
    

    while( scanf("%c",arr+count) ==1 ){
        count++;
        if(count == num){
            char *ar;
            num=num*5;
            ar=(char*)realloc(arr,num*sizeof(char));
            if(ar == NULL)
            {
                printf("Error:can't allocate memory\n");
                return 1;
            }
            else arr=ar;
        }
    }
    //printf("n=%d",n);
    ptr=sort(arr,count-1);
    printf("%s",ptr);
    free(arr);
    return 0;
}