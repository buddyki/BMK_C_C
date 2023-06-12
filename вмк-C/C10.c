#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 3000

void change(char * str, char * str1, char * str2) {
	int i, j, k, test, count = 0, loc = 0;
	char temp[MAXSIZE];
	
	//printf("strlen(str)=%d",strlen(str));
	//printf("strlen(str1)=%d",strlen(str1));
	//printf("strlen(str2)=%d",strlen(str2));
	
	for (i = 0; i < strlen(str); i += loc) {
		if (str[i] == str1[0])  //找 Cao 
		{
			test = 0;
			for (j = i, k = 0; k < strlen(str1); j++, k++)//str1 = 3 - Cao
			{
				if (str[j] != str1[k])  //str1[0-1-2]=C a o;
				{
					test = 1;    //tesk=1 找到了
					loc = k;
					break;
				}
				//printf("loc=%d",loc);
				
			}
			if (test == 0)  // 已找到待替换字符串并替换
			{ 
				for (j = i + strlen(str1), k = 0; j < strlen(str); j++, k++) // 保存原字符串中剩余的字符
				{ 
					temp[k] = str[j];
					//printf("temp[%d]=%c\n",k,temp[k]);
				}
				//printf("\n");
				temp[k] = '\0'; // 将字符数组变成字符串
				
				for (j = i, k = 0; k < strlen(str2); j++, k++)  // 字符串替换
				{ 
					str[j] = str2[k]; //str2[0 1 2 3]-L i n g;
					//printf("str[%d]=%c\n",j,str[j]);
				}
				//printf("\n");
				for (k = 0; k < strlen(temp); j++, k++) { // 剩余字符串回接
					str[j] = temp[k];
				}
				str[j] = '\0'; // 将字符数组变成字符串
				test = strlen(str1);
			}
		}
		else {
			loc = 1;
		}
	}
	return;
}


int main(int argc, char *argv[]) {
	char str[MAXSIZE];
	scanf("%3000[^\n]",str);
    // 	char str1[]="cao";
    // 	char str2[]="ling";
    // 	change(str, str1, str2);
	change(str, argv[1], argv[2]);
	printf("%s\n",str);
	return 0;
}
