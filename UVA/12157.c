#include<stdio.h>
int main()
{
    int t=1,T;
    scanf("%d",&T);
    while(t<=T)
    {
        long long int n,a[100000],i,j,m=0,c=0;
        scanf("%lld",&n);
        for(i=0;i<n;i++)
        {
            scanf("%lld",&a[i]);
        }
        for(i=0;i<n;i++)
        {
            for(j=1;;j++)
            {
                if(a[i]<j*30)
                {
                    m=m+(10*j);
                    break;
                }
            }
        }
        for(i=0;i<n;i++)
        {
            for(j=1;;j++)
            {
                if(a[i]<j*60)
                {
                    c=c+(15*j);
                    break;
                }
            }
        }
        if(m<c)
        {
            printf("Case %d: Mile %lld\n",t,m);
        }
        else if(m>c)
        {
            printf("Case %d: Juice %lld\n",t,c);
        }
        else if(m==c)
        {
            printf("Case %d: Mile Juice %lld\n",t,c);
        }
        t++;
    }
    return 0;
}
