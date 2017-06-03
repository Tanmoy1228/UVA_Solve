#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a,b,x,y;
        scanf("%d:%d",&a,&b);
        if(b>0)
        {
            y=60-b;
            x=12-a-1;
        }
        else if(b==0)
        {
            y=0;
            x=12-a;
        }
        if(x<1)
        {
            x=x+12;
        }
        if(x<10)
        {
            printf("0%d:",x);
        }
        else
        {
            printf("%d:",x);
        }
        if(y<10)
        {
            printf("0%d",y);
        }
        else
        {
            printf("%d",y);
        }
        printf("\n");

    }
    return 0;
}
