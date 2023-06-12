#include<stdio.h>
#include<stdlib.h> //<- malloc()
void sort(int *arr,int N){
	int i,j,tmp;
	for(i=0;i<N;i++){
	    for(j=i+1;j<N;j++){
	        if(arr[i]>arr[j]){
	            tmp=arr[i];
	            arr[i]=arr[j];
	            arr[j]=tmp;
	        }
	    }
	}
}
int main(){
	int N,i;
	int *arr;//maccив
	scanf("%d",&N);
	arr=(int*)malloc(N*sizeof(int));
	if(arr == NULL){
		printf("Error:can't allocate memory\n");
		return 1;
	}
	for(i=0;i<N;i++)
		scanf("%d",arr+i);
		
    sort(arr,N);
	for(i=0;i<N;i++)
	{
	    //printf("a[%d]=%d\n",i,arr[i]);
	    if(arr[i+1]-arr[i]!=1) {
	          printf("%d",arr[i]+1);
	          break;
	    }
	}
		
	free(arr);
	return 0;
}