#include<stdio.h>
int main()
{
    int t=1,T;
    scanf("%d",&T);
    while(t<=T)
    {
        long long int n,i,j,m=1,d,k=0,a[100000];
        scanf("%lld",&n);
        for(i=0;i<n;i++)
        {
            scanf("%lld",&a[i]);
            if(i==0)
            {
                continue;
            }
            else if(i>0)
            {
                if(a[i]-a[i-1]>m)
                {
                    m=a[i]-a[i-1];
                }
            }
        }
        d=m;
        for(i=0;i<n-1;i++)
        {
            if(a[i+1]-a[i]<m)
            {
                continue;
            }
            else if(a[i+1]-a[i]==m)
            {
                m=m-1;
            }
            else if(a[i+1]-a[i]>m)
            {
                k=1;
                break;
            }
        }
        if(k==0)
        {
            printf("Case %d: %lld\n",t,d);
        }
        else if(k==1)
        {
            printf("Case %d: %lld\n",t,d+1);
        }
        t++;
    }
    return 0;
}
