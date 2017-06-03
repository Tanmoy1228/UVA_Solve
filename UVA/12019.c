#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int m,d,i,j,x=0,y,k=0;
        int a[12]={31,28,31,30,31,30,31,31,30,31,30,31};
        scanf("%d %d",&m,&d);
        for(i=0;i<m-1;i++)
        {
            x=x+a[i];
        }
        y=x+d;
        if(y%7==4)
        {
            printf("Tuesday\n");
            continue;
        }
        else if(y%7==5)
        {
            printf("Wednesday\n");
            continue;
        }
        else if(y%7==6)
        {
            printf("Thursday\n");
            continue;
        }
        else if(y%7==0)
        {
            printf("Friday\n");
            continue;
        }
        else if(y%7==1)
        {
            printf("Saturday\n");
            continue;
        }
        else if(y%7==2)
        {
            printf("Sunday\n");
            continue;
        }
        else if(y%7==3)
        {
            printf("Monday\n");
            continue;
        }
    }
    return 0;
}


