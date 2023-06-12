#include<stdio.h>
#include<stdlib.h> //<- malloc()
int j=0;
void choose(int *arr,int *brr,int N){
 int i;
    for(i=0;i<N;i++){
        //printf("%d\n",arr[i]%100);
        if(arr[i]%100 < 10)
        {
            brr[j]=arr[i];
            j++;
            //printf("j=%d",j);
        }
    }
}

int main(){
    int N,i;
     int *arr,*brr;//maccив
     scanf("%d",&N);
     arr=(int*)malloc(N*sizeof(int));
     
     if(arr == NULL){
        printf("Error:can't allocate memory\n");
        return 1;
     }
    for(i=0;i<N;i++)
        scanf("%d",arr+i);
        
    brr=(int*)malloc(N*sizeof(int));
    
    if(arr == NULL){
        printf("Error:can't allocate memory\n");
        return 1;
     }
    choose(arr,brr,N);
    
    for(i=0;i<j;i++)
    {
       printf("%d ",brr[i]);
    }
     
     free(arr);
     free(brr);
     return 0;
}