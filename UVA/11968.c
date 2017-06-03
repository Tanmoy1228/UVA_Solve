#include<stdio.h>
int main()
{
    int t=1,T;
    scanf("%d",&T);
    while(t<=T)
    {
        long long int n,m,k,a[10000],i,j,x=0,d=0,g,h;
        double y,e;
        scanf("%lld %lld %lld",&n,&m,&k);
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(i=0;i<m;i++)
        {
            x=x+a[i];
        }
        y=(x*1.0)/(m*1.0);
        for(j=i;j<i+k;j++)
        {
            d=d+a[j];
        }
        e=(d*1.0)/(k*1.0);
        g=y;
        h=e;
        if(y!=g)
        {
            g=g+1;
        }
        if(e!=h)
        {
            h=h+1;
        }
        printf("Case #%d: %lld %lld\n",t,g,h);
        t++;
    }
    return 0;
}
