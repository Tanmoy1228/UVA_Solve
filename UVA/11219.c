#include<stdio.h>
int main()
{
    int t=1,T;
    scanf("%d",&T);
    while(t<=T)
    {
        long long int d1,d2,m1,m2,y1,y2,d,m,y;
        scanf("%lld/%lld/%lld %lld/%lld/%lld",&d1,&m1,&y1,&d2,&m2,&y2);
        if(d1<d2)
        {
            d=d1-d2+30;
            m2=m2+1;
        }
        else
        {
            d=d1-d2;
        }
        if(m1<m2)
        {
            m=m1-m2+12;
            y2=y2+1;
        }
        else
        {
            m=m1-m2;
        }
        if(y1<y2)
        {
            printf("Case #%d: Invalid birth date\n",t);
        }
        else
        {
            y=y1-y2;
            if(y>130)
            {
                printf("Case #%d: Check birth date\n",t);
            }
            else
            {
                printf("Case #%d: %lld\n",t,y);
            }
        }
        t++;
    }
    return 0;
}
