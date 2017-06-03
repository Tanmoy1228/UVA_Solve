#include<stdio.h>
int main()
{
    int t=1,T;
    scanf("%d",&T);
    while(t<=T)
    {
        long long int n,c;
        double v=0;
        scanf("%lld",&n);
        if(n<=180000)
        {
            printf("Case %d: 0\n",t);
            t++;
            continue;
        }
        if(n>180000)
        {
            n=n-180000;
        }
        if(n>300000)
        {
            v=v+300000.0*(10.0/100.0);
            n=n-300000;
        }
        else
        {
            v=v+n*1.0*(10.0/100.0);
            c=v;
            if(c<=2000)
            {
                printf("Case %d: 2000\n",t);
            }
            else
            {
                printf("Case %d: %lld\n",t,c);
            }
            t++;
            continue;
        }
        if(n>400000)
        {
            v=v+400000.0*(15.0/100.0);
            n=n-400000;
        }
        else
        {
            v=v+n*1.0*(15.0/100.0);
            c=v;
            printf("Case %d: %lld\n",t,c);
            t++;
            continue;
        }
        if(n>300000)
        {
            v=v+300000.0*(20.0/100.0);
            n=n-300000;
        }
        else
        {
            v=v+n*1.0*(20.0/100.0);
            c=v;
            printf("Case %d: %lld\n",t,c);
            t++;
            continue;
        }
        if(n>0)
        {
            v=v+n*1.0*(25.0/100.0);
            c=v;
            printf("Case %d: %lld\n",t,c);
            t++;
            continue;
        }
    }
    return 0;
}
