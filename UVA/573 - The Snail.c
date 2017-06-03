#include<stdio.h>
//#include<iostream>
//#include<cstdio>
//using namespace std;
int main()
{
    double i=0,x,y;
    int h,u,d,f,k;
    while(scanf("%d %d %d %d",&h,&u,&d,&f)==4 && h!=0)
    {
        i=0;
        k=1;
        y=u;
        x=(u*f)/100.0;
        while(1)
        {
            if(y>0)
                i=i+y;
            y=y-x;
            if(i>h)
            {
                printf("success on day %d\n",k);
                break;
            }
            if(i>=0 && i<=h)
            {
                i=i-d;
            }
            if(i<0)
            {
                printf("failure on day %d\n",k);
                break;
            }
            k++;
            //printf("%lf %lf %d\n",i,y,k);
        }

    }

    return 0;
}
