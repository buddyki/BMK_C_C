#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[]) 
{
	int num;
	num=atoi(argv[2]);
	
	int i=0; //计数
    double n,count; //存数
    if (strcmp(argv[1], "sum") == 0) 
	{
	    count=0;
		for (i = 0; i < argc - 3 && i < num; i++)  //i < argc - 3 -> EOF 
		{
			sscanf(argv[3 + i], "%lf", &n); 
			count = count + n;
		}
	}
	
	if (strcmp(argv[1], "mul") == 0) 
	{
	    count=1;
		for (i = 0; i < argc - 3 && i < num; i++) 
		{
			sscanf(argv[3 + i], "%lf", &n); 
			count = count * n;
		}

	}
    
	printf("%.3lf\n",count);
	return 0;
}