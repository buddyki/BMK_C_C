#include <stdio.h>
#include <string.h>
#include<errno.h>


int main(int argc,char *argv[]){
	if(argc < 3)
	{
	    fprintf(stderr,"Use: %s inpur_file output_file n\n",argv[0]);
		return 1;
	}
	int linenum=0;
	int charnum = 0;
	int wordnum=0;
	int end=0;

   //统计文件的字符数、单词数、行数
    FILE *fi= fopen(argv[1], "r"); // 指向文件的指针 
	FILE *fo= fopen(argv[2], "w");
    int c;  // 读取到的字符

    if( fi == NULL ){
        perror(argv[1]);
        return 1;
    }
	if( fo == NULL ){
        perror(argv[2]);
        return 1;
	}

	while ( (c = fgetc(fi) ) != -1)
    {
        if (c == ' ' || c == '\n' )
        {
            wordnum += end;
            end = 0;
            if (c == EOF)
                break;
            if (c == '\n')
                linenum++;
        }
        else
            end = 1;
        charnum++;
    }

    fprintf(fo, "%d %d %d", linenum, wordnum, charnum);

	fclose(fi);
	fclose(fo);
    return 0;
}