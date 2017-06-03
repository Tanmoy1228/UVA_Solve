#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        unsigned long long n,m,x,y;
        scanf("%llu %llu",&n,&m);
        if(n>=m)
        {
            x=(n+m);
            y=(n-m);
            if(x%2==0 && y%2==0)
            {
                printf("%llu %llu\n",x/2,y/2);
            }
            else
            {
                printf("impossible\n");
            }
        }
        else
        {
            printf("impossible\n");
        }
    }
    return 0;
}
