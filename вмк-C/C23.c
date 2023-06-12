#include<stdio.h>

int main(int argc,char **argv)
{
    FILE *fi;
    FILE *fo;
    int num_buf;

    if (argc < 3)
    {
       fprintf(stderr,"Use: %s text_file bin_file\n",argv[0]);
       return 1;
    }
    fi = fopen(argv[1],"r");
    
    if (fi == NULL)
    {
       fprintf(stderr,"Can't open file %s\n",argv[1]);
       return 1;
    }
    
    fo = fopen(argv[2],"w");
    if (fo == NULL)
    {
       fprintf(stderr, "Can't open file %s\n",argv[2]);
       return 1;
    }
    
    while(fread(&num_buf,sizeof(int),1,fi) == 1)
    fprintf(fo,"%d ",num_buf);
    fclose(fi);
    fclose(fo);
    return 0;
}
