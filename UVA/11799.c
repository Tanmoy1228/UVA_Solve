#include<stdio.h>
int main()
{
    int t=1,T;
    scanf("%d",&T);
    while(t<=T)
    {
        long long int n,m=0,i,a[10000];
        scanf("%lld",&n);
        for(i=0;i<n;i++)
        {
            scanf("%lld",&a[i]);
        }
        for(i=0;i<n;i++)
        {
            if(m<a[i])
            {
                m=a[i];
            }
        }
        printf("Case %d: %lld\n",t,m);
        t++;
    }
    return 0;
}
