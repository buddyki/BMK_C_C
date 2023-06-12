#include <stdio.h>
#include<math.h>
struct vector{
    double x;
    double y;
    double z;
};

void area(struct vector m,struct vector n)
{
    double i,j,k,sum;
    i=(m.y)*(n.z)-(m.z)*(n.y);
    i=i*i;
    j=(m.x)*(n.z)-(m.z)*(n.x);
    j=j*j;
    k=(m.x)*(n.y)-(m.y)*(n.x);
    k=k*k;
    sum=sqrt(i+j+k);
    printf("%.4f",sum);
    
}



int main()
{
    struct vector v1,v2;
    scanf("%le %le %le",&v1.x,&v1.y,&v1.z);
    scanf("%le %le %le",&v2.x,&v2.y,&v2.z);
    area(v1,v2);
    
}