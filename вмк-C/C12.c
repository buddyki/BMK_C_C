#include<stdio.h>
#include<string.h>

struct color
{
	char name[20];//имя цвета
	int count;// сколько раз встретили цвет
};
int main()
{
	struct color white={"WHITE",0}; //name <- WHITE count <-0
	struct color black={"BLACK",0};
	struct color other={"OTHER",0};
	char buf[20];
	while(scanf("%19s",buf) != EOF) //пока есть слова
	{
		if(!strcmp(white.name,buf)) //если buf =="WHITE"
			white.count++;  //счетчик белого увеличить
		else if(!strcmp(black.name,buf)) //если buf == "BLACK"
			black.count++;
		else
		{ other.count++;}
	}
	printf("%s %d\n",white.name, white.count);
	printf("%s %d\n",black.name, black.count);
	printf("%s %d\n",other.name, other.count);
	return 0;
}
