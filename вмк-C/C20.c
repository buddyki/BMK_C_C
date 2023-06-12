#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(int argc,char**argv)
{
	FILE *fi;
	FILE *fo;
	int buf;
	int count,n;
	if(argc < 4)
	{
		fprintf(stderr,"Use: %s inpur_file output_file n\n",argv[0]);
		return 1;
	}
	fi = fopen(argv[1],"r");
	if(fi==NULL)
	{
		fprintf(stderr,"Can;t open file %s\n",argv[1]);
		return 2;
	}
	fo=fopen(argv[2],"w");
	if(fo==NULL)
	{
		fprintf(stderr,"Can't open file %s\n",argv[2]);
		return 3;
	}
	n = atoi(argv[3]);
	count=0;
	while((buf=fgetc(fi)) !=EOF && count <n)
	{
		if(buf == '\n')
			count++;
		fputc(buf,fo);
	}
	fclose(fi);
	fclose(fo);
	return 0;
}