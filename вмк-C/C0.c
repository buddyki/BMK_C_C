#include<stdio.h>
#include<stdlib.h> //<- malloc()
void Swap_max_min(int *arr,int N){
	int i,imax,imin,tmp;
	imax=imin=0;
	for(i=1;i<N;i++)
	{
		if(arr[i]>arr[imax])
			imax=i;
		if(arr[i]<arr[imin])
			imin=i;
	}
	tmp=arr[imax];
	arr[imax]=arr[imin];
	arr[imin]=tmp;
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
	printf("\n");
        Swap_max_min(arr,N);
	for(i=0;i<N;i++)
		printf("%d ",arr[i]);
	//printf("\n");
	free(arr);
	return 0;
}
