#include <stdio.h>

struct Date{
    unsigned year;
    unsigned month;
    unsigned day;
};

int j=0;
struct Date D[300],T[20];

void testtime(struct Date D[],struct Date T[],int i)
{
    int test=0;
    if(1<=D[i].month && D[i].month<=12)
    {
        //判断日期为31天的月份
        if(D[i].month==1 || D[i].month==3 || D[i].month==5 || D[i].month==7 || D[i].month==8 || D[i].month==10 || D[i].month==12)
        {
            if(D[i].day>=1 && D[i].day<=31)
            {
                test=test+1;
            }
         //判断日期为30天的月份
        }else if(D[i].month==4 || D[i].month==6 || D[i].month==9 || D[i].month==11)
        {
            if(D[i].day>=1 && D[i].day<=30)
            {
                test=test+1;
            }
           //判断闰年和平年，闰年2月29天，平年2月28天
           //闰年的判断法
           //非整百年，能被 44 整除的为闰年。
		   //整百年，能被 400400 整除的是闰年。
        }else if(D[i].year%100!=0 && D[i].year%4==0 || D[i].year%400==0)
        {
             if(D[i].day>=1 && D[i].day<=29)
            {
                test=test+1;
            }
            
        }else if(D[i].day>=1 && D[i].day<=28)
            {
                 test=test+1;
            }
 
    }
    
    if (j>19) return;
    //printf("test=%d j=%d\n",test,j);
    if(test == 1 )
    {
        T[j].year=D[i].year;
        T[j].month=D[i].month;
        T[j].day=D[i].day;
        j=j+1;
    }
    
}

void sort(struct Date T[],int i,int m)
{
    int tmp;
    
    tmp=T[i].year;
    T[i].year=T[m].year;
    T[m].year=tmp;
    
    tmp=T[i].month;
    T[i].month=T[m].month;
    T[m].month=tmp;
    
    tmp=T[i].day;
    T[i].day=T[m].day;
    T[m].day=tmp;
    
}

void output(struct Date T[],int count)
{
    int i,m,tmp;
    for(i=0;i<count;i++)
    {
        for(m=i+1;m<count;m++)
        {
            if(T[m].year < T[i].year) 
                sort(T,i,m);
            
            if(T[m].year == T[i].year) 
            {
                if(T[m].month < T[i].month) 
                    sort(T,i,m);
        
                if(T[m].month == T[i].month) 
                {
                    if(T[m].day < T[i].day)
                        sort(T,i,m);
                }
            }
        }
        
    }
    
    for(i=0;i<count;i++)
    {
        printf("%04d %02d %02d\n",T[i].year,T[i].month,T[i].day);
    }
    
}

int main()
{
    int i=0,count;
    while( scanf("%d %d %d",&D[i].year,&D[i].month,&D[i].day) != EOF)
    {
        i++;
    }
    count=i;
    
    for(i=0;i<count;i++)
    {    
        testtime(D,T,i);
        //printf("j=%d\n",j);
    }    
    
    count=j;
    // for(i=0;i<count;i++)
    // {
    //     printf("t=%04d %02d %02d\n",T[i].year,T[i].month,T[i].day);
    // }
    //printf("\n");
    output(T,count);
    
    
    return 0;
}
